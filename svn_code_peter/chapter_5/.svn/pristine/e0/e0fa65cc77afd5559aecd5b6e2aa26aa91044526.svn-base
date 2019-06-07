// vector_unique_ptr.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <exception>
#include <initializer_list>
#include <algorithm>
#include <cstring>
#include <memory>

using namespace std;

namespace vit {

    struct out_of_range : runtime_error
    {
        out_of_range() : runtime_error{ "Index out of range in vit::vector" } {}
    };

    struct missing_exception {};

    class vector
    {
        void check(size_t i) const { if (i >= s) throw out_of_range{}; }
    public:
        void size_check(size_t ss) const { assert(s == ss); }

        vector() : s{ 0 }, data{ nullptr } {}

        explicit vector(size_t s) : s{ s }, data{ new double[s] } {}

        vector(initializer_list<double> il) : vector(il.size())
        {
            copy(begin(il), end(il), &data[0]);
        }

        vector(const vector& that) : vector(that.size())
        {
            cout << "Kopierkonstruktor\n";
            copy(&that.data[0], &that.data[s], &data[0]);
        }

        vector(vector&& that) : s{ that.s }, data{ move(that.data) }
        {
            cout << "Move-Konstruktor\n";
            // that.data = nullptr;
            that.s = 0;
        }

        vector& operator=(const vector& that) &
        {
            cout << "Kopierzuweisung\n";
            size_check(that.s);
            copy(&that.data[0], &that.data[s], &data[0]);
            return *this;
        }

        vector& operator=(vector&& that) &
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

        // ~vector() { cout << "Dtor\n"; delete[] data; }

        const double& operator[](size_t i) const & { check(i); return data[i]; }
        double& operator[](size_t i) & { check(i); return data[i]; }
        double operator[](size_t i) && { check(i); return data[i]; }

        size_t size() const { return s; }
    private:
        size_t                    s;
        std::unique_ptr<double[]> data;
    };

    std::ostream& operator<<(std::ostream& os, const vector& v)
    {
        // v[0] = 666;
        os << '{';
        if (v.size() > 0)
            os << v[0];
        for (size_t i = 1; i < v.size(); ++i)
            os << ", " << v[i];
        return os << '}';
    }

    vector operator+(const vector& v1, const vector& v2)
    {
        size_t s = v2.size();
        v1.size_check(s);
        vector sum(s);
        for (size_t i = 0; i < s; ++i)
            sum[i] = v1[i] + v2[i];
        return sum;
    }

}

int main(int argc, char** argv)
{
    using namespace vit;

    vector w = { 4.2, 8.1, 9.7 };
    cout << "w = " << w << endl;
    assert(abs(w[1] - 8.1) < 1e-12);

    vector v{ w };
    cout << "v = " << v << endl;

    v[0] = 666;
    w[1] = 999;
    cout << "w = " << w << endl;
    cout << "v = " << v << endl;

    vector x(3);
    x = v;
    cout << "x = " << x << endl;
    cout << "v = " << v << endl;

    x = v + w;
    cout << "x = " << x << endl;

    vector y{ x + w };
    cout << "y = " << y << endl;

    {
        vector y{ 3 };
    }

    y = move(x);
    cout << "x = " << x << endl;

    vector z{ move(v) };
    cout << "v = " << v << endl;

}