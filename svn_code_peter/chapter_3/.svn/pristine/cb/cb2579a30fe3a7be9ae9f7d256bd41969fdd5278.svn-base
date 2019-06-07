#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <exception>
#include <complex>
#include <initializer_list>

using namespace std;

namespace le {

    struct out_of_range
      : std::runtime_error
    {
	out_of_range() : std::runtime_error("Out of range in vector") {}
    };

    struct size_value { size_t s; };
    
    template <typename Value>
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	using value_type= Value;
	
	explicit vector(size_t s) : s{s}, data{new value_type[s]} {}
	explicit vector(size_value sv) : vector(sv.s) {}

	explicit vector(double, double) : vector(0) { cout << "double double\n"; }

	vector(initializer_list<value_type> il)
	  : vector(il.size())
	{
	    size_t i= 0;
	    for (value_type v : il)
		data[i++]= v;
	}
	

	const value_type& operator[](size_t i) const { check(i); return data[i]; }
	      value_type& operator[](size_t i)       { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t      s;
	value_type* data;
    };

    template <typename Value>
    ostream& operator<<(ostream& os, const vector<Value>& v)
    {
	os << '{';
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << '}';
    }

    template <typename Value>
    size_t vsize(const vector<Value>& v) { return v.size(); }

    template <typename Container>
    typename Container::value_type first_entry(const Container& c)
    {
	return c[0];
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    vector<double> v(3);
    // vector<double> v{3};        // one entry, which is 3
    // vector<double> v{size_value{3}}; // three entries, bit clumsy
    v[0]= 3.1; v[1]= 4.2; v[2]= 7.1;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 4.2) < 1e-10);

    cout << "v = " << v << endl;

    // const double w0{1.9};
    const int w0{4};
    vector<float> w{w0, 4.9, 2.5};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.9) < 1e-7);

    cout << "Size of w is " << vsize(w) << ".\n";

    vector<int>  vi1(3.4, 3.6);
    // vector<int>  vi2{3.4, 3.6};

    vector<complex<int>> vd1{{1}}, vd2{{1, 2}}, vd3{{1, 2, 3}};
    cout << "vd1 = " << vd1 << endl;
    cout << "vd2 = " << vd2 << endl;
    cout << "vd3 = " << vd3 << endl;

    vector<string> vs1{3}, vs2{{3}};
    cout << "vs1 = " << vs1 << endl;
    cout << "vs2 = " << vs2 << endl;

    vsize(vector<int>{4, 5, 9, 4});
    
    
    return 0;
}
  
 
