// vector_double.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>

using namespace std;

namespace ct {

    struct size_value { size_t s; };

    class vector
    {
        void check(size_t i) const { assert(i < s); }
    public:
        explicit vector(size_t ss) : s{ss}, data{ new double[s]} {}
        vector(size_value sv) : s{sv.s}, data{ new double[s] } {}

        vector(initializer_list<double> il) // : s{ il.size() }, data{ new double[s] }
            : vector(il.size())
        {
            copy(begin(il), end(il), data);
        }

        double& operator[](size_t i) { check(i); return data[i]; }
        const double& operator[](size_t i) const { check(i); return data[i]; }

        size_t size() const { return s; }

        // friend ostream& operator<<(std::ostream& os, vector& v);
    private:
        size_t  s;
        double* data;
    };

    ostream& operator<<(std::ostream& os, const vector& v)
    {
        // v[0] = 666.0;
        os << "{";
        if (v.size() > 0)
            os << v[0];
        for (size_t i = 1; i < v.size(); ++i)
            os << ", " << v[i];
        return os << "}";
    }

    size_t array_size(const vector& v) { return v.size(); }
}

int main()
{
    using namespace ct;

    // vector v{ 3 };
    // vector v{ size_value{3} };
    vector v(3);
    v[0] = 4.2; v[1] = 5.9; v[2] = 6.1;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 5.9) < 1e-12);

    cout << "v = " << v << '\n';
    // v << (cout << "v = ") << '\n'; // als Methode OMG

    vector w{ { 9.1, 2.4, 8.8 } };
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.4) < 1e-12);

    cout << "array_size(w) = " << array_size(w) << endl;
    // cout << "array_size(9) = " << array_size(9) << endl;
    cout << "array_size(9) = " << array_size(static_cast<vector>(9)) << endl;

    // vector x = 11; funktioniert nicht mit explizitem Konstrukto
}

