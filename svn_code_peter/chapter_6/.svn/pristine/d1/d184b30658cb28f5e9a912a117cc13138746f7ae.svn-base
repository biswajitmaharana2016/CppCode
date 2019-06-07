// uniform_init.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

namespace ct {

    struct leer {};

    template <typename T>
    void f(T)
    {
        T e1; // Default-Ktor, fund. Typen nicht initialisiert
        // T e2(); // Funktionsdeklaration
        T e3{}; // Default-Ktor, fund. Typen init. (0, 0.0, nullptr)
    }

    struct complex
    {
        complex(double rn, double in) : r{ rn }, i{ in } {}
        double r, i;
    };
}

int main()
{
    using namespace ct;

    int i1 = 3.6;
    int i2(3.7);
    // int i3{ 3.8 };
    // int i4 = { 3.9 };

    int i5{ 7 };
    unsigned int u1{ 9 };

    // int i6{ u1 };
    // unsigned int u2{ i5 };

    // static_assert(sizeof(long) > sizeof(unsigned int), "long zu kurz.");
    // long l1{ u1 };

    static_assert(sizeof(long long) > sizeof(unsigned int), "long long zu kurz.");
    long long ll1{ u1 };

    leer e1;
    // leer e2(); // Funktionsdeklaration
    leer e3{};

    ct::complex c1{ 3.4, 5.2 };
    long double ld1{ 4.9 };
    // ct::complex c2{ ld1, ld1 };
}

