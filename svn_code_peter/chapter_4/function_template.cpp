#include <iostream>

using namespace std;

namespace ct {

    template <typename T>
    T maxi(T x, T y)
    {
	return x > y ? x : y;
    }

    template int maxi(int, int);

    inline long maxi(long x, long y)
    {
	return x > y ? x : y;
    }

    namespace {

	short maxi(short x, short y)
	{
	    return x > y ? x : y;
	}
	
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    cout << "maxi(3.1, 7.2) = " << maxi(3.1, 7.2) << endl;
    cout << "maxi(3, 7) = " << maxi(3, 7) << endl;
    cout << "maxi(3l, 7l) = " << maxi(3l, 7l) << endl;

    int i{7};
    double d{3.4};

    // cout << "maxi(i, d) = " << maxi(i, d) << endl;

    // cout << "maxi((double) i, d) = " << maxi((double) i, d) << endl;
    // cout << "maxi(i, d) = " << maxi(double(i), d) << endl;
    cout << "maxi(i, d) = " << maxi(static_cast<double>(i), d) << endl;

    cout << "maxi(i, d) = " << maxi<long double>(i, d) << endl;
    cout << "maxi(i, i) = " << maxi<long>(i, i) << endl;

    short s1{4}, s2{9};
    cout << "maxi(s1, s2) = " << maxi(s1, s2) << endl;
    
    return 0;
}
  
 
