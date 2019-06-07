#include <iostream>
#include <cassert>
#include <cmath>
#include <exception>
#include <initializer_list>

using namespace std;

namespace le {

    // typedef double real_type;
    // typedef int array_type[9];
    // typedef int (ftype*)(int, int);

    // using real_type= double;
    // using array_type= int[9];
    // using ftype= int (*)(int, int);

    // --------

    struct out_of_range
      : std::runtime_error
    {
	out_of_range() : std::runtime_error("Out of range in vector") {}
    };

    template <typename Value>
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range(); }
      public:
	using value_type= Value;
	
	explicit vector(size_t s) : s(s), data(new value_type[s]) {}

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
    v[0]= 3.1; v[1]= 4.2; v[2]= 7.1;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 4.2) < 1e-10);

    cout << "v = " << v << endl;

    vector<float> w{1.9, 4.9, 2.5};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.9) < 1e-7);

    cout << "Size of w is " << vsize(w) << ".\n";

    return 0;
}
  
 
