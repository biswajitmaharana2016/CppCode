#include <iostream>
#include <cassert>
#include <cmath>
#include <exception>
#include <initializer_list>

using namespace std;

namespace le {

    struct out_of_range
      : std::runtime_error
    {
	out_of_range() : std::runtime_error("Out of range in vector") {}
    };
    
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range(); }
      public:
	explicit vector(size_t s) : s(s), data(new double[s]) {}

	vector(initializer_list<double> il) // : s(il.size()), data(new double[s])
	  : vector(il.size())
	{
	    size_t i= 0;
	    for (double v : il)
		data[i++]= v;
	}
	

	const double& operator[](size_t i) const { check(i); return data[i]; }
	      double& operator[](size_t i)       { check(i); return data[i]; }

	// ostream& operator<<(ostream& os)
	// {
	//     os << '{';
	//     if (s > 0)
	// 	os << data[0];
	//     for (size_t i= 1; i < s; ++i)
	// 	os << ", " << data[i];
	//     return os << '}';
	// }

	// friend ostream& operator<<(ostream& os, vector& v);

	size_t size() const { return s; }
      private:
	size_t  s;
	double* data;
    };

    ostream& operator<<(ostream& os, const vector& v)
    {
	// v[0]= 666;
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
    using namespace le;

    vector v(3);
    v[0]= 3.1; v[1]= 4.2; v[2]= 7.1;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 4.2) < 1e-10);

    cout << "v = " << v << endl;
    // v << (cout << "v = ") << endl; // as method (OMG)

    vector w{1.9, 4.9, 2.5};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.9) < 1e-10);

    cout << "Size of w is " << vsize(w) << ".\n";

    // cout << "Size of 5 is " << vsize(5) << ".\n";
    // cout << "Size of 5 is " << vsize(static_cast<vector>(5)) << ".\n";
    
    // vector z= 9;
    // cout << "Size of z is " << vsize(z) << ".\n";

    return 0;
}
  
 
