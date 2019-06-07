#include <iostream>
#include <type_traits>

using namespace std;

namespace ct {

    int sum() { return 0; }
    
    template <typename T> T sum(T x) { return x; }

    // Template Alias ab C++11
    // Genutzt in type_traits ab C++14 als common_type_t
    template <typename ...Args>
    using common= typename common_type<Args...>::type;
    
    template <typename First, typename ...Rest>
    // First // Schrott
    // typename common_type<First, Rest...>::type
    // common<First, Rest...>
    auto // C++14
    sum(First f, Rest ...r)
    {
	return f + sum(r...);
    }

    // C++17: Faltungsausdruecke

    // wie sum: rechtsassoziativ (faengt mit letztem Summanden an)
    // und ohne Einheitselement
    template <typename ...Args>
    auto sumr(Args ...a)
    {
	return (a + ...); // a[0] + (a[1] + (a[2] +  ... a[n]))
    }
    
    // rechtsassoziativ, mit Einheitselement
    template <typename ...Args>
    auto sumr0(Args ...a)
    {
	return (a + ... + 0); // a[0] + (a[1] + (a[2] +  ... (a[n] + 0)))
    }

    // linksassoziativ und ohne Einheitselement
    template <typename ...Args>
    auto suml(Args ...a)
    {
	return (... + a); // ((a[0] + a[1]) + a[2]) + ... a[n]
    }
   
    // linksassoziativ, mit Einheitselement
    template <typename ...Args>
    auto suml0(Args ...a)
    {
	cout << "suml0 mit " << sizeof...(Args) << " Argumenten aufgerufen.\n"; // C++11
	return (0 + ... + a); // ((a[0] + a[1]) + a[2]) + ... a[n]
    }
   
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    cout << "sum(9u, -2.6) = " << sum(9u, -2.6) << endl;
    cout << "sum(3.7f, 9u, -2.6) = " << sum(3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -2.6) = " << sum(-7, 3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -42.6) = " << sum(-7, 3.7f, 9u, -42.6) << endl;

    cout << "sumr(-7, 3.7f, 9u, -42.6) = " << sumr(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0() = " << sumr0() << endl;

    cout << "suml(1.0, -1.0, 1e-20) = " << suml(1.0, -1.0, 1e-20) << endl;
    cout << "sumr(1.0, -1.0, 1e-20) = " << sumr(1.0, -1.0, 1e-20) << endl;
    
    suml0(1.0, -1.0, 1e-20);
    
    return 0;
}
  
 
