#include <iostream>

using namespace std;

namespace le {

    template <typename T>
    struct base
    {
	using value_type= T;
	T f(T i) { return i * 3 + k; }
	T k{4};
    };

    template <typename T>
    struct derived : base<T>
    {
	T g(T i)
	{
	    typename base<T>::value_type j= 2 * i;
	    // j+= base<T>::k;
	    // return base<T>::f(j + 5);
	    j+= this->k;
	    return this->f(j + 5);
	}
    };
    

    template <typename T>
    struct derived_int : base<int>
    {
	T g(T i)
	{
	    value_type j= 2 * i;
	    j+= k;
	    return f(j + 5);
	}
    };

    // Who writes this, deserves being fired
    template <>
    struct base<short>
    {
    	int value_type() { return 3; }
    	short f{4};
    	using k= short;
    };

}

int main (int argc, char* argv[]) 
{
    using namespace le;

    derived_int<int> d1;
    cout << "d1.g(4) = " << d1.g(4) << endl;

    derived<int> d2;
    cout << "d2.g(4) = " << d2.g(4) << endl;

    derived<short> d3;
    // cout << "d3.g(4) = " << d3.g(4) << endl;

    derived<int>::value_type i4{4};
    
    return 0;
}
  
 
