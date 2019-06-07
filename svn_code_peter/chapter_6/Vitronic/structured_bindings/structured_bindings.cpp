// structured_bindings.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

//#include "pch.h"
#include <iostream>
#include <typeinfo>
#include <tuple>
#include <string>
#include <unordered_map>

using namespace std;

namespace ct {

    struct altlasten
    {
        int i;
        double d;
    };
    altlasten fun()
    {
        return {1,2.5};
    }
    auto create() {
        return tuple<int, float, string>{ 3, 4.2f, "Hallo" };
    }
}

int main()
{
    using namespace ct;

    tuple t0{ 3, 4.2f, "Hallo"s };
    auto [ i, fl] = altlasten();
    cout << "i= " << i << "fl :" << fl<< endl;

    altlasten a1{ 3, 3.9 }, a2{ 4 };
    cout << "a2.d = " << a2.d << endl;

    auto[i2, d2] = a2;
    cout << "i2 ist ein " << typeid(i2).name() << " mit dem Wert " << i2 << endl;

    auto t1 = create();
    auto t1i = get<0>(t1);
    cout << "Index 0 von t1 ist " << t1i << endl;
    get<0>(t1) = 666;
    cout << "Index 0 von t1 ist " << get<0>(t1) << endl;

    cout << "Der float in t1 ist " << get<float>(t1) << endl;

    int i3;
    float f3;
    string s3;
    tie(i3, f3, s3) = create();

    cout << "Tie :" << i3 << "f3" << f3 <<endl;

    auto [t10, t11, t12] = create();

    unordered_map<string, unsigned> tel{ {"Chris", 7064}, {"Thomas", 240}, {"Lars", 384} };

    for (pair<const string, unsigned> entry : tel)
        cout << entry.first << "' Nummer ist " << entry.second << ".\n";

    for (auto [name, nr] : tel)
        cout << name << "' Nummer ist " << nr << ".\n";
}

