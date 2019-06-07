#include <iostream>
#include <type_traits>
#include <tuple>

using namespace std;

namespace mv {

    template <typename T> T sum(T x) { return x; }

    // wie common_type_t in C++14
    template <typename ...Args>
    using ct= typename common_type<Args...>::type;

    template <typename First, typename ...Rest>
    // First // einfach, aber Mist
    // typename common_type<First, Rest...>::type // C++11
    // ct<First, Rest...>
    auto // C++14
    sum(First f, Rest ...r)
    {
	return f + sum(r...);
    }

    template <typename First, typename ...Rest>
    ct<First, Rest...> sum2(First f, Rest ...r)
    {
	if constexpr (sizeof...(r) > 0) { // C++17, wertet Ausdruck zur Compile-Time aus
	    tuple<Rest...> rt{r...};
	    if constexpr (sizeof...(r) > 2)
		cout << get<2>(rt) << endl;
	    return f + sum2(r...);      // nur instanziiert, wenn Ausdruck wahr
	} else
	    return f;                   // nur instanziiert, wenn Ausdruck falsch
    }

    // wie sum und sum2, d.h. rechts-assoziativ ohne Einheitselement
    template <typename ...Args>
    auto sumr(Args ...args)
    {
	return (args + ...); 
    } 
     
    // rechts-assoziativ mit Einheitselement
    template <typename ...Args>
    auto sumr0(Args ...args)
    {
	return (args + ... + 0);
    }
    
    // links-assoziativ ohne Einheitselement
    template <typename ...Args>
    auto suml(Args ...args)
    {
	return (... + args); 
    } 
     
    // links-assoziativ mit Einheitselement
    template <typename ...Args>
    auto suml0(Args ...args)
    {
	return (0 + ... + args); 
    } 
     
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    cout << "sum(-7) = " << sum(-7) << endl;
    cout << "sum(-7, 3.7f) = " << sum(-7, 3.7f) << endl;
    cout << "sum(-7, 3.7f, 9u) = " << sum(-7, 3.7f, 9u) << endl;
    cout << "sum(-7, 3.7f, 9u, -2.6) = " << sum(-7, 3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -4) = " << sum(-7, 3.7f, 9u, short(-4)) << endl;

    cout << -49 + 42ull << endl;
    
    cout << "sum2(-7, 3.7f, 9u, -2.6) = " << sum2(-7, 3.7f, 9u, -2.6) << endl;

    if constexpr (sizeof(int) > 2)
	cout << "gross genug.\n";

    cout << "sumr(-7, 3.7f, 9u, -2.6) = " << sumr(-7, 3.7f, 9u, -2.6) << endl;
    cout << "sumr0(-7, 3.7f, 9u, -2.6) = " << sumr0(-7, 3.7f, 9u, -2.6) << endl;
    

    return 0;
}
  
 
