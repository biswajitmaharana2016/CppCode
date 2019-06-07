#include <iostream>
#include <cmath>

using namespace std;

namespace sn {

    constexpr double square(double x) { return x * x; }

    template <typename T>
    constexpr T square(T x) { return x * x; }

    template <typename T>
    constexpr T power(T x, unsigned n)
    {
	T res{1};
	for (; n > 0; --n)
	    res*= x;
	return res;
    }

#if 0
    constexpr size_t popcount(size_t x)
    {
	size_t count{0};
	for (size_t mask{1}, i{0}; i < sizeof(size_t) * 8; ++i, mask<<= 1) 
	    if (x & mask)
		++count;
	return count;
    }
#endif

    constexpr size_t popcount(size_t x)
    {
	size_t count{0};
	for (; x != 0; ++count)
	    x&= x - 1;
	return count;
    }

    constexpr size_t popcount11(size_t x)
    {
	return x == 0 ? 0 : popcount(x & (x-1)) + 1;
    }

    constexpr bool is_prime(size_t i)
    {
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	size_t max_check= ceil(sqrt(i)) + 1; // nicht portabel, Funktionen in Clang nicht constexpr
	for (size_t j= 3; j < max_check; j+=2) 
	    if (i % j == 0)
		return false;
	return true;
    }

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    constexpr double sq37= square(3.7);
    constexpr float sq38= square(3.8f);
    constexpr int sq4= square(4);

    constexpr double p71_3= power(7.1, 3);
    cout << "7.1^3 = " << p71_3 << endl;

    cout << "popcount(0b1100'0100'0010) = " << popcount(0b1100'0100'0010) << endl;
    cout << "popcount11(0b1100'0100'0010) = " << popcount11(0b1100'0100'0010) << endl;

    constexpr bool is_large_prime= is_prime(982'451'653);
    
    return 0;
}
  
 
