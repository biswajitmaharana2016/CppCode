#include <iostream>
#include <functional>
#include <map>

using namespace std;
using namespace std::placeholders;

namespace ct {

    inline int add(int x, int y) { return x + y; }

    template <typename T>
    T mul(T x, T y) { return x * y; }

    struct minus
    {
	int operator()(int x, int y) const { return x - y; }
    };

    template <typename T>
    struct div
    {
	T operator()(T x, T y) const { return x / y; }
    };

    struct power
    {
	template <typename T>
	T operator()(T x, T y) const
	{
	    T res{1};
	    for (T i= 0; i < y; ++i)
		res*= x;
	    return res;
	}
    };

    struct maxi
    {
	static int fs(int x, int y) { return x > y ? x : y; }

	int f(int x, int y) const { return x > y ? x : y; }
    };
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    using binfun= function<int(int, int)>;
    binfun f= add;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= mul<int>;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= ct::minus{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= ct::div<int>{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= power{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    power p;
    cout << "p(7, 3) = " << p(7, 3) << endl;
    cout << "p(7l, 3l) = " << p(7l, 3l) << endl;

    f= [](int x, int y){ return x % y; };
    cout << "f(7, 3) = " << f(7, 3) << endl;
    
    f= maxi::fs;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    // f= maxi::f;
    f= [](int x, int y){ maxi m; return m.f(x, y); };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    maxi m;
    f= bind(&maxi::f, m, _1, _2);
    cout << "f(7, 3) = " << f(7, 3) << endl;

    map<string, binfun> ops{{"plus", add}, {"mal", mul<int>},
			    {"modulo", [](int x, int y){ return x % y; }}};

    cout << "9 modulo 4 = " << ops["modulo"](9, 4) << endl;

    for (auto [opname, op] : ops)
	cout << "9 " << opname << " 4 = " << op(9, 4) << endl;
    
    return 0;
}
  
 
