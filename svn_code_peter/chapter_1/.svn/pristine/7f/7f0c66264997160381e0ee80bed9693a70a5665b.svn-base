#include <iostream>
#include <utility>
#include <string>
#include <functional>
#include <unordered_map>

using namespace std;

namespace mv {

    int add(int x, int y) { return x + y; }

    template <typename T>
    T mul(T x, T y)  { return x * y; }

    struct div
    {
	int operator()(int x, int y) const { return x / y; }
    };

    template <typename T>
    struct sub
    {
	T operator()(T x, T y) const { return x - y; }
    };

    struct power
    {
	template <typename T>
	T operator()(T x, T y) const
	{
	    T res{1};
	    for (T i{0}; i < y; ++i)
		res*= x;
	    return res;
	}
    };

    struct maxi
    {
	static int evals(int x, int y) { return x + y; }
	int eval(int x, int y) const { return x + y; }
    };
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    using ft= function<int(int, int)>;
    ft f= add;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= mul<int>;
    cout << "f(7, 3) = " << f(7, 3) << endl;    

    f= mv::div{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= sub<int>{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= power{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= [](int x, int y) { return x % y; };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= maxi::evals;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    // f= maxi::eval;

    maxi m;
    f= bind(&maxi::eval, m, placeholders::_1, placeholders::_2);
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= [m](int x, int y) { return m.eval(x, y); };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    unordered_map<string, ft> functions{{"plus", add}, {"minus", sub<int>{}},
					{"hoch", power{}},
			                {"modulo", [](int x, int y) { return x % y; }}};

    cout << "9 hoch 4 = " << functions["hoch"](9, 4) << endl;

    for (auto value : functions)
	cout << "7 " << value.first << " 4 = " << value.second(7, 4) << endl;

    for (auto [opname, op] : functions)
	cout << "7 " << opname << " 4 = " << op(7, 4) << endl;
    
    return 0;
}
  
 
