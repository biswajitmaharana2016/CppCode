// type_traits_examples.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <typeinfo>

using namespace std;

namespace ct {

    // wie is_pointer aus C++11
    template <typename T>
    struct ist_zeiger_trait
    {
        static constexpr bool value = false;
    };

    template <typename T>
    struct ist_zeiger_trait<T*>
    {
        static constexpr bool value = true;
    };

    // wie is_pointer_v aus C++17
    template <typename T>
    constexpr bool ist_zeiger = ist_zeiger_trait<T>::value;

    template <typename T>
    void print_ist_zeiger1(T)
    {
        cout << typeid(T).name() << " ist " << (ist_zeiger<T> ? "" : "k") << "ein Zeiger.\n";
        // cout << typeid(T).name() << " ist " << (ist_zeiger_trait<T>::value ? "" : "k") << "ein Zeiger.\n";
    }

    template <typename T>
    void nur_zeiger1(T)
    {
        static_assert(ist_zeiger<T>, "Funktion nur fuer Zeiger erlaubt.");
        cout << typeid(T).name() << " ist ein Zeiger.\n";
    }

    template <bool Condition, typename T= void>
    struct enable_if
    {
        using type = T;
    };

    template <typename T>
    struct enable_if<false, T>
    {};

    template <typename T>
    typename enable_if<ist_zeiger<T>, void>::type nur_zeiger2(T)
    {
        cout << typeid(T).name() << " ist ein Zeiger.\n";
    }

    template <bool Condition, typename T = void>
    using enable_if_t = typename enable_if<Condition, T>::type;

    template <typename T>
    enable_if_t<ist_zeiger<T>> nur_zeiger3(T)
    {
        cout << typeid(T).name() << " ist ein Zeiger.\n";
    }

    template <typename T, typename = enable_if_t<ist_zeiger<T>> >
    void nur_zeiger4(T)
    {
        cout << typeid(T).name() << " ist ein Zeiger.\n";
    }

    template <typename T>
    enable_if_t<ist_zeiger<T>> print_value1(T x)
    {
        cout << "Der Wert ist " << *x << ". [Zeiger]\n";
    }

    template <typename T>
    enable_if_t<! ist_zeiger<T>> print_value1(T x)
    {
        cout << "Der Wert ist " << x << ". [kein Zeiger]\n";
    }

    template <bool Value>
    struct bool_constant
    {
        static constexpr bool value = Value;
    };

    using true_type = bool_constant<true>;
    using false_type = bool_constant<false>;

    template <typename T>
    void print_value2(T x, true_type)
    {
        cout << "Der Wert ist " << *x << ". [Zeiger]\n";
    }

    template <typename T>
    void print_value2(T x, false_type)
    {
        cout << "Der Wert ist " << x << ". [kein Zeiger]\n";
    }

    template <typename T>
    void print_value2(T x)
    {
        print_value2(x, bool_constant<ist_zeiger<T>>{});
    }

    template <typename T>
    void print_value3(T x)
    {
        if constexpr (ist_zeiger<T>)
            cout << "Der Wert ist " << *x << ". [Zeiger]\n";
        else
            cout << "Der Wert ist " << x << ". [kein Zeiger]\n";
    }
}

int main()
{
    using namespace ct;

    int i{ 3 };
    print_ist_zeiger1(3);
    print_ist_zeiger1(&i);

    nur_zeiger1(&i);
    // nur_zeiger(i);

    nur_zeiger2(&i);
    // nur_zeiger2(i);

    nur_zeiger3(&i);
    // nur_zeiger2(i);

    nur_zeiger4(&i);
    // nur_zeiger2(i);

    print_value1(i);
    print_value1(&i);

    print_value2(i);
    print_value2(&i);

    print_value3(i);
    print_value3(&i);
}

