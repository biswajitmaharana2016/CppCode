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

    template <typename Value>
    class vector_sum;
    
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
	    data= move(that.data);
	    that.s= 0;
	    return *this;
	}

	vector& operator=(vector_sum<Value> that) &
	{
	    cout << "vector_sum assignment\n";
	    check_size(that.size());
	    for (size_t i= 0; i < s; ++i)
		data[i]= that[i];	    
	    return *this;
	}
	
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

#if 0
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
#endif

    template <typename Value>
    class vector_sum
    {
      public:
	explicit vector_sum(const vector<Value>& v1, const vector<Value>& v2)
	  : v1{v1}, v2{v2}
	{ v1.check_size(v2.size()); }

	size_t size() const { return v1.size(); }

	Value operator[](size_t i) { v1.check(i); return v1[i] + v2[i]; }
	
      private:
	const vector<Value>& v1;
	const vector<Value>& v2;
    };
    
    template <typename Value>
    vector_sum<Value> operator+(const vector<Value>& v1, const vector<Value>& v2)
    {
	return vector_sum<Value>{v1, v2};
    }

    template <typename Value>
    void add(vector<Value>& sum, const vector<Value>& v1, const vector<Value>& v2)
    {
	const size_t s= v2.size();
	v1.check_size(s);
	sum.check_size(s);
	for (size_t i= 0; i < s; ++i)
	    sum[i]= v1[i] + v2[i];
    }

    template <typename Value>
    void add(vector<Value>& sum, const vector<Value>& v1, const vector<Value>& v2,
	     const vector<Value>& v3)
    {
	const size_t s= v2.size();
	v1.check_size(s);
	v3.check_size(s);
	sum.check_size(s);
	for (size_t i= 0; i < s; ++i)
	    sum[i]= v1[i] + v2[i] + v3[i];
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    vector v{3.4f, 4.1f, 2.5f};
    cout << "v = " << v << endl;
    
    vector w{2.4f, 4.9f, 2.5f};
    cout << "w = " << w << endl;

    vector<float> x(3);
    x= v + w;
    cout << "x = " << x << endl;
   
    // x= v + w + v;
    // cout << "x = " << x << endl;

    cout << "----------------\n";

    add(x, v, w);
    cout << "x = " << x << endl;

    add(x, v, w, v);
    cout << "x = " << x << endl;
    
    
    return 0;
}
  
 
