#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <exception>
#include <algorithm>
#include <memory>
#include <initializer_list>

#include "irange.hpp"

using namespace std;

namespace le {

    struct out_of_range
      : std::runtime_error
    {
	out_of_range() : std::runtime_error("Out of range in vector") {}
    };

    struct incompatible_size
      : std::runtime_error
    {
	incompatible_size() : std::runtime_error("Incompatible size") {}
    };

    template <typename Value>
    class vector
    {
	void copy_that(const vector& that) { copy(&that.data[0], &that.data[s], &data[0]); }	    
      public:
	using value_type= Value;
	
	void check_size(size_t s) const { if (s != this->s) throw incompatible_size{}; }
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }

	explicit vector(size_t s = 0)
	  : s{s}, data{s > 0 ? new value_type[s] : nullptr}
	{ cout << "Size constructor\n";}

	vector(initializer_list<value_type> il)
	  : vector(il.size())
	{
	    cout << "List constructor\n";
	    size_t i= 0;
	    for (value_type v : il)
		data[i++]= v;
	}

	template <typename Iter>
        vector(Iter b, Iter e) : vector(distance(b, e))
        {
            std::copy(b, e, &data[0]);
        }


	vector(const vector& that) : vector(that.size())
	{
	    cout << "Copy constructor\n";
	    copy_that(that);
	}

	vector(vector&& that) : s{that.s}, data{move(that.data)}
	{
	    cout << "Move constructor\n";
	    // that.data= nullptr;
	    that.s= 0;
	}
	
	vector& operator=(const vector& that) &
	{
	    cout << "Copy assignment\n";
	    check_size(that.size());
	    copy_that(that);
	    return *this;
	}

	vector& operator=(vector&& that) &
	{
	    cout << "Move assignment\n";
	    check_size(that.size());
	    // delete[] data;
	    // data= that.data;
	    // that.data= nullptr;
	    data= move(that.data);
	    that.s= 0;
	    return *this;
	}
	
	// ~vector() { delete[] data; }

	const value_type& operator[](size_t i) const& { check(i); return data[i]; }
	      value_type& operator[](size_t i) &      { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t                   s;
	unique_ptr<value_type[]> data;
    };

    // Deduction guide
    vector(size_t) -> vector<float>;

    template<typename Iterator>
    vector(Iterator b, Iterator e)
        -> vector<typename std::iterator_traits<Iterator>::value_type>;

    
    
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
	const size_t s= v2.size();
	v1.check_size(s);
	vector<Value> sum(s);
	for (size_t i= 0; i < s; ++i)
	    sum[i]= v1[i] + v2[i];
	return sum;
    }
    
    void lvalue_only(int&) { cout << "Yeah, an lvalue.\n"; }
    void rvalue_only(int&&) { cout << "Yeah, an rvalue.\n"; }

    void pass_on(int&& i)
    {
	// rvalue_only(i); // lvalue
	rvalue_only(static_cast<int&&>(i)); // turn it into an rvalue again
	rvalue_only(move(i));               // convenience function
	
	rvalue_only(1 * i);                 // or like this
    }

    void rvalue_only(vector<float>&&) {}
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    vector w{2.4f, 4.9f, 2.5f};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.9) < 1e-7);

    // vector v{w}; // vector<vector<float>>
    vector v(w);
    cout << "v = " << v << endl;

    vector z(v.size());
    z= v;
    cout << "z = " << z << endl;

    // vector<float>(3)= z; // not allowed now

    z= v + w;
    cout << "z = " << z << endl;
    
    vector<float> x{v + w};
    cout << "x = " << x << endl;

    move(v); // still okay
    cout << "v = " << v << endl;

    rvalue_only(move(v)); // still okay
    cout << "v = " << v << endl;

    z= move(v); // v is now z
    cout << "v = " << v << endl;

    vector<float> y{move(v)};
    cout << "v = " << v << endl;

    irange ir20{1, 21};
    vector v20(begin(ir20), end(ir20));
    cout << "v20 = " << v20 << endl;
    
    return 0;
}
  
 
