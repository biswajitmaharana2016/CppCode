// lambda_loesung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace ct {

    template <typename Container>
    auto find_first_multiple(const Container& v, int i)
    {
        return find_if(begin(v), end(v), [i](int x) { return x % i == 0; });
    }

    template <typename Value, size_t Size>
    Value* end(Value(&array)[Size])
    {
        return array + Size; 
    }

    template <typename Container>
    auto end(Container& c) -> decltype(c.end())
    {
        return c.end();
    }
}

int main()
{
    // using namespace ct;

    // vector<int> vi{ 3, 5, 4, 12, 15, 7, 9 };
    int vi[]= {3, 5, 4, 12, 15, 7, 9};
    for (int i = 2; i < 10; ++i) {
        auto it = ct::find_first_multiple(vi, i);
        if (it != end(vi))
            cout << "The first multiple of " << i << " is " << *it << endl;
        else
            cout << "There is no multiple of " << i << endl;
    }

    return 0;
}


