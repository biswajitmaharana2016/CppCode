// abhaengige_Typen.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
#include "pch.h"
#include <iostream>

using namespace std;

namespace ct {

    template <typename T>
    struct base
    {
        using value_type = T;
        T f(T i) { return k + i; }
        T k{ 8 };
    };

    // Wer so etwas schreibt, gehoert gefeuert
    template <>
    struct base<short>
    {
        int value_type = 9;
        using f = short;
        short k() { return 3; }
    };

    template <typename T>
    struct derived : base<T>
    {
        T g(T i)
        {
            typename base<T>::value_type j = i + 3;
            j += this->k;
            return this->f(j * 2);
            //j += base<T>::k;
            //return base<T>::f(j * 2);
        }
    };


    template <typename T>
    struct derived_int : base<int>
    {
        T g(T i)
        {
            value_type j = i + 3;
            j += k;
            return f(j * 2);
        }
    };
}

int main()
{
    using namespace ct;

    derived_int<int> d1;
    cout << d1.g(4) << endl;

    derived<int> d2;
    cout << d2.g(4) << endl;

    derived<short> d3;
    // cout << d3.g(4) << endl;

    typename derived<long>::value_type l{ 4 };
}

