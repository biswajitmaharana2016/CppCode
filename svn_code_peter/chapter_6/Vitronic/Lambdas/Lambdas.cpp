// Lambdas.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <iterator>
#include <memory>

using namespace std;

namespace ct {


    struct klassen_lambda
    {
        int f(int i) { return k + i; }

        int g(int i)
        {
            auto la = [this, i](int j) { return f(i + j) + k; };
            return la(i + 1);
        }

        int k{ 8 };
    };

    struct inc_scale_f
    {
        int operator()(int i) const { return ++factor * i; };
        mutable int factor;
    };

    // C++14
    template <typename Container>
    void reverse_sort(Container& c)
    {
        sort(begin(c), end(c), [](auto x, auto y){ return x > y; });
        // C++11 geht das zur Not auch 
        // using rt = decltype(*begin(c));
        // sort(begin(c), end(c), [](rt x, rt y) { return x > y; });
    }

    auto scale_factory(int i)
    {
        unique_ptr<int> up{ new int{i} };
        // return [up](int x) { return *up * x; }; // kein Copy-Ktor
        // return [&up](int x) { return *up * x; }; // doppelt ungueltig
        return [u= move(up)](int x) { return *u * x; };
    }
}

int main()
{
    using namespace ct;

    using ci = complex<int>;
    vector<ci> v{ {4, 6}, {2, 11}, {8, 3} };
    sort(begin(v), end(v), [](ci x, ci y) { return real(x) < real(y); });
    copy(begin(v), end(v), ostream_iterator<ci>(cout, " ")); cout << endl;

    vector<int> w{ 8, 1, 3, 9, 11, 4 }, x(w.size());
    // sort(begin(w), end(w), [](int x, int y) { return x > y; });
    reverse_sort(w);
    copy(begin(w), end(w), ostream_iterator<int>(cout, ", ")); cout << endl;

    int factor{ 6 };
    transform(begin(w), end(w), begin(x), [factor](int i){ return factor * i; });
    copy(begin(x), end(x), ostream_iterator<int>(cout, ", ")); cout << endl;

    auto scale_copy = [factor](int i) { return factor * i; };
    auto scale_ref = [&factor](int i) { return factor * i; };

    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    ++factor;
    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    // lieber nicht, siehe Scott Meyers fuer Details
    auto copy_all= [=](int i) { return factor * i; };
    auto ref_all = [&](int i) { return factor * i; };
    auto copy_most = [=,&factor](int i) { return factor * i; };
    auto ref_most = [&,factor](int i) { return factor * i; };

    auto inc_scale= [factor](int i) mutable { return ++factor * i; };
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;

    auto sf = scale_factory(7);
    cout << "scale_factory(7)(6) = " << sf(6) << endl;
}

