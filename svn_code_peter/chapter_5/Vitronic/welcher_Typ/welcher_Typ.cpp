// welcher_Typ.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace std;

template <typename T> struct wrap {};

template <typename T>
void cp(T x)
{
    cout << "T = " << typeid(wrap<T>).name() << ", x = " << typeid(wrap<decltype(x)>).name() << endl;
}

template <typename T>
void cr(const T& x)
{
    cout << "T = " << typeid(wrap<T>).name() << ", x = " << typeid(wrap<decltype(x)>).name() << endl;
}

template <typename T>
void mr(T& x)
{
    cout << "T = " << typeid(wrap<T>).name() << ", x = " << typeid(wrap<decltype(x)>).name() << endl;
}

template <typename T>
void fr(T&& x)
{
    cout << "T = " << typeid(wrap<T>).name() << ", x = " << typeid(wrap<decltype(x)>).name() << endl;
}

template <typename T>
void gib_weiter(T&& x)
{
    // fr(x); // immer lvalue
    // fr(move(x)); // immer rvalue
    fr(forward<T>(x));
}

void rvalue_only(int&&) {}

template <typename T>
void rvalue_only(wrap<T>&&) {}

template <typename T>
void rvalue_only1(T&&) { cout << "Ein rvalue.\n"; }

template <typename T>
void rvalue_only1(T&) = delete;

// Template-Variablen ab C++14
// Diese wie is_rvalue_reference_v in C++17
template <typename T>
constexpr bool is_rvalue_ref = is_rvalue_reference<T>::value;

template <typename T>
void rvalue_only2(T&& x) 
{ 
    // static_assert(is_rvalue_reference<decltype(x)>::value, "Nur rvalues!!!");
    static_assert(is_rvalue_ref<decltype(x)>, "Nur rvalues!!!");
    cout << "Ein rvalue.\n";
}

int main(int argc, char** argv)
{
    int        i{ 8 };
    int&       r{ i };
    const int& c{ i };

    rvalue_only1(3);
    // rvalue_only1(i);

    rvalue_only2(3);
    // rvalue_only2(i);

    cp(3);
    cp(i);
    cp(r);
    cp(c);
    cout << endl;

    cr(3);
    cr(i);
    cr(r);
    cr(c);
    cout << endl;

    // mr(3);
    mr(i);
    //mr<int&>(i);
    //mr<int&&>(i);
    mr(r);
    mr(c);
    cout << endl;

    fr(3);
    // fr<int&&>(3);
    fr(i);
    fr(r);
    fr(c);
    cout << endl;

    gib_weiter(3);
    gib_weiter(i);
    gib_weiter(r);
    gib_weiter(c);
    cout << endl;
}

