// fibonacci.cpp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>


using namespace std;

namespace ct {

    template <size_t N>
    struct fibonacci
    {
        static const size_t value = fibonacci<N - 1>::value + fibonacci<N - 2>::value;
    };

    template <>
    struct fibonacci<1>
    {
        static const size_t value = 1;
    };

    template <>
    struct fibonacci<2>
      : fibonacci<1> {};

    constexpr size_t fibo(size_t n)
    {
        return n < 2 ? n : fibo(n - 1) + fibo(n - 2);
    }
}

int main(int argc, char** argv)
{
    using namespace ct;

    cout << "Die 17. Fibonacci-Zahl ist " << fibonacci<17>::value << endl;
    cout << "Die 18. Fibonaccizahl ist " << fibo(18) << endl;
 
    fibonacci<fibo(4)> ff4;

    size_t n = 5;
    if (argc > 1)
        n = stoul(argv[1]);
    const size_t k = n;

    cout << "Die " << n << ". Fibonacci-Zahl ist " << fibo(n) << endl;

    // constexpr size_t f9 = fibo(k); // nur wenn k zur Compile-Zeit bekannt ist
    constexpr size_t f9 = fibo(9);
    cout << "Die 9. Fibonacci-Zahl ist " << f9 << endl;


}