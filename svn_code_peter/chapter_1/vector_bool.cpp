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

	vector(initializer_list<Value> il) : vector(il.size())
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

    class vector_bool_proxy
    {
	using self= vector_bool_proxy;
      public:
	using uchar= unsigned char;
	vector_bool_proxy(uchar& byteref, size_t pos)
	  : byteref{byteref}, mask{static_cast<uchar>(1 << pos)} {}

	self& operator=(bool value) {
	    if (value)
		byteref|= mask;
	    else
		byteref&= ~mask;	    
	    return *this;
	}

	operator bool() const { return (byteref & mask) != 0; }
	
      private:
	uchar& byteref;
	uchar  mask;
    };

    template <>
    class vector<bool>
    {
	// typedef unsigned char uchar;
	// typedef int iarray[12];
	// typedef int (*fp)(int, int); 

	using uchar= vector_bool_proxy::uchar;
	// using iarray= int[12];
	// using fp= int (*)(int, int);
	void check(size_t i) const { assert(i < s); }

      public:
	explicit vector(size_t s) : s{s}, data{new uchar[(s+7)/8]} {}

	vector(initializer_list<bool> il) : vector(il.size())
	{
	    size_t i= 0;
	    for (bool value : il)
		(*this)[i++]= value;
	}
					    

	bool operator[](size_t i) const { check(i); return (data[i/8] >> i%8 & 1) == 1; }
	vector_bool_proxy operator[](size_t i) { check(i); return {data[i/8], i%8}; }
	
	size_t size() const { return s; }
      private:
	size_t  s;
	uchar* data;
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
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    vector<bool> v1(3);
    // v1[0];
    v1[0]= false; v1[1]= true; v1[2]= false;
    cout << "v1[1] = " << boolalpha << v1[1] << endl;
    assert(v1[1]);

    cout << "v1 = " << v1 << endl;

    vector<bool> v2{true, true, false, false};
    assert(v2[1]);
    cout << "v2 = " << v2 << endl;
    
    return 0;
}
  
 
