#include <iostream>

using namespace std;

namespace mv {

    template <typename T>
    T maxi(T x, T y)
    {
	return x >= y ? x : y;
    }

    inline int maxi(int x, int y) 
    {
    	return x >= y ? x : y;
    }

    // namespace {
    // 	inline int maxi(int x, int y) 
    // 	{
    // 	    return x >= y ? x : y;
    // 	}
    // }

    template short maxi<short>(short, short);
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    cout << "maxi(7, 3) = " << maxi(7, 3) << endl;
    cout << "maxi(7.1, 3.1) = " << maxi(7.1, 3.1) << endl;

    cout << "maxi(7, 13.1) = " << maxi(7, 13.1) << endl;
    cout << "maxi(7, 3.1) = " << maxi(static_cast<double>(7), 3.1) << endl;
    cout << "maxi(7, 3.1) = " << maxi<double>(7, 3.1) << endl;
    
    return 0;
}
  
 
