#include <iostream>
#include <type_traits>

using namespace std;

namespace le {

    template <typename T>
    T sum(T x) { return x; }

    // Template alias since C++11, this one like common_type_t from C++14
    template <typename ...Args>
    using ct= typename common_type<Args...>::type;
    
    template <typename First, typename ...Rest>
    // First // simple but crappy
    // typename common_type<First, Rest...>::type // C++11
    // ct<First, Rest...>
    auto // C++14
    sum(First f, Rest ...r)
    {
	return f + sum(r...);
    }

    // C++17: folding
    // Like sum: right-associative, without identity element
    template <typename ...Args>
    auto sumr(Args ...a)
    {
	return (a + ...);
    }

    // right-associative, with identity element
    template <typename ...Args>
    auto sumr0(Args ...a)
    {
	return (a + ... + 0);
    }

    // left-associative, without identity element
    template <typename ...Args>
    auto suml(Args ...a)
    {
	return (... + a);
    }

    // left-associative, with identity element
    template <typename ...Args>
    auto suml0(Args ...a)
    {
	return (0 + ... + a);
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    cout << "sum(9u, -2.6) = " << sum(9u, -2.6) << endl;
    cout << "sum(3.7f, 9u, -2.6) = " << sum(3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -2.6) = " << sum(-7, 3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -42.6) = " << sum(-7, 3.7f, 9u, -42.6) << endl;

    cout << "sumr(-7, 3.7f, 9u, -42.6) = " << sumr(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0(-7, 3.7f, 9u, -42.6) = " << sumr0(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0() = " << sumr0() << endl;

    cout << "suml(-7, 3.7f, 9u, -42.6) = " << suml(-7, 3.7f, 9u, -42.6) << endl;
    cout << "suml0(-7, 3.7f, 9u, -42.6) = " << suml0(-7, 3.7f, 9u, -42.6) << endl;
    cout << "suml0() = " << suml0() << endl;

    cout << "suml(1.0, -1.0, 1e-20) = " << suml(1.0, -1.0, 1e-20) << endl;
    cout << "sumr(1.0, -1.0, 1e-20) = " << sumr(1.0, -1.0, 1e-20) << endl;

    cout << "3ul + -7 = " << -7 + 3ul << endl;
    cout << "3u + -7 = " << 3u + -7 << endl;
    
    return 0;
}
  
 
