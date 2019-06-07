#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>
#include <exception>

using namespace std;

namespace ct { 

    struct size_value { size_t i; };

    struct out_of_range : std::runtime_error
    {
	out_of_range() : runtime_error{"Vector index out of range"} {}
    };

    struct incompatible : std::runtime_error
    {
	incompatible() : runtime_error{"Incompatible vector size"} {}
    };
    
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	void size_check(size_t s) const { if (s != this->s) throw incompatible{}; }
	
	vector(size_t s) : s{s}, data{ new double[s] } {}

	vector(initializer_list<double> il) 
	  : vector(il.size())
	{
	    copy(begin(il), end(il), data); 
	}

	vector(const vector& that) : vector(that.size())
	{
	    // copy(that.data, that.data + s, data);
	    *this= that;
	}

	vector& operator=(const vector& that)
	{
	    size_check(that.size());
	    copy(that.data, that.data + s, data);
	    return *this;
	}
	
	~vector() { delete[] data; }

	const double& operator[](size_t i) const { check(i); return data[i]; }
	      double& operator[](size_t i)       { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t  s;
	double* data;
    };

    ostream& operator<<(ostream& os, const vector& v)
    {
	os << '{';
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << '}';
    }

    size_t vsize(const vector& v) { return v.size(); }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    vector w{3.8, 4.2, 9.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.2) < 1e-10);

    vector v{w};
    cout << "v = " << v << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "w = " << w << endl;
    cout << "v = " << v << endl;

    vector x(3);
    x= v;
    cout << "x = " << x << endl;
    cout << "v = " << v << endl;
    
    return 0;
}
  
 
