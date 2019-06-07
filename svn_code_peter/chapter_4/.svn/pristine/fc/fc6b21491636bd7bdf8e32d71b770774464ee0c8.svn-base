#include <iostream>

using namespace std;

namespace ct {

    template <typename T>
    struct base
    {
	using value_type= T;
	T f(T i) { return i + k; }
	T k{5};
    };

    template <typename T>
    struct derived_int : base<int>
    {
	T g(T i)
	{
	    value_type j{i + 2};
	    j+= 2 * k;
	    return f(j);
	}
    };
    
    template <typename T>
    struct derived : base<T>
    {
    	T g(T i)
    	{
    	    typename base<T>::value_type j{i + 2};
    	    // j+= 2 * base<T>::k;
    	    // return base<T>::f(j);

    	    j+= 2 * this->k;
    	    return this->f(j);
	    
    	    // value_type j{i + 2};
    	    // j+= 2 * k;
    	    // return f(j);
    	}
    };

    // Wer so etwas schreibt, gehoert gefeuert!
    template <>
    struct base<short>
    {
	using k= long;
	using f= short;
	double value_type(int i) { return 1.2 * i; }
    };

}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    derived<int> d1;
    cout << "d1.g(4) = " << d1.g(4) << endl;

    derived_int<int> d2;
    cout << "d2.g(4) = " << d2.g(4) << endl;

    derived<short> d3;
    // cout << "d3.g(4) = " << d3.g(4) << endl;
    
    base<int>::value_type i1;
    derived<int>::value_type i2;
    typename derived<int>::value_type i3;
 
    return 0;
}
  
 
