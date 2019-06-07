// vector_copy.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <exception>
#include <initializer_list>
#include <algorithm>

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
        explicit vector(size_t s) : s{ s }, data{ new double[s] } {}

        vector(initializer_list<double> il) : vector(il.size())
        {
            copy(begin(il), end(il), data);
        }

        vector(const vector& that) : vector(that.size())
        {
            copy(that.data, that.data + s, data);
        }

        vector& operator=(const vector& that) &
        {
            assert(s == that.s);
            copy(that.data, that.data + s, data);
            return *this;
        }

        ~vector() { delete[] data; }

        const double& operator[](size_t i) const & { check(i); return data[i]; }
              double& operator[](size_t i)       & { check(i); return data[i]; }

        // friend std::ostream& operator<<(std::ostream& os, vector& v);

        size_t size() const { return s; }
    private:
        size_t  s;
        double* data;
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

    // vector(3) = v;
 }