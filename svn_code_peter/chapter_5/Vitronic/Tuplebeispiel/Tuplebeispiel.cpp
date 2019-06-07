// Tuplebeispiel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <tuple>

using namespace std;

namespace vit {

    //typedef tuple<int, double, string> triple;
    //typedef int array[12];
    //typedef int (*binfun)(int, int);

    using triple = tuple<int, double, string>;
    using array = int[12];
    using binfun = int(*)(int, int);


    triple f() {
        return triple(4, 9.2, "Dings");
    }

    

    //template <size_t N, typename Tuple>
    //typename tuple_element<N, Tuple>::type get(Tuple& t) { return  ;  }
}

int main(int argc, char** argv)
{
    using namespace vit;

    auto t1 = f();
    auto t10 = get<0>(t1);
    cout << "Das int-Ergebnis ist " << t10 << ".\n";
    get<0>(t1) = 666;

    cout << "Das int-Ergebnis ist " << get<int>(t1) << ".\n";

    int    i2;
    double d2;
    string s2;
    tie(i2, d2, s2) = f();
    cout << "Das int-Ergebnis ist " << i2 << ".\n";
}