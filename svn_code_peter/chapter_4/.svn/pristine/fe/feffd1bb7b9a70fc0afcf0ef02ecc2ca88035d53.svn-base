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
    
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	explicit vector(size_t s) : s{s}, data{ new double[s] } {}
	vector(size_value sv) : s{sv.i}, data{ new double[s] } {}

	vector(initializer_list<double> il) // : s{il.size()}, data{ new double[s] }
	  : vector(il.size())
	{
	    copy(begin(il), end(il), data); 
	}

	const double& operator[](size_t i) const { check(i); return data[i]; }
	      double& operator[](size_t i)       { check(i); return data[i]; }

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
    using namespace ct;

    // vector v{3};
    vector v(3);
    // vector v{size_value{3}};
    v[0]= 3.2; v[1]= 4.1; v[2]= 9.3;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 4.1) < 1e-10);

    try {
	v[3]= 9.2;
    } catch (ct::out_of_range& e) {
	cerr << "Daneben!\n";
    }

    // v << (cout << "v = ") << endl; // Als Methode (OMG)
    cout << "v = " << v << endl;

    vector w{3.8, 4.2, 9.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.2) < 1e-10);

    cout << "w hat " << vsize(w) << " Eintraege.\n";
    // cout << "7 hat " << vsize(7) << " Eintraege.\n";
    cout << "7 hat " << vsize(static_cast<vector>(7)) << " Eintraege.\n";

    // vector x= 11;
    // cout << "x hat " << vsize(x) << " Eintraege.\n";
    
    return 0;
}
  
 
