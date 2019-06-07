#include <iostream>

using namespace std;

namespace sn {

    template <typename T>
    T maxi(T x, T y)
    {
	return x >= y ? x : y;
    }

    // template <typename T, typename U>
    // T maxi(T x, U y)
    // {
    // 	return x >= y ? x : y;
    // }

    // template int maxi<int>(int, int); // expl. Instanziierung
} 

int main (int argc, char* argv[]) 
{
    using namespace sn;

    cout << "maxi(3, 7) = " << maxi(3, 7) << endl;
    cout << "maxi(3u, 7u) = " << maxi(3u, 7u) << endl;
    cout << "maxi(3.1, 7.1) = " << maxi(3.1, 7.1) << endl;

    // cout << "maxi(3.1, 7) = " << maxi(3.1, 7) << endl;
    // cout << "maxi(3, 7.1) = " << maxi(3, 7.1) << endl;

    // cout << "maxi(3, 7.1) = " << maxi((double)3, 7.1) << endl; // bloss nicht 
    // cout << "maxi(3, 7.1) = " << maxi(double(3), 7.1) << endl; // Konstruktor bei Klassen, C-Cast sonst
    cout << "maxi(3, 7.1) = " << maxi(static_cast<double>(3), 7.1) << endl;

    cout << "maxi(3, 7.1) = " << maxi<long double>(3, 7.1) << endl;
    
    return 0;
}
  
 
