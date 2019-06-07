#include <iostream>
#include <memory>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>
#include "irange.hpp"

using namespace std;

namespace sn {

    struct out_of_range {};
    struct incompatible {};

    template <typename Value>
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	using value_type= Value;
	
	explicit vector(size_t s) : s{s}, data{ new Value[s] } {}

	vector(initializer_list<Value> il) : vector(il.size())
	{
	    size_t i{0};
	    for (Value d : il)
		data[i++]= d;
	}

	vector(const vector<Value>& that) : vector(that.size())
	{
	    cout << "Kopierkonstruktor\n";
	    *this= that;
	}

	template <typename Value2>
	vector(const vector<Value2>& that) : vector(that.size())
	{
	    cout << "Kopierkonstruktor\n";
	    std::copy(&that[0], &that[0] + s, &data[0]);
	}

	vector(vector&& that) : s{that.s}, data{move(that.data)}
	{
	    cout << "Move-Konstruktor\n";
	    // that.data= nullptr;
	    that.s= 0;
	}
	
	// ~vector() { delete[] data; }

	void size_check(size_t s) const { if (s != this->s) throw incompatible{}; }

	const vector& operator=(const vector& that)
	{
	    cout << "Kopierzuweisung\n";
	    size_check(that.size());
	    std::copy(&that.data[0], &that.data[s], &data[0]);
	    return *this;
	}

	const vector& operator=(vector&& that)
	{
	    cout << "Move-Zuweisung\n";
	    size_check(that.size());
	    data= move(that.data);
	    that.s= 0;
	    return *this;
	}

	const Value& operator[](size_t i) const& { check(i); return data[i]; }
	      Value& operator[](size_t i) &      { check(i); return data[i]; }
	      Value  operator[](size_t i) &&     { check(i); return data[i]; }

	size_t size() const { return s; }
	
	// friend std::ostream& operator<<(std::ostream& os, vector& v);
      private:
	size_t  s{0};
	std::unique_ptr<Value[]> data;
    };
    
    template <typename Value>
    std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
    {
	// v[0]= 666; // darf nicht kompilieren
	os << '{';
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << '}';
    }

    template <typename Value>
    vector<Value> operator+(const vector<Value>& v1, const vector<Value>& v2)
    {
	v1.size_check(v2.size());
	vector<Value> sum(v1.size());
	for (int i : irange(0, v1.size()))
	    sum[i]= v1[i] + v2[i];
	return sum;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    vector<double> w{9.1, 2.7, 3, 5.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.7) < 1e-10);

    vector<double> v{w};
    cout << "v = " << v << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;

    vector<double> x(w.size());
    x= w;
    cout << "x = " << x << endl;

    x= w + w;
    cout << "x = " << x << endl;

    vector<double> y{x + w};
    cout << "y = " << y << endl;

    x= move(y);
    cout << "y = " << y << endl;

    vector<double> z{move(w)};
    cout << "z = " << z << endl;
    cout << "w = " << w << endl;

    // vector<long double> vl{z};
    vector<long double> vl(z);
    cout << "vl = " << vl << endl;

    
    return 0;
}
  
 
