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

    template <typename Value>
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	using value_type= Value;
	
	explicit vector(size_t s) : s{s}, data{new value_type[s]} {}

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

    class vector_bool_proxy
    {
      public:
	using uchar= unsigned char;

	vector_bool_proxy(uchar& byte, size_t pos)
	  : byte{byte}, mask{static_cast<uchar>(1 << pos)} {}

	vector_bool_proxy& operator=(bool value)
	{
	    if (value)
		byte|= mask;
	    else
		byte&= ~mask;
	    return *this;
	}

	operator bool() const { return (byte & mask) != 0; }
	
      private:
	uchar& byte;
	uchar  mask;
    };
    
    template <>
    class vector<bool>
    {
	using uchar= unsigned char;
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	explicit vector(size_t s) : s{s}, data{new uchar[(s+7)/8]} {}

	bool operator[](size_t i) const { check(i); return (data[i/8] >> i%8 & 1) == 1; }
	vector_bool_proxy operator[](size_t i) { check(i); return {data[i/8], i%8}; }
	
	size_t size() const { return s; }
      private:
	size_t      s;
	uchar*      data;
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
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    vector<bool> v(3);
    v[0]= false; v[1]= true; v[2]= false;
    cout << "v[1] = " << boolalpha << v[1] << endl;
    assert(v[1]);

    cout << "v = " << v << endl;

    // vector<bool> w{true, false, true, false};
    // cout << "w = " << w << endl;
    // assert(! w[1]);
    
    return 0;
}
  
 
