// abhaengige_Typen.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>

using namespace std;

namespace vit {

    template <typename T>
    struct base
    {
        using value_type = T;
        T f(T i) { return i + k; }
        T k{ 11 };
    };

    template <typename T>
    struct derived_int : base<int>
    {
        T g(T i)
        {
            value_type j = i + 2;
            j += k;
            return f(i * j);
        }
    };


    template <typename T>
    struct derived : base<T>
    {
        T g(T i)
        {
            typename base<T>::value_type j = i + 2;
            base<int>::value_type j2{ j };
            //j += base<T>::k;
            //return base<T>::f(i * j);
            j += this->k;
            return this->f(i * j);
        }
    };

    // Wer das schreibt, gehoert gefeuert!
    template <>
    struct base<short>
    {
        using f = double;
        using k = short;
        double value_type(int, double, long l) { return l; }
    };
}

int main(int argc, char** argv)
{
    using namespace vit;

    derived<int> d1;
    cout << d1.g(4) << endl;

    derived_int<long> d2;
    cout << d2.g(4) << endl;

    derived<short> d3;
    // cout << d3.g(4) << endl;

    long long l = 345'353'515'156, b= 0b1000111001010101010100101010100110010;
}
