#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>

using namespace std;

namespace sn {

    struct out_of_range {};

    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	vector(size_t s) : s{s}, data{ new double[s] } {}

	vector(initializer_list<double> il) : vector(il.size())
	{
	    size_t i{0};
	    for (double d : il)
		data[i++]= d;
	}

	~vector() { delete[] data; }

	const double& operator[](size_t i) const& { check(i); return data[i]; }
	      double& operator[](size_t i) &      { check(i); return data[i]; }

	size_t size() const { return s; }
	
	// friend std::ostream& operator<<(std::ostream& os, vector& v);
      private:
	size_t  s;
	double* data;
    };
    
    std::ostream& operator<<(std::ostream& os, const vector& v)
    {
	// v[0]= 666; // darf nicht kompilieren
	os << '{';
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << '}';
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    // vector v{3};
    vector v(3);
    v[0]= 3.1; v[1]= 4.2; v[2]= 5.1;
    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 4.2) < 1e-10);

    cout << "v = " << v << endl;
    // v << (cout << "v = ") << endl; // Als Methode (OMG)

    vector w{9.1, 2.7, 3, 5.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.7) < 1e-10);

    return 0;
}
  
 
