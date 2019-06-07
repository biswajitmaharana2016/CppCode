#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <utility>

using namespace std;

namespace le {

    constexpr std::false_type is_a_matrix(...) { return {}; }

    template <typename T>
    constexpr bool is_matrix= decltype(is_a_matrix(declval<T>()))::value;

    template <typename T>
    void print_is_matrix(T)
    {
	cout << typeid(T).name() << " is " << (is_matrix<T> ? "" : "not ")
	     << "matrix.\n"; 
    }
    
    struct matrix {};
    struct sparse_matrix : matrix {};

    constexpr std::true_type is_a_matrix(const matrix&) { return {}; }

    struct florians_thingy
    {
	operator matrix() const { return matrix{}; }
    };
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    print_is_matrix(3);
    print_is_matrix(matrix{});
    print_is_matrix(sparse_matrix{});
    print_is_matrix(florians_thingy{});

    return 0;
}
  
 
