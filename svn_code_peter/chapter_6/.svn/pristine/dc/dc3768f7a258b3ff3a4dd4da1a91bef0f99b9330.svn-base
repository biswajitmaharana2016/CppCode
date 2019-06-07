// variadisches_Template.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <type_traits>

using namespace std;

namespace ct {

    int sum() { return 0; }

    template <typename T> T sum(T x) { return x; }

    // Template-Alias ab C++11
    // dieser ist wie common_type_t aus C++14
    template <typename ...Args>
    using ct = typename common_type<Args...>::type;

    template <typename First, typename ...Rest>
    // First // Mist
    // typename common_type<First, Rest...>::type // C++11
    // ct<First, Rest...>
    auto // ab C++14
    sum(First f, Rest ...r)
    {
        return f + sum(r...);
    }

    // Faltung ab C++17
    // wie sum: rechtsassoziativ, ohne Einheitselement
    template <typename ...Args>
    auto sumr(Args ...a)
    {
        return (a + ...);
    }

    // rechtsassoziativ, mit Einheitselement
    template <typename ...Args>
    auto sumr0(Args ...a)
    {
        return (a + ... + 0);
    }

    // linksassoziativ, ohne Einheitselement
    template <typename ...Args>
    auto suml(Args ...a)
    {
        return (... + a);
    }

    // linksassoziativ, mit Einheitselement
    template <typename ...Args>
    auto suml0(Args ...a)
    {
        return (0 + ... + a);
    }

}

int main()
{
    using namespace ct;

    cout << "sum(-7) = " << sum(-7) << endl;
    cout << "sum(-7, 3.7f) = " << sum(-7, 3.7f) << endl;
    cout << "sum(-7, 3.7f, 9u) = " << sum(-7, 3.7f, 9u) << endl;
    cout << "sum(-7, 3.7f, 9u, -2.6) = " << sum(-7, 3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -42.6) = " << sum(-7, 3.7f, 9u, -42.6) << endl;

    cout << "sumr(-7, 3.7f, 9u, -42.6) = " << sumr(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0(-7, 3.7f, 9u, -42.6) = " << sumr0(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0() = " << sumr0() << endl;
     
    cout << suml(1.0, -1.0, 1e-20) << endl;
    cout << sumr(1.0, -1.0, 1e-20) << endl;
}