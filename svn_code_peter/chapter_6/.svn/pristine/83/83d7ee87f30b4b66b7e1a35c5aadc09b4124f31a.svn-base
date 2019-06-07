// funktionstemplate.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>

using namespace std;

namespace ct {

    template <typename T, typename U>
    struct convert_trait
    {
        // typedef T result_type;
        using result_type = T;

        static T conv(U u)
        {
            return static_cast<T>(u);
        }
    };

    template <typename T, typename U>
    struct convert_trait<T, U*>
    {
        // typedef T result_type;
        using result_type = T;

        static T conv(U* u)
        {
            return static_cast<T>(u);
        }
    };

    template <typename T, typename U>
    typename convert_trait<T, U>::result_type convert(U u)
    {
        return convert_trait<T, U>::conv(u);
    }


    template <typename T>
    T maxi(T x, T y)
    {
        return x >= y ? x : y;
    }

    inline int maxi(int x, int y)
    {
        return x >= y ? x : y;
    }

    namespace {

        unsigned maxi(unsigned x, unsigned y)
        {
            return x >= y ? x : y;
        }
    }

    // Instanziierung
    template long maxi(long, long);

    // Spezialisierung, lieber nicht
    template <>
    short maxi<short>(short x, short y)
    {
        return x >= y ? x : y;
    }
}

int main()
{
    using namespace ct;

    cout << "maxi(3, 7) = " << maxi(3, 7) << endl;
    cout << "maxi(3.1, 7.1) = " << maxi(3.1, 7.1) << endl;
    cout << "maxi(3l, 7l) = " << maxi(3l, 7l) << endl;

    // cout << "maxi(3, 7.1) = " << maxi(3, 7.1) << endl;

    cout << "maxi(3, 7.1) = " << maxi((double)3, 7.1) << endl; // C-Cast, brutal
    cout << "maxi(3, 7.1) = " << maxi(double(3), 7.1) << endl; // Ktor fuer Klassen, fund. T. C-Cast
    cout << "maxi(3, 7.1) = " << maxi(static_cast<double>(3), 7.1) << endl; // sicherste Version, empfohlen

    cout << "maxi(3, 7.1) = " << maxi<long double>(3, 7.1) << endl;
}