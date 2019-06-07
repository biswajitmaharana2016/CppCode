// vector_copy.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

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

        void copy_that(const vector& that) 
        { copy(that.data, that.data + s, data); }
    public:
        void size_check(size_t st) const { assert(s == st); }

        explicit vector(size_t ss) : s{ ss }, data{ new Value[s] } {}

        vector(initializer_list<Value> il) : vector(il.size())
        {
            copy(begin(il), end(il), data);
        }

        vector(const vector& that) : vector(that.size())
        {
            copy_that(that);
        }

        const vector& operator=(const vector& that)
        {
            size_check(that.s);
            copy_that(that);
            return *this;
        }

        ~vector() { delete[] data; }

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

    vector<double> w{ { 9.1, 2.4, 8.8 } };
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.4) < 1e-12);

    vector<double> v{ w };
    cout << "v = " << v << '\n';

    v[0] = 666;
    w[1] = 999;
    cout << "w = " << w << endl;
    cout << "v = " << v << '\n';

    vector<double> x(3);
    x = v;
    cout << "x = " << x << endl;

 }

