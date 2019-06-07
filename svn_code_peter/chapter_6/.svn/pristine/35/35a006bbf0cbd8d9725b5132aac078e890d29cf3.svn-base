// vector_template.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>

using namespace std;

namespace ct {

    template <typename Value>
    class vector
    {
        void check(size_t i) const { assert(i < s); }
    public:
        explicit vector(size_t ss) : s{ ss }, data{ new Value[s] } {}

        vector(initializer_list<Value> il) : vector(il.size())
        {
            copy(begin(il), end(il), data);
        }

        Value& operator[](size_t i) { check(i); return data[i]; }
        const Value& operator[](size_t i) const { check(i); return data[i]; }

        size_t size() const { return s; }

    private:
        size_t  s;
        Value* data;
    };

    template <typename Value>
    ostream& operator<<(std::ostream& os, const vector<Value>& v)
    {
        // v[0] = 666.0;
        os << "{";
        if (v.size() > 0)
            os << v[0];
        for (size_t i = 1; i < v.size(); ++i)
            os << ", " << v[i];
        return os << "}";
    }

    template <typename Value>
    size_t array_size(const vector<Value>& v) { return v.size(); }
}

int main()
{
    using namespace ct;

    // vector v{ 3 };
    vector<float> v(3);
    v[0] = 4.2f; v[1] = 5.9f; v[2] = 6.1f;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 5.9) < 1e-7);

    cout << "v = " << v << '\n';
    // v << (cout << "v = ") << '\n'; // als Methode OMG

    vector<double> w{ { 9.1, 2.4, 8.8 } };
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.4) < 1e-12);

    cout << "array_size(w) = " << array_size(w) << endl;
    // cout << "array_size(9) = " << array_size(9) << endl;
    cout << "array_size(9) = " << array_size(static_cast<vector<int>>(9)) << endl;

    // vector x = 11; funktioniert nicht mit explizitem Konstrukto
}

