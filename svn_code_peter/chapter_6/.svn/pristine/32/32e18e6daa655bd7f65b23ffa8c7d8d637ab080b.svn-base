// auto_examples.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

namespace ct {

    int& fref() { static int i{ 4 }; return i; }
    const int& cref() { static int i{ 4 }; return i; }

    template <typename Container>
    void print_all_98(const Container& c)
    {
        for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
            cout << *it << endl;
        }
    }

    template <typename Container>
    void print_all_11(const Container& c)
    {
        for (auto it = begin(c); it != end(c); ++it) {
            auto&& value = *it;
            cout << value << endl;
        }
    }

    template <typename Container>
    void print_all_for(const Container& c)
    {
        for (auto&& value : c)
            cout << value << endl;
    }

    template <typename Value, size_t N>
    Value* end(Value(&ar)[N])
    {
        return ar + N;
    }

    template <typename Container>
    auto end(Container& c) -> decltype(c.end())
    {
        return c.end();
    }
    
    // C++14
    template <typename Container>
    auto first_entry_copy(Container& c)
    {
        return *begin(c);
    }

    template <typename Container>
    decltype(auto) first_entry_directly(Container& c)
    {
        return *begin(c);
    }
}

int main()
{
    using namespace ct;

    // auto a0;
    auto a1 = -9 + 3.7f + 7u - 2.6;  // double

    auto a2 = fref();         // int
    auto& a3 = fref();        // int&
    const auto& a4 = fref();  // const int&

    auto a5 = cref();         // int
    auto& a6 = cref();        // const int& (auto durch const int substituiert)

    auto&& drei = 3;          // int&&
    drei = 4;
    cout << "drei = " << drei << endl;

    auto&& a7 = fref();       // int&
    auto&& a8 = cref();       // const int&

    decltype(cref()) a9 = cref(); // const int&
    decltype(auto) a10 = cref();  // Typ wie decltype, verwendet auto
}

