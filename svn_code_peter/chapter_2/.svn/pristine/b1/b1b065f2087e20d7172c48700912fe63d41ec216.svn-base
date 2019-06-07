#pragma once

#include <iterator>

namespace sn {

    class iiter
    {
      public:
	iiter(int i) : i{i} {}

	bool operator!=(iiter that) const { return i != that.i; }
	iiter& operator++() { ++i; return *this; }
	int operator*() const { return i; }

	iiter operator++(int)
	{
	    iiter cp(*this);
	    i++;
	    return cp;
	}
	
	int operator-(iiter that) const { return i - that.i; }
      private:
	int i;
    };

    int distance(iiter i1, iiter i2) { return *i2 - *i1; }

    
    class irange
    {
      public:
	irange(int from, int to)
	  : from{from}, to{to} {}

	iiter begin() const { return iiter(from); }
	iiter end() const { return iiter(to); }
      private:
	int from, to;
    };
    
}

namespace std {

    template <>
    struct iterator_traits<sn::iiter>
    {
	using value_type= int;
	using difference_type= int;
	// using iterator_category= std::forward_iterator_tag;
	using iterator_category= std::random_access_iterator_tag;
    };
    
}
