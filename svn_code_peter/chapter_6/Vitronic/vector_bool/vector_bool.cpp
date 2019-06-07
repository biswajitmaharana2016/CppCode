// vector_bool.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

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
        {
            copy(that.data, that.data + s, data);
        }
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

    class vb_proxy
    {
    public:
        using uchar = unsigned char;

        vb_proxy(uchar& byte, size_t pos) 
            : byte{ byte }, mask{ static_cast<uchar>(1 << pos) } {}

        vb_proxy& operator=(bool value)
        {
            if (value)
                byte |= mask;
            else
                byte &= ~mask;
            return *this;
        }

        operator bool() const { return byte & mask; }

    private:
        uchar& byte;
        uchar  mask;
    };

    template <>
    class vector<bool>
    {
        using uchar = vb_proxy::uchar;
        void check(size_t i) const { assert(i < s); }
    public:
        explicit vector(size_t ss) : s{ ss }, data{ new uchar[(s+7)/8] } {}

        vector(initializer_list<bool> il) : vector(il.size())
        {
            size_t i = 0;
            for (bool value : il)
                (*this)[i++] = value;

                // operator[](i++) = value;
        }

        bool operator[](size_t i) const { check(i); return data[i / 8] >> i % 8 & 1; }

        vb_proxy operator[](size_t i) { return { data[i / 8], i % 8 }; }

        size_t size() const { return s; }

    private:
        size_t  s;
        uchar* data;
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

}

int main()
{
    using namespace ct;

    vector<bool> v(3);
    v[0];
    v[0] = false; v[1] = true; v[2] = false;
    cout << "v[1] = " << boolalpha << v[1] << endl;
    cout << "v = "  << v << '\n';
    assert(v[1]);


    vector<bool> w{ true, false, true };
    cout << "w = " << w << endl;
    assert(w[2]);

    char a[] = "Geht das wirklich?";
    for (char c : a)
        cout << c << endl;
}

