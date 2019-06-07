// ptask_is_thread.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

namespace ct {

    struct trivial {};

    bool is_prime(size_t i)
    {
        if (i % 10 == 5 && i != 5)
            throw trivial{};
        if (i == 1)
            return false;
        if (i % 2 == 0)
            return i == 2;
        size_t max_check = i;
        for (size_t j = 3; j < max_check; j += 2)
            if (i % j == 0)
                return false;
        return true;
    }

    template <typename T> class ptask;

    template <typename Ret, typename ...Args>
    class ptask<Ret(Args...)>
    {
        using ftype = function<Ret(Args...)>;
    public:
        ptask(ftype f) : f{f} {}

        template <typename ...A2>
        void operator()(A2&& ...a) const
        {
            try {
                p.set_value_at_thread_exit(f(forward<A2>(a)...));
            }
            catch (...) {
                p.set_exception_at_thread_exit(current_exception());
            }
        }

        future<Ret> get_future() { return p.get_future(); }

    private:
        ftype f;
        mutable promise<Ret> p;
    };



}

int main(int argc, char** argv)
{
    using namespace ct;

    int num_threads = 2;
    if (argc > 1)
        num_threads = stoi(argv[1]);

    vector<size_t> vi;
    size_t tv = 982'451'653;
    for (int i = 0; i < num_threads; ++i, tv += 2)
        vi.push_back(tv);

    vector<future<bool>> futures;
    for (int i = 0; i < num_threads; ++i) {
        ptask<bool(size_t)> pt{ is_prime };
        futures.push_back( pt.get_future() );
        thread{ move(pt), vi[i] }.detach();
    }
    cout << "Alles gestartet" << endl;

    for (int i = 0; i < num_threads; ++i) {
        while (futures[i].wait_for(200ms) != future_status::ready)
            cout << "Das dauert!!!" << endl;
        try {
            bool it_is = futures[i].get();
            cout << vi[i] << " ist " << (it_is ? "eine" : "keine") << " Primzahl.\n";
        }
        catch (trivial) {
            cout << vi[i] << " ist offensichtlich keine Primzahl.\n";
        }
    }


}