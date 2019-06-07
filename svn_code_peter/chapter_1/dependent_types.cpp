#include <iostream>

using namespace std;

namespace mv {

    template <typename T>
    struct base
    {
	using value_type= T;
	T f(T i) { return i + 3 + k; }
	T k{5};
    };

    struct untyp {};
    
    // Wer so etwas schreibt, gehoert gefeuert
    template <>
    struct base<short> 
    {
	using f= untyp;
	int value_type{4};
	using k= short;
    };
    
    template <typename T>
    struct derived_int : base<int>
    {
	T g(T i)
	{
	    value_type j= i + 3;
	    j+= k;
	    return f(j + 6);
	}
    };
    
    template <typename T>
    struct derived : base<T>
    {
	T g(T i)
	{
	    using vt= typename base<T>::value_type;
	    vt j= i + 3;
	    // j+= base<T>::k;
	    // return base<T>::f(j + 6);
	    j+= this->k;
	    return this->f(j + 6);
	}
    };
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    derived_int<int> d1;
    cout << "d1.g(4) = " << d1.g(4) << endl;

    derived<int> d2;
    cout << "d2.g(4) = " << d2.g(4) << endl;

    derived<short> d3;
    // cout << "d3.g(4) = " << d3.g(4) << endl;

    derived<int>::value_type i= 9;

    return 0;
}
  
 
