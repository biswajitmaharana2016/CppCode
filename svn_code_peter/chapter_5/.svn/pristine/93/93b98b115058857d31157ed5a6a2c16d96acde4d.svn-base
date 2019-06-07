// vector_bool.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.


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

    template <typename Value>
    class vector
    {
        void check(size_t i) const { if (i >= s) throw out_of_range{}; }
    public:
        using value_type = Value;

        void size_check(size_t ss) const { assert(s == ss); }

        vector() : s{ 0 }, data{ nullptr } {}

        explicit vector(size_t s) : s{ s }, data{ new value_type[s] } {}

        vector(initializer_list<value_type> il) : vector(il.size())
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

        vector& operator=(const vector<Value>& that) &
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
            data = move(that.data);
            that.s = 0;
            return *this;
        }

        const value_type& operator[](size_t i) const & { check(i); return data[i]; }
        value_type& operator[](size_t i) & { check(i); return data[i]; }
        value_type operator[](size_t i) && { check(i); return data[i]; }

        size_t size() const { return s; }
    private:
        size_t                    s;
        std::unique_ptr<value_type[]> data;
    };

    class vector_bool_proxy
    {
    public:
        using uchar = unsigned char;

        vector_bool_proxy(uchar& byte, size_t pos) 
            : byte{ byte }, mask { static_cast<uchar>(1 << pos) } {}

        vector_bool_proxy& operator=(bool value) 
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
        using uchar = vector_bool_proxy::uchar;
        void check(size_t i) const { if (i >= s) throw out_of_range{}; }
    public:
        explicit vector(size_t s) : s{s}, data{ new uchar[(s+7)/8]} {}

        vector(initializer_list<bool> il) : vector(il.size())
        {
            size_t i = 0;
            for (bool v : il)
                (*this)[i++] = v;

                //operator[](i++) = v;
        }

        vector_bool_proxy operator[](size_t i) { check(i); return { data[i / 8], i % 8 }; }

        bool operator[](size_t i) const { check(i); return data[i / 8] >> i % 8 & 1; }

        size_t size() const { return s;  }
    private:
        size_t              s;
        unique_ptr<uchar[]> data;
    };


    template <typename Value>
    std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
    {
        // v[0] = 666;
        os << '{';
        if (v.size() > 0)
            os << v[0];
        for (size_t i = 1; i < v.size(); ++i)
            os << ", " << v[i];
        return os << '}';
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

int main(int argc, char** argv)
{
    using namespace vit;

    vector<bool>   v(3);
    v[0];
    v[0] = false; v[1] = true; v[2] = false;
    cout << "v[1] = " << boolalpha << v[1] << endl;
    cout << "v = " << v << endl;
    assert(v[1]);

    vector<bool> w = { true, false, true };
    cout << "w = " << w << endl;
    assert(!w[1]);

 
}