#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>

using namespace std;

namespace mv {

    struct size_helper { size_t s; };

    template <typename Value>
    class vector
    {
	void check(size_t i) const { assert(i < s); }
      public:
	explicit vector(size_t s) : s{s}, data{new Value[s]} {}
	explicit vector(size_helper sh) : s{sh.s}, data{new Value[s]} {}

	vector(initializer_list<Value> il) : s{il.size()}, data{new Value[s]}
	{
	    size_t i{0};
	    for (Value value : il)
		data[i++]= value;
	}
	
	const Value& operator[](size_t i) const { check(i); return data[i]; }
              Value& operator[](size_t i)       { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t  s;
	Value* data;
    };

    template <typename Value>
    std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
    {
	os << "{";
	// v[1]= 666;
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << "}";
    }

    size_t vsize(vector<double> const& v) { return v.size(); }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    // vector v1{3};
    // vector v1(3);
    vector<float> v1{size_helper{3}};
    
    v1[0]= 2.3; v1[1]= 2.8; v1[2]= 5.3;
    cout << "v1[1] = " << v1[1] << endl;
    assert(abs(v1[1] - 2.8) < 1e-7);

    cout << "v1 = " << v1 << endl;
    // v1 << (cout << "v1 = ") << endl;

    vector<double> v2{{5.1, 8.2, 9.1}};
    assert(abs(v2[1] - 8.2) < 1e-11);
    cout << "v2 = " << v2 << endl;

    cout << "size of v2 is " << vsize(v2) << endl;
    // cout << "size of 7 is " << vsize(7) << endl;

    // vector<double> v3= 8;
    // cout << "size of v3 is " << vsize(v3) << endl;
    
    return 0;
}
  
 
