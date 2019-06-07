#include <map>
#include <any>
#include <iostream>
#include <functional>

using namespace std;

class Observer {

    private:

        static map<string, any> listeners;

    public:

        template <typename ReturnValue, typename ...Args>
        static void registerListener(const string& name, const function<ReturnValue(Args...)>& handler) {
            listeners[name] = handler;
        }

        template <typename ReturnValue, typename ...Args>
        static ReturnValue fireEvent(const string& name, Args ...args) {
            auto result = listeners.find(name);
            if(result != listeners.end()) {
                auto handler = any_cast<function<ReturnValue(Args...)>>(result->second);
                return handler(args...);
            }
            else {
                return 0;
            }
        }
};

map<string, any> Observer::listeners;

#define EVENT_A_SIGNATURE int, int, float

int main(int argc, char** argv) {
    function<int(int, float)> handler = [](int i, float f)->int {
        cout << "int " << i << ", float " << f << endl;

        return -i;
    };

    Observer::registerListener("test", handler);

    auto result = Observer::fireEvent<int>("test", 23, 42.23f);

    cout << "result is " << result << endl;

    return 0;
}

