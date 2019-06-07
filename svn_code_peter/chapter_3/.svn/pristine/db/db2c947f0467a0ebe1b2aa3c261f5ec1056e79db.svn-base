#include <iostream>
#include <functional>
#include <map>

using namespace std;
using namespace std::placeholders;

namespace le {

    int add(int x, int y) { return x + y; }

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
	T operator()(T x, T y) const {
	    T r{1};
	    for (T p{0}; p < y; ++p)
		r*= x;
	    return r;
	}
    };

    struct maxi
    {
	static int seval(int x, int y) { return x > y ? x : y; }
	int eval(int x, int y) const { return x > y ? x : y; }
    };
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    using bf= std::function<int(int, int)>;
    bf f= add;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= mul<int>;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= le::minus{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= le::div<int>{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= power{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= [](int x, int y){ return x % y; };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= maxi::seval;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    // f= maxi::eval;
    maxi m;
    f= bind(&maxi::eval, m, _1, _2);
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= [](int x, int y){ maxi m; return m.eval(x, y); };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    map<string, bf> ops{{"plus", add}, {"by", le::div<int>{}}, {"modulo", [](int x, int y){ return x % y; }}};

    cout << "9 modulo 4 = " << ops["modulo"](9, 4) << endl;
    for (auto [opname, op] : ops)
	cout << "9 " << opname << " 4 = " << op(9, 4) << endl;
    
    return 0;
}
  
 
