// to_tuple_string.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
#include "pch.h"

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <initializer_list>

using namespace std;

namespace ct {

    template <typename T>
    string to_string(const T& x)
    {
        ostringstream os;
        os << x;
        return os.str();
    }

#if 0
    template <typename First, typename ...Rest>
    string to_string(const First& f, const Rest& ...r)
    {
        return to_string(f) + ", " + to_string(r...); 
    }

    // Benoetigt Hilfsfunktion und Indirektion
    template <typename ...Args>
    string to_tuple_string(const Args& ...a)
    {
        return "(" + to_string(a...) + ")";

    }

    template <typename ...Args>
    void dummy(Args& ...) {}

    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
        ostringstream os;
        os << "(" << f;
        // dummy((os << ", " << r)...); // Ausgabe richtige Reihenfolge mit clang++, sonst Reihenfolge falsch
        initializer_list<int> dummy [[maybe_unused]] = { (os << ", " << r, 0)... };
        os << ")";
        return os.str();
    }

    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
        return "(" + (to_string(f) + ... + (", " + to_string(r)) ) + ")";
    }
#endif

    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
        ostringstream os;
        ((os << "(" << f), ..., (os << ", " << r));
        // (os << ", " << r) , (os << ", " << r/1/) , (os << ", " << r/2/), ...
        os << ")";
        return os.str();
    }


    void f(int i, int j)
    {
        cout << "i = " << i << ", j = " << j << endl;
    }
}


int main()
{
    int i = 0;
    ct::f(++i, ++i); 

    cout << ct::to_tuple_string(3) << endl;
    cout << ct::to_tuple_string(3, 3.7) << endl;
    cout << ct::to_tuple_string(3, 3.7, "huhu") << endl;

    //assert(ct::to_tuple_string(3) == "(3)");
    //assert(ct::to_tuple_string(3, 3.7) == "(3, 3.7)");
    //assert(ct::to_tuple_string(3, 3.7, "huhu"s) == "(3, 3.7, huhu)");

    return 0;
}

