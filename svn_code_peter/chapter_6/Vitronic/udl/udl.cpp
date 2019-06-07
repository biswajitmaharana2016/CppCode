// udl.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <typeinfo>
#include <complex>
#include <string>
#include <string_view>

using namespace std;

namespace ct {

    class length
    {
    public:
        explicit length(double lv) : lv{ lv } {}

        friend ostream& operator<<(ostream& os, length l)
        {
            return os << l.lv << "m";
        }

        length operator+(length that) const { return length{ lv + that.lv }; }
        length operator-() const { return length{ -lv }; }

    private:
        double lv;
    };

    length operator""_m(long double v) { return length(v); }
    length operator""_km(long double v) { return length(1000.0 * v); }
    length operator""_nmi(long double v) { return length(1852.0 * v); }
    length operator""_nmi(unsigned long long v) { return length(1852.0 * v); }
}

int main()
{
    // using namespace ct;
    using ct::length;
    using ct::operator""_m;
    using ct::operator""_km;
    using ct::operator""_nmi;

    length l1{ 3.4 };
    cout << "l1 = " << l1 << endl;

    auto l2 = 5.4_m;
    auto l3 = 2.3_km;
    auto l4 = 4.1_nmi;

    cout << "l4 = " << l4 << endl;

    cout << "3.2 Seemeilen + 4.2 Kilometer = " << 3.2_nmi + 4.2_km << endl;
    cout << "-3.2 Seemeilen + 4.2 Kilometer = " << -3.2_nmi + 4.2_km << endl;
    cout << "3 Seemeilen + 4.2 Kilometer = " << 3_nmi + 4.2_km << endl;

    cout << "Typ von Stunde " << typeid(1h).name() << endl;
    cout << "Typ von Stunde " << typeid(1.0h).name() << endl;
    cout << "Typ von Nanosekunde " << typeid(1ns).name() << endl;

    complex<long double> c{ 3.2, 1.4 };
    cout << c * 2.0il << endl;
    
 
}

