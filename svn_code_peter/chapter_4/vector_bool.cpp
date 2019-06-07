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

    template <typename Value>
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	using value_type= Value;
	
	void size_check(size_t s) const { if (s != this->s) throw incompatible{}; }

	explicit vector(size_t s= 0) : s{s}, data{ s > 0 ? new value_type[s] : nullptr } {}

	vector(initializer_list<value_type> il) : vector(il.size())
	{
	    copy(begin(il), end(il), data); 
	}

	vector(const vector& that) : vector(that.size())
	{
	    cout << "Kopierkonstruktor.\n";
	    copy(that.data, that.data + s, data);
	    // *this= that;
	}

	vector(vector&& that) : s{that.s}, data{that.data}
	{
	    cout << "Move-Konstruktor.\n";
	    that.data= nullptr;
	    that.s= 0;
	}

	vector& operator=(const vector& that)
	{
	    cout << "Kopierzuweisung.\n";
	    size_check(that.size());
	    copy(that.data, that.data + s, data);
	    return *this;
	}

	vector& operator=(vector&& that)
	{
	    cout << "Move-Zuweisung.\n";
	    size_check(that.size());
	    // swap(data, that.data);
	    delete[] data;
	    data= that.data;
	    that.data= nullptr;
	    that.s= 0;
	    return *this;
	}
	
	~vector() { delete[] data; }

	const value_type& operator[](size_t i) const { check(i); return data[i]; }
	      value_type& operator[](size_t i)       { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t      s;
	value_type* data;
    };

    class vector_bool_proxy
    {
	using self= vector_bool_proxy;
      public:
	using uchar= unsigned char;

	vector_bool_proxy(uchar& byte, size_t pos)
	  : byte{byte}, mask{static_cast<uchar>(1 << pos)} {}

	self& operator=(bool value)
	{
	    if (value)
		byte|= mask;
	    else
		byte&= ~mask;
	    return *this;
	}

	operator bool() const { return byte & mask; }
      private:
	uchar& byte;
	uchar  mask;
    };

    template <>
    class vector<bool>
    {
	using uchar= vector_bool_proxy::uchar;
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	explicit vector(size_t s= 0) : s{s}, data{ s > 0 ? new uchar[(s+7)/8] : nullptr } {}

	vector(initializer_list<bool> il) : vector(il.size())
	{
	    size_t pos= 0;
	    for (bool value : il)
		(*this)[pos++]= value;
		// operator[](pos++)= value;
	}
	
	vector_bool_proxy operator[](size_t i) { return {data[i/8], i%8}; } 
	bool operator[](size_t i) const { check(i); return data[i/8] >> i%8 & 1; }

	size_t size() const { return s; }
      private:
	size_t  s;
	uchar*  data;
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
    using namespace ct;

    vector<bool> v(3);
    v[0]= true; v[1]= false; v[2]= true;
    cout << "v[2] = " << boolalpha << v[2] << endl;
    cout << "v = " << v << endl;
    assert(v[2]);

    vector<bool> w{false, true, true, false};
    cout << "w = " << w << endl;
    assert(w[1]);
    
    return 0;
}
  
 
