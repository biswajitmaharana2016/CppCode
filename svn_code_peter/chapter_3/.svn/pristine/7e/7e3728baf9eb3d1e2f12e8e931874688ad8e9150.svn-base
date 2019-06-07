#include <iostream>

using namespace std;

namespace le {

    template <size_t N>
    struct fibonacci
    {
	static const size_t value= fibonacci<N-1>::value + fibonacci<N-2>::value;

    };

    template <>
    struct fibonacci<1>
    {
	static const size_t value= 1;
    };

    template <>
    struct fibonacci<2>
      : fibonacci<1> {};

    constexpr size_t fibo(size_t n)
    {
	return n < 2 ? n : fibo(n-1) + fibo(n-2);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    cout << "Fibonacci number 18 is " << fibonacci<18>::value << endl;
    cout << "Fibonacci number 19 is " << fibo(19) << endl; // might be computed at run time

    fibonacci<fibo(4)> ff4; // must be computed at compile time 

    constexpr size_t f20= fibo(20); // also computed at compile time 
    cout << "Fibonacci number 20 is " << fibo(20) << endl;

    int n{5};
    if (argc > 1)
	n= stoi(argv[1]);
    
    cout << "Fibonacci number " << n << " is " << fibo(n) << endl;

    // constexpr size_t fibon= fibo(n);

    const size_t c1{6 + 9};
    const int c2{6 + n};

    constexpr size_t fiboc1= fibo(c1);
    // constexpr size_t fiboc2= fibo(c2);

    
    return 0;
}
  
 
