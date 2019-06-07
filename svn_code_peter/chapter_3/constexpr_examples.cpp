#include <iostream>
#include <cmath>

using namespace std;

namespace le {

    constexpr double square(double x) { return x * x; }
    
    template <typename T>
    constexpr T square(T x) { return x * x; }

    constexpr bool is_prime(size_t n)
    {
	if (n == 1)
	    return false;
	if (n % 2 == 0)
	    return n == 2;
	size_t max_check= ceil(sqrt(n)); // only constexpr in g++, not in clang++
	for (size_t j= 3; j < max_check; j+= 2)
	    if (n % j == 0)
		return false;
	return true;
    }

    constexpr size_t popcount14(size_t n)
    {
	size_t res{0};
	for (; n != 0; ++res)
	    n&= n - 1; 
	return res;
    }

    constexpr size_t popcount11(size_t n)
    {
	return n == 0 ? 0 : popcount11(n & n-1) + 1;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    constexpr double sq37= square(3.7);
    constexpr float sq38= square(3.8f);

    constexpr bool it_is= is_prime(982'451'653);

    cout << "popcount14(0b1010'0010'1001) = " << popcount14(0b1010'0010'1001) << endl;
    cout << "popcount11(0b1010'0010'1001) = " << popcount11(0b1010'0010'1001) << endl;
    
    return 0;
}
  
 
