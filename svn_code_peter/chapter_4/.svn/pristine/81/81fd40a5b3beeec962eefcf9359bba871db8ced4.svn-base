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

	vector(size_t s= 0) : s{s}, data{ s > 0 ? new value_type[s] : nullptr } {}

	vector(initializer_list<value_type> il) 
	  : vector(il.size())
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
	size_t  s;
	value_type* data;
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

    template <typename Value>
    vector<Value> operator+(const vector<Value>& v1, const vector<Value>& v2)
    {
	size_t s= v1.size();
	v2.size_check(s);
	vector<Value> sum(s);
	for (size_t i= 0; i < s; ++i)
	    sum[i]= v1[i] + v2[i];
	return sum;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    vector<float> w{3.8, 4.2, 9.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.2) < 1e-6);

    vector<float> v{w};
    cout << "v = " << v << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "w = " << w << endl;
    cout << "v = " << v << endl;

    vector<float> x(3);
    x= v;
    cout << "x = " << x << endl;
    cout << "v = " << v << endl;

    x= v + w;
    cout << "x = " << x << endl;

    vector<float> y{x + w};
    cout << "y = " << y << endl;

    x= move(y);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    vector<float> z{move(w)};
    cout << "w = " << w << endl;
    
    return 0;
}
  
 
