// constexpr_Beispiele.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

namespace ct {

    constexpr double square(double x) { return x * x; }

    template <typename T>
    constexpr T square(T x)
    {
        return x * x;
    }

    // C++14
    constexpr size_t popcount(size_t n)
    {
        size_t count = 0;
        for (; n != 0; ++count)
            n &= n - 1;
#if 0
        for (; n != 0; n >>= 1)
            if (n & 1)
                ++count;
#endif
        return count;
    }

    constexpr size_t popcount11(size_t n)
    {
        return n == 0 ? 0 : popcount11(n & n - 1) + 1;
    }

    constexpr bool is_prime(size_t i)
    {
        if (i == 1)
            return false;
        if (i % 2 == 0)
            return i == 2;
        // size_t max_check = ceil(sqrt(i));
        size_t max_check = i;
        for (size_t j = 3; j < max_check; j += 2)
            if (i % j == 0)
                return false;
        return true;
    }

}

int main()
{
    using namespace ct;

    constexpr auto sq37 = square(3.7);
    cout << "sq37 = " << sq37 << endl;

    constexpr float sq38 = square(3.8f);
    cout << "sq38 = " << sq38 << endl;

    cout << "popcount(0b1000'1000'0010'1001) = " << popcount(0b1000'1000'0010'1001) << endl;
    cout << "popcount11(0b1000'1000'0010'1001) = " << popcount11(0b1000'1000'0010'1001) << endl;

    // constexpr bool a_large_prime = is_prime(982'451'653);
    constexpr bool a_small_prime = is_prime(37);
}

