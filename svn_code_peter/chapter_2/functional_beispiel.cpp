#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;

namespace sn {

    int add(int x, int y) { return x + y; }

    struct mul
    {
	int operator()(int x, int y) const { return x * y; }
    };

    template <typename T>
    T minus(T x, T y) { return x - y; }

    template <typename T>
    struct div
    {
	T operator()(T x, T y) const { return x / y; }
    };

    struct power
    {
    	template <typename T>
    	T operator()(T x, T y) const {
	    T res{1};
	    for (T i{0}; i < y; ++i)
		res*= x;
	    return res;
    	}
    };

    struct bin_and
    {
	static int f(int x, int y) { return x & y; }

	int g(int x, int y) const { return x & y; }
    };
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    using binfun= function<int(int, int)>;
    binfun f= add;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= mul{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= sn::minus<int>;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= sn::div<int>{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= power{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= bin_and::f;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    // f= &bin_and::g;
    f= bind(&bin_and::g, bin_and{}, placeholders::_1, placeholders::_2);
    cout << "f(7, 3) = " << f(7, 3) << endl;

    // f= [](int x, int y){ bin_and b; return b.f(x, y); };
    f= [](int x, int y){ return bin_and{}.f(x, y); };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= [](int x, int y){ return x % y; };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    // f= [](int x) { return x; }; // Fehler: falsche Signatur

    unordered_map<string, binfun> ff{{"plus", add}, {"minus", sn::minus<int>}, {"modulo", [](int x, int y){ return x % y; }}};

    cout << "9 modulo 4 = " << ff["modulo"](9, 4) << endl;

    for (auto [opname, op] : ff)
	cout << "9 " << opname << " 4 = " << op(9, 4) << endl;

    
    return 0;
}
  
 
