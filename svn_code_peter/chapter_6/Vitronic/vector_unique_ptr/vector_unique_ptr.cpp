// vector_unique_ptr.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>
#include <memory>

using namespace std;

namespace ct {

    template <typename Value>
    class vector
    {
        void check(size_t i) const { assert(i < s); }

        void copy_that(const vector& that)
        {
            copy(&that.data[0], &that.data[s], &data[0]);
        }
    public:
        void size_check(size_t st) const { assert(s == st); }

        explicit vector(size_t ss) : s{ ss }, data{ new Value[s] } {}

        vector(initializer_list<Value> il) : vector(il.size())
        {
            copy(begin(il), end(il), &data[0]);
        }

        vector(const vector& that) : vector(that.size())
        {
            cout << "Copy-Konstruktor\n";
            copy_that(that);
        }

        // vector(const vector& that) = default;

        vector(vector&& that) : s{ that.s }, data{ move(that.data) }
        {
            cout << "Move-Konstruktor\n";
            // that.data = nullptr;
            that.s = 0;
        }

        const vector& operator=(const vector& that)
        {
            cout << "Copy-Zuweisung\n";
            size_check(that.s);
            copy_that(that);
            return *this;
        }

        const vector& operator=(vector&& that)
        {
            cout << "Move-Zuweisung\n";
            size_check(that.s);
            //delete[] data;
            //data = that.data;
            //that.data = nullptr;
            data = move(that.data);
            that.s = 0;
            return *this;
        }

        // ~vector() { delete[] data; }

        Value& operator[](size_t i) { check(i); return data[i]; }
        const Value& operator[](size_t i) const { check(i); return data[i]; }

        size_t size() const { return s; }

    private:
        size_t              s;
        unique_ptr<Value[]> data;
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
    vector<Value> operator+(const vector<Value>& v1, const vector<Value>& v2)
    {
        size_t s = v2.size();
        v1.size_check(s);
        vector<Value> sum(s);
        for (size_t i = 0; i < s; ++i)
            sum[i] = v1[i] + v2[i];
        return sum;
    }

}

int main()
{
    using namespace ct;

    vector<double> w{ { 9.1, 2.4, 8.8 } };
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.4) < 1e-12);

    vector<double> v{ w };
    cout << "v = " << v << '\n';

    vector<double> x(3);
    x = v;
    cout << "x = " << x << endl;

    x = v + w;
    cout << "x = " << x << endl;

    vector<double> y{ v + w };
    cout << "y = " << y << endl;

    x = move(v);
    cout << "v = " << v << '\n';

    vector<double> z{ move(w) };
    cout << "w = " << w << endl;
}

