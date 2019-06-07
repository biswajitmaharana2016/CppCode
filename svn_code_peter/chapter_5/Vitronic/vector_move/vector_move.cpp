// vector_move.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <exception>
#include <initializer_list>
#include <algorithm>
#include <cstring>

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

        vector() : s{0}, data{nullptr} {}

        explicit vector(size_t s) : s{ s }, data{ new double[s] } {}

        vector(initializer_list<double> il) : vector(il.size())
        {
            copy(begin(il), end(il), data);
        }

        vector(const vector& that) : vector(that.size())
        {
            cout << "Kopierkonstruktor\n";
            copy(that.data, that.data + s, data);
        }

        vector(vector&& that) : s{ that.s }, data{ that.data }
        {
            cout << "Move-Konstruktor\n";
            that.data = nullptr;
            that.s = 0;
        }

        vector& operator=(const vector& that) &
        {
            cout << "Kopierzuweisung\n";
            size_check(that.s);
            copy(that.data, that.data + s, data);
            return *this;
        }

        vector& operator=(vector&& that) &
        {
            cout << "Move-Zuweisung\n";
            size_check(that.s);
            // swap(data, that.data);
            delete[] data;
            data = that.data;
            that.data = nullptr;
            that.s = 0;
            return *this;
        }

        ~vector() { cout << "Dtor\n"; delete[] data; }

        const double& operator[](size_t i) const & { check(i); return data[i]; }
        double& operator[](size_t i) & { check(i); return data[i]; }
        double operator[](size_t i) && { check(i); return data[i]; }

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

    vector operator+(const vector& v1, const vector& v2)
    {
        size_t s = v2.size();
        v1.size_check(s);
        vector sum(s);
        for (size_t i = 0; i < s; ++i)
            sum[i] = v1[i] + v2[i];
        return sum;
    }

    void lvalue_only(int&) { cout << "Yeah, ein lvalue.\n"; }
    void rvalue_only(int&&) { cout << "Yeah, ein rvalue.\n"; }

    void gib_weiter(int&& i) 
    { 
        rvalue_only(1 * i); 
        rvalue_only(static_cast<int&&>(i));
        rvalue_only(move(i));
    }

    void rvalue_only(vector&&) {}
}

int main(int argc, char** argv)
{
    using namespace vit;

    int i{ 7 };

    lvalue_only(i);
    // lvalue_only(3);
    // lvalue_only(1 * i);
    // lvalue_only(i++);
    lvalue_only(++i);
    ++++i;
    // i++++;

    // rvalue_only(i);
    rvalue_only(3);
    rvalue_only(1 * i);
    rvalue_only(i++);
    // rvalue_only(++i);

    gib_weiter(3);

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

    move(x);
    cout << "x = " << x << endl;

    rvalue_only(move(x));
    cout << "x = " << x << endl;

    y = move(x);
    cout << "x = " << x << endl;

    vector z{ move(v) };
    cout << "v = " << v << endl;

    cout << sizeof(vector) << endl;
    // bloss nicht!!!
    cout << "Allokation mit malloc\n";
    vector* p1 = static_cast<vector*>(malloc(sizeof(vector)));

    // 

    cout << "Allokation mit new\n";
    vector* p2 = new vector{ 3.1, 4.2, 9 };

    // *p1 = *p2;
    memcpy(p1, p2, sizeof(vector));
    cout << "*p1 = " << *p1 << endl;

    delete p2;
    free(p1);

    cout << "Nach delete\n";


}