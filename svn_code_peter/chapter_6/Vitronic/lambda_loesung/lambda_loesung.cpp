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
        return find_if(begin(v), end(v), [i](int x) {return x % i == 0; });
    }
}

int main()
{
    using namespace ct;

    vector<int> vi{ 3, 5, 4, 15, 7, 9, 12 };
    // int vi[]= {3, 5, 4, 15, 7, 9, 12};
    for (int i = 2; i < 10; ++i) {
        auto it = find_first_multiple(vi, i);
        if (it != end(vi))
            cout << "The first multiple of " << i << " is " << *it << endl;
        else
            cout << "There is no multiple of " << i << endl;
    }

    return 0;
}


