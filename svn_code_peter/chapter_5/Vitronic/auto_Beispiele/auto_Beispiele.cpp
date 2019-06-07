// auto_Beispiele.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <tuple>
#include <string>
#include <unordered_map>

using namespace std;

namespace vit {

    int& fref() { static int i{ 3 }; return i; }
    const int& cref() { static int i{ 3 }; return i; }

    template <typename Container>
    void print_all98(const Container& c)
    {
        for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
            cout << *it << endl;
    }

    template <typename Container>
    void print_all11(const Container& c)
    {
        for (auto it = begin(c); it != end(c); ++it)
            cout << *it << endl;
    }

    template <typename Container>
    void print_all_auto(const Container& c)
    {
        // for (auto v : c) // kopiere in v
        for (auto&& v : c) // rvalue- oder lvalue-Referenz
            cout << v << endl;
    }

    // ab C++14: return-Typ automatisch

    // immer Kopie
    template <typename Container>
    auto first_entry_copy(Container& c)
    {
        return *begin(c);
    }

    // gib Wert zurueck, wie er ist
    template <typename Container>
    decltype(auto) first_entry_as_is(Container& c)
    {
        return *begin(c);
    }

}

int main(int argc, char** argv)
{
    using namespace vit;

    // auto a0;
    auto a1 = -7 + 3.7f + 9u - 2.6; // double

    auto a2 = fref();               // int
    auto& a3 = fref();              // int&
    const auto& a4 = fref();        // const int&

    auto a5 = cref();               // int
    auto& a6 = cref();              // const int& (auto -> const int)

    auto&& neun = 9;                // int&&
    neun = 4;
    cout << "neun = " << neun << endl;

    auto&& a7 = fref();             // int&
    auto&& a8 = cref();             // const int&

    decltype(cref()) a9 = cref();   // const int&
    decltype(auto) a10 = cref();    // Typ wie decltype, verwendet wie auto

    tuple<int, double, string> t1{ 3, 9.2, "haha"s };
    tuple t2{ 3, 9.2, "haha"s };

    auto[t21, t22, t23] = t2;

    unordered_map<string, int> telefon{ {"Galina", 7167}, {"Robert", 4711}, {"Daniel", 7404} };
    for (auto [name, nummer] : telefon)
        cout << name << "s Nummer ist " << nummer << ".\n";

}

