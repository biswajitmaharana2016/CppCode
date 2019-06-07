// Variadische_Funktion.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <type_traits>

using namespace std;

namespace vit {

    int sum() { return 0; }

    // template <typename T> T sum(T x) { return x; }

    // Template-Alias, gibt's seit C++11
    // Dieses Alias ist wie common_type_t aus C++14
    template <typename ...Args>
    using ct = typename common_type<Args...>::type;

    template <typename First, typename ...Rest>
    // First 
    // typename common_type<First, Rest...>::type
    // ct<First, Rest...>
    auto // C++14
    sum(First f, Rest ...r)
    {
        return f + sum(r...);
    }

    // C++17: Faltung

    // wie sum: rechtsassoziativ (von rechts nach links rechnen), ohne Einheitselement
    template <typename ...Args>
    auto sumr(Args ...a)
    {
        return (a + ...);
        // return -7 + (3.7f + (9u + -42.4));
    }

    // rechtsassoziativ mit Einheitselement
    template <typename ...Args>
    auto sumr0(Args ...a)
    {
        cout << " [ mit " << sizeof...(Args) << " Argumenten ] ";
        return (a + ... + 0);
        // return -7 + (3.7f + (9u + (-42.4 + 0)));
    }

    // linksassoziativ (von links nach rechts rechnen), ohne Einheitselement
    template <typename ...Args>
    auto suml(Args ...a)
    {
        return (... + a);
        // return ((-7 + 3.7f) + 9u) + -42.4;
    }

    // linksassoziativ (von links nach rechts rechnen), ohne Einheitselement
    template <typename ...Args>
    auto suml0(Args ...a)
    {
         return (0 + ... + a);
        // return (((0 + -7) + 3.7f) + 9u) + -42.4;
    }

}

int main(int argc, char** argv)
{
    using namespace vit;

    cout << "sum(-7, 3.7f) = " << sum(-7, 3.7f) << endl;
    cout << "sum(-7, 3.7f, 9u) = " << sum(-7, 3.7f, 9u) << endl;
    cout << "sum(-7, 3.7f, 9u, -2.4) = " << sum(-7, 3.7f, 9u, -2.4) << endl;
    cout << "sum(-7, 3.7f, 9u, -42.4) = " << sum(-7, 3.7f, 9u, -42.4) << endl;

    cout << "sumr(-7, 3.7f, 9u, -42.4) = " << sumr(-7, 3.7f, 9u, -42.4) << endl;
    cout << "sumr0(-7, 3.7f, 9u, -42.4) = " << sumr0(-7, 3.7f, 9u, -42.4) << endl;
    cout << "sumr0() = " << sumr0() << endl;

    cout << "suml(-7, 3.7f, 9u, -42.4) = " << suml(-7, 3.7f, 9u, -42.4) << endl;

    cout << "sumr(1.0, -1.0, 1e-20) = " << sumr(1.0, -1.0, 1e-20) << endl;
    cout << "suml(1.0, -1.0, 1e-20) = " << suml(1.0, -1.0, 1e-20) << endl;

}

