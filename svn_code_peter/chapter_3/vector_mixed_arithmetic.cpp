#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <exception>
#include <algorithm>
#include <memory>
#include <initializer_list>
#include <type_traits>

#include "irange.hpp"

using namespace std;

namespace le {

    template <typename Vector1, typename Vector2>
    class vector_sum;
    
    template <typename Value>
    class vector;

    template <typename T>
    struct is_container
      : std::false_type {};
    
    template <typename Value>
    struct is_container<vector<Value>>
      : std::true_type {};

    template <typename T>
    using const_ref_container= conditional_t<is_container<T>::value, const T&, T>;
    
    template <typename T>
    struct is_vector_expression
      : std::false_type {};
    
    template <typename Vector1, typename Vector2>
    struct is_vector_expression<vector_sum<Vector1, Vector2>>
      : std::true_type {};

    template <typename T>
    constexpr bool is_vector= is_container<T>::value || is_vector_expression<T>::value;
    
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

	template <typename Vector1, typename Vector2>
	vector& operator=(vector_sum<Vector1, Vector2> that) &
	{
	    cout << "vector_sum assignment\n";
	    check_size(that.size());
	    for (size_t i= 0; i < s; ++i)
		data[i]= that[i];	    
	    return *this;
	}
	
	const value_type& operator[](size_t i) const& { check(i); return data[i]; }
	      value_type& operator[](size_t i) &      { check(i); return data[i]; }
      	      value_type  operator[](size_t i) &&     { check(i); return data[i]; }

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

    template <typename Vector1, typename Vector2>
    class vector_sum
    {
	const_ref_container<Vector1> v1;
	const_ref_container<Vector2> v2;
      public:
	using value_type= decltype(v1[0] + v2[0]);
	
	explicit vector_sum(const Vector1& v1, const Vector2& v2)
	  : v1{v1}, v2{v2}
	{ v1.check_size(v2.size()); }

	size_t size() const { return v1.size(); }
	
	void check_size(size_t s) const { if (s != size()) throw incompatible_size{}; }
	void check(size_t i) const { if (i >= size()) throw out_of_range{}; }

	value_type operator[](size_t i) const { v1.check(i); return v1[i] + v2[i]; }
    };
    
    template <typename Vector1, typename Vector2,
	      typename = std::enable_if_t<is_vector<Vector1> && is_vector<Vector2> > >
    vector_sum<Vector1, Vector2> operator+(const Vector1& v1, const Vector2& v2)
    {
	return vector_sum<Vector1, Vector2>{v1, v2};
    }

}

int main (int argc, char* argv[]) 
{
    using namespace le;

    vector v{3.4f, 4.1f, 2.5f};
    cout << "v = " << v << endl;
    
    vector w{2.4, 4.9, 2.5};
    cout << "w = " << w << endl;

    vector<double> x(3);
    x= v + w;
    cout << "x = " << x << endl;
   
    x= v + w + v;
    cout << "x = " << x << endl;

    return 0;
}
  
 
