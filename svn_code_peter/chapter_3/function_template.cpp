#include <iostream>

using namespace std;

namespace le {

    template <typename T>
    T maxi(T x, T y)
    {
	return x > y ? x : y;
    }

    template long maxi(long x, long y);

    // inline int maxi(int x, int y)
    // {
    // 	return x > y ? x : y;
    // }
    
    namespace {
    
	int maxi(int x, int y)
	{
	    return x > y ? x : y;
	}

    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    cout << "maxi(3, 7) = " << maxi(3, 7) << endl;
    cout << "maxi(3.1, 7.1) = " << maxi(3.1, 7.1) << endl;
    cout << "maxi(3.1f, 7.1f) = " << maxi(3.1f, 7.1f) << endl;

    // cout << "maxi(3, 7.1) = " << maxi(3, 7.1) << endl;

    cout << "maxi(3, 7.1) = " << maxi((double) 3, 7.1) << endl; // C style, don't use
    cout << "maxi(3, 7.1) = " << maxi(double(3), 7.1) << endl;  // C style for intrinsics, Ctor for classes (and structs)
    cout << "maxi(3, 7.1) = " << maxi(static_cast<double>(3), 7.1) << endl; // recommended 

    cout << "maxi(3, 7.1) = " << maxi<long double>(3, 7.1) << endl;
    
    return 0;
}
  
 
