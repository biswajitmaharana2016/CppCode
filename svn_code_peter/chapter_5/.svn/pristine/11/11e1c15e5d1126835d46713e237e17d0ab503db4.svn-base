// Lambdabeispiele.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <complex>
#include <typeinfo>
#include <memory>

using namespace std;

namespace vit {

    struct dings
    {
        int f(int i) { return i + k; }
        int g(int i)
        {
            auto la= [i,this]() { return f(i + k); };
            return la();
        }
        int k{ 9 };
    };

    // C++14
    template <typename Container>
    void reverse_sort(Container& c)
    {
        sort(begin(c), end(c), [](auto x, auto y) { return x > y; });
        // In C++11
        //using vt = decltype(*begin(c));
        //sort(begin(c), end(c), [](vt x, vt y) { return x > y; });
    }

    auto scale_factory(int factor)
    {
        unique_ptr<int> up{ new int{factor} };
        // return [up](int i) { return *up * i; }; // kein Kopierkonstruktor
        // return [&up](int i) { return *up * i; };
        return [u = move(up)](int i){ return *u * i; }; 
    }
}

int main(int argc, char** argv)
{
    using namespace vit;

    using ci = complex<int>;
    vector<ci> w{ {4, 5}, {2, 8}, {1, 19} };
    sort(begin(w), end(w), [](ci x, ci y) { return real(x) < real(y); });
    copy(begin(w), end(w), ostream_iterator<ci>(cout, ", ")); cout << endl;

    sort(begin(w), end(w), [](ci x, ci y) { return imag(x) < imag(y); });
    copy(begin(w), end(w), ostream_iterator<ci>(cout, ", ")); cout << endl;

    vector<int> v{ 9, 2, 7, 4, 11, 3 }, x(6);
    // sort(begin(v), end(v), [](int x, int y) { return x > y; });
    reverse_sort(v);
    copy(begin(v), end(v), ostream_iterator<int>(cout, ", ")); cout << endl;

    int factor = 6;
    transform(begin(v), end(v), begin(x), [factor](int i) { return factor * i; });
    copy(begin(x), end(x), ostream_iterator<int>(cout, ", ")); cout << endl;

    auto scale_copy = [factor](int i) { return factor * i; };
    auto scale_ref = [&factor](int i) { return factor * i; };
    cout << "Typ von scale_copy ist " << typeid(scale_copy).name() << endl;

    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    ++factor;
    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    auto sf = scale_factory(11);
    cout << "sf(5) = " << sf(5) << endl;
}


