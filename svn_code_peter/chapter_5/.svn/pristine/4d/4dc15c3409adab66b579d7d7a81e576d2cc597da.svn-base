#include "pch.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <exception>
#include <initializer_list>
#include <algorithm>

using namespace std;

namespace vit {

    struct size_value { size_t s; };

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
        // vector(size_value sv) : s{ sv.s }, data{ new double[s] } {}

        vector(initializer_list<double> il) // : s{il.size()}, data{new double[s]} 
            : vector(il.size())
        {
            copy(begin(il), end(il), data);
        }
        
        const double& operator[](size_t i) const { check(i); return data[i]; }
              double& operator[](size_t i) { check(i); return data[i]; }

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

    size_t vsize(const vector& v) { return v.size(); }
}

int main(int argc, char** argv)
{
    using namespace vit;

    // vector v{ 3 };
    // vector v{ size_value{3} }; // Fuer Brace-Fetischisten
    vector v(3);
    v[0] = 2.3; v[1] = 4.2; v[2] = 5.9;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 4.2) < 1e-12);

    try {
        v[3];
        throw missing_exception{};
    }
    catch (vit::out_of_range& ) {
        cout << "Ausnahme erfolgreich gefangen, Yeah!!!\n";
    }

    cout << "v = " << v << endl;
    // v << (cout << "v = ") << endl;

    vector w= { 4.2, 8.1, 9.7 };
    cout << "w = " << w << endl;
    assert(abs(w[1] - 8.1) < 1e-12);

    cout << "w hat " << vsize(w) << " Eintraege.\n";
    // cout << "9 hat " << vsize(9) << " Eintraege.\n";
    cout << "9 hat " << vsize(static_cast<vector>(9)) << " Eintraege.\n";

    // vector z = 11;
}