#include "pch.h"
#include <iostream>
#include <cstdint>

using namespace std;

namespace vit {

    struct empty {};

    struct trans_language
    {
#ifdef __cplusplus
        trans_language(int i, int j) : i{ i }, j{ j } {}
#endif // __cplusplus

        int i, j;
    };

    template <typename T>
    void f(T)
    {
        T empty1;   // Default-Konstruktor, intr. Typen nicht initialisiert
        T empty2(); // Funktionsdeklaration
        T empty3{}; // Default-Konstruktor, intr. Typen initilisiert (0, 0.0, nullptr)
    }

    struct olles_c_zeug
    {
        int i;
        double d;
    };
}

int main(int argc, char** argv)
{
    using namespace vit;

    //int i1 = 3.7;     // Warnung in VS und clang++, nichts in g++
    //int i2(3.8);      // dito
    //int i3{ 3.9 };    // Fehler nach Standard: Verengung
    //int i4 = { 4.1 }; // dito

    const int i4{ 3 };
    unsigned u1{ 8 };

    // unsigned u2{ i4 };
    // int      i5{ u1 };

    cout << "sizeof(int) = " << sizeof(int) << ", sizeof(long) = " << sizeof(long) << endl;

    // static_assert(sizeof(long) > sizeof(unsigned), "long muss laenger sein als unsigned.");
    // long l1{ u1 };      // plattformabh., long muss laenger sein als unsigned

    static_assert(sizeof(long long) > sizeof(unsigned), "long long muss laenger sein als unsigned.");
    long long ll1{ u1 };      // plattformabh., long muss laenger sein als unsigned
    long l2{ static_cast<long>(u1) };

    // int i6{ 12345678901 }; // zu gross fuer 32 Bit

    int64_t i64{ u1 };

    trans_language t1{ 3, 5 };

    vit::empty e1;   // Default-Konstruktor
    vit::empty e2(); // Funktionsdeklaration, Most Vexing Parse
    vit::empty e3{}; // Default-Konstruktor

    olles_c_zeug o1{ 3, 6.1 }; // direkte Initialisierung der Member, wenn kein Konstruktor existiert
}

