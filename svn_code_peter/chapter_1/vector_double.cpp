#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>

using namespace std;

namespace mv {

    struct size_helper { size_t s; };
    
    class vector
    {
	void check(size_t i) const { assert(i < s); }
      public:
	vector(size_t s) : s{s}, data{new double[s]} {}
	vector(size_helper sh) : s{sh.s}, data{new double[s]} {}

	vector(initializer_list<double> il) : s{il.size()}, data{new double[s]}
	{
	    size_t i{0};
	    for (double value : il)
		data[i++]= value;
	}
	
	const double& operator[](size_t i) const { check(i); return data[i]; }
              double& operator[](size_t i)       { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t  s;
	double* data;
    };

    std::ostream& operator<<(std::ostream& os, const vector& v)
    {
	os << "{";
	// v[1]= 666;
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << "}";
    }

}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    // vector v1{3};
    // vector v1(3);
    vector v1{size_helper{3}};
    
    v1[0]= 2.3; v1[1]= 2.8; v1[2]= 5.3;
    cout << "v1[1] = " << v1[1] << endl;
    assert(abs(v1[1] - 2.8) < 1e-11);

    cout << "v1 = " << v1 << endl;
    // v1 << (cout << "v1 = ") << endl;

    vector v2{{5.1, 8.2, 9.1}};
    assert(abs(v2[1] - 8.2) < 1e-11);
    cout << "v2 = " << v2 << endl;

    
    
    return 0;
}
  
 
