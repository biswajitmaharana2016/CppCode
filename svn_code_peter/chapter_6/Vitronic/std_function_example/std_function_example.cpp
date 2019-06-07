// std_function_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <functional>
#include <map>
#include <string>

using namespace std;
using namespace std::placeholders;

namespace ct {

    int add(int x, int y) { return x + y; }

    template <typename T>
    T mul(T x, T y) { return x * y; }

    struct minus
    {
        int operator()(int x, int y) const { return x + y; }
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
            T res{ 1 };
            for (T i = 0; i < y; ++i)
                res *= x;
            return res;
        }
    };

    struct mini
    {
        int g(int x, int y) const { return x < y ? x : y; }
        static int h(int x, int y) { return x < y ? x : y; }
    };
}

int main()
{
    using namespace ct;

    using bin_fun = function<int(int, int)>;

    bin_fun f = add;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f = mul<int>;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f = ct::minus{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f = ct::div<int>{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f = power{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f = mini::h;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    // f = mini::g;
    mini m;
    f = bind(&mini::g, mini{}, _1, _2);
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f = [](int x, int y) { return x % y; };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= [m](int x, int y) { return m.g(x, y); };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    map<string, bin_fun> func{ {"plus", add}, {"hoch", power{}}, {"modulo", [](int x, int y) { return x % y; }} };

    cout << "9 hoch 4 = " << func["hoch"](9, 4) << endl;

    for (auto[opname, op] : func)
        cout << "9 " << opname << " 4 = " << op(9, 4) << endl;


}

