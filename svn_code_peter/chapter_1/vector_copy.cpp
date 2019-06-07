#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <initializer_list>

using namespace std;

namespace mv {

    struct size_helper { size_t s; };

    template <typename Value>
    class vector
    {
	void check(size_t i) const { assert(i < s); }
	void size_check(size_t ss) const { assert(ss == s); }
      public:
	explicit vector(size_t s) : s{s}, data{new Value[s]} {}
	explicit vector(size_helper sh) : s{sh.s}, data{new Value[s]} {}

	vector(initializer_list<Value> il) : vector(il.size())
	{
	    size_t i{0};
	    for (Value value : il)
		data[i++]= value;
	}

	~vector() { delete[] data; }

	vector(const vector& that) : vector(that.size())
	{
	    std::copy(that.data, that.data + s, data);
	}

	vector& operator=(const vector& that)
	{
	    if (this != &that) {
		size_check(that.size());
		std::copy(that.data, that.data + s, data);
	    }
	    return *this;
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

    vector<double> v1{{5.1, 8.2, 9.1}};

    const vector<double> v2{v1};
    assert(abs(v2[1] - 8.2) < 1e-11);
    cout << "v2 = " << v2 << endl;

    v1[0]= 666;
    // v2[1]= 999;
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    vector<double> v3(3);
    v3= v1;
    
    cout << "v3 = " << v3 << endl;
    
    v1[2]= 333;
    cout << "v3 = " << v3 << endl;

    v3= v3;
    cout << "v3 = " << v3 << endl;
    
    return 0;
}
  
 
