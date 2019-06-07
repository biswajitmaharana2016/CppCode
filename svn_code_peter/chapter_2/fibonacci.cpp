#include <iostream>

using namespace std;

namespace sn {

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

    constexpr size_t fibo(size_t n) //constexpr call the onstexpr only but recurzively
    {
	return n < 2 ? n : fibo(n-1) + fibo(n-2);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    cout << "Fibonacci-Zahl 16 = " << fibonacci<16>::value << endl;
    cout << "Fibonacci-Zahl 15 = " << fibo(15) << endl;

    constexpr size_t f14= fibo(210);
    cout << "Fibonacci-Zahl 15 = " << f14 << endl;

    int i= 9;
    if (argc > 1)
	i= stoi(argv[1]);
    cout << "Fibonacci-Zahl " << i << " = " << fibo(i) << endl;

    const size_t fibo_i= fibo(i);
    // constexpr size_t fibo_i2= fibo(i);

    const size_t k= 4;

    fibonacci<fibo(4)> ff4;
    fibonacci<k>       fk;
    // fibonacci<fibo_i>  ffi;

    return 0;
}
  
 
