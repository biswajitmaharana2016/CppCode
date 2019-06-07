// welcher_Typ.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <memory>

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
void pass_on(T&& x)
{
    // fr(x); // immer lvalue
    // fr(move(x)); // immer rvalue
    fr(forward<T>(x));
}

template <typename Target, typename ...Args>
unique_ptr<Target> make_unique(Args&& ...a)
{
    return unique_ptr<Target>{ new Target{ forward<Args>(a)... } };
}

template <typename T>
void rvalue_only(wrap<T>&&) { cout << "nur rvalue\n"; }

template <typename T>
void rvalue_only_del(T&& x) { cout << "nur rvalue\n"; }

template <typename T>
void rvalue_only_del(T& x) = delete;

template <typename T>
void rvalue_only_check(T&& x) 
{ 
    static_assert(is_rvalue_reference<decltype(x)>::value, "Man, das ist ein lvalue.");
    cout << "nur rvalue\n"; 
}



int main()
{
    int        i{ 4 };
    int&       r{ i };
    const int& c{ i };

    cout << "cp(T)\n";
    cp(3);
    cp(i);
    cp(r);
    cp(c);
    cout << endl;

    cout << "cr(const T&)\n";
    cr(3);
    cr(i);
    cr(r);
    cr(c);
    cout << endl;

    cout << "mr(T&)\n";
    // mr(3);
    mr(i);
    mr<int&>(i);
    mr<int&&>(i);
    mr(r);
    mr(c);
    cout << endl;

    cout << "fr(T&&)\n";
    fr(3);
    // fr<int&&>(3);
    fr(i);
    fr(r);
    fr(c);
    cout << endl;

    cout << "pass_on(T&&)\n";
    pass_on(3);
    // pass_on<int&&>(3);
    pass_on(i);
    pass_on(r);
    pass_on(c);
    cout << endl;


}