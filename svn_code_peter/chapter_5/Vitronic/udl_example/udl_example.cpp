// udl_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <chrono>

using namespace std;

namespace vit {

    class length
    {
    public:
        explicit length(double l) : l{l} {}

        friend ostream& operator<<(ostream& os, length ll)
        {
            if (ll.l >= 1000.0)
                return os << ll.l / 1000.0 << "km";
            return os << ll.l << "m";
        }

        length operator+(length l2) const { return length{ l + l2.l }; }

        length operator-() const { return length{ -l }; }
    private:
        double l;
    };

    length operator"" _mm(long double v) { return length{ static_cast<double>(1e-3 * v) }; }
    length operator"" _m(long double v) { return length{ static_cast<double>(v) }; }
    length operator"" _km(long double v) { return length{ static_cast<double>(1000.0 * v) }; }
    length operator"" _mi(long double v) { return length{ static_cast<double>(1852.0 * v) }; }

    length operator"" _mm(unsigned long long v) { return length{ static_cast<double>(1e-3 * v) }; }
    length operator"" _m(unsigned long long v) { return length{ static_cast<double>(v) }; }
    length operator"" _km(unsigned long long v) { return length{ static_cast<double>(1000.0 * v) }; }
    length operator"" _mi(unsigned long long v) { return length{ static_cast<double>(1852.0 * v) }; }
}

int main(int argc, char** argv)
{
    // using namespace vit;
    using vit::length;
    using vit::operator""_m;
    using vit::operator""_km;
    using vit::operator""_mi;

    length l1{ 13.5 };
    cout << "Die 1. Laenge ist " << l1 << endl;

    auto l2 = 3.1_mi;
    cout << "Die 2. Laenge ist " << l2 << endl;

    cout << "5 Meilen + 3.2km + 700m = " << 5.0_mi + 3.2_km + 700.0_m << endl;
    cout << "5 Meilen + 3.2km + 700m = " << 5_mi + 3.2_km + 700_m << endl;
    cout << "5 Meilen + -3.2km + 700m = " << 5_mi + -3.2_km + 700_m << endl;

    cout << typeid("Haha").name() << endl;
    cout << typeid(string{ "Haha" }).name() << endl;
    cout << typeid("Haha"s).name() << endl;

    chrono::milliseconds t1(300);
    auto t2 = 300ms;

    cout << typeid(t2).name() << endl;
    cout << typeid(300.0ms).name() << endl;
    cout << typeid(300.0h).name() << endl;
}

