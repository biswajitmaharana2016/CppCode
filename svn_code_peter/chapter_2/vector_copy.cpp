#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>

using namespace std;

namespace sn {

    struct out_of_range {};
    struct incompatible {};

    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
	void size_check(size_t s) const { if (s != this->s) throw incompatible{}; }
      public:
	vector(size_t s) : s{s}, data{ new double[s] } {}

	vector(initializer_list<double> il) : vector(il.size())
	{
	    size_t i{0};
	    for (double d : il)
		data[i++]= d;
	}

	vector(const vector& that) : vector(that.size())
	{
	    // std::copy(that.data, that.data + s, data);
	    *this= that;
	}
	
	~vector() { delete[] data; }

	const vector& operator=(const vector& that)
	{
	    size_check(that.size());
	    std::copy(that.data, that.data + s, data);
	    return *this;
	}

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

    vector w{9.1, 2.7, 3, 5.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.7) < 1e-10);

    vector v{w};
    cout << "v = " << v << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;

    vector x(w.size());
    x= w;
    cout << "x = " << x << endl;

    x[3]= 555;
    w[2]= 444;
    cout << "x = " << x << endl;
    cout << "w = " << w << endl;
    

    return 0;
}
  
 
