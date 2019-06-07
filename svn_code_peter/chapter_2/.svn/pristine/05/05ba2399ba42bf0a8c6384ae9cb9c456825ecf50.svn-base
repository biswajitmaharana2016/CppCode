#include <iostream>
#include <typeinfo>

using namespace std;

namespace sn {

    template <typename T>
    struct is_pointer
    {
	static constexpr bool value= false;
    };

    template <typename T>
    struct is_pointer<T*>
    {
	static constexpr bool value= true;
    };

    template <typename T>
    struct is_pointer<T const>
      : is_pointer<T> {};
    
    // Template-Var. ab C++14, solche Definitionen ab C++17
    template <typename T>
    constexpr bool is_pointer_v= is_pointer<T>::value;
    
    template <typename T>
    void print_is_pointer(T)
    {
	// cout << typeid(T).name() << " ist " << (is_pointer<T>::value ? "" : "k") << "ein Zeiger.\n";
	cout << typeid(T).name() << " ist " << (is_pointer_v<T> ? "" : "k") << "ein Zeiger.\n";
    }

    template <typename T>
    void pointer_only1(T)
    {
	static_assert(is_pointer_v<T>, "Nur fuer Zeiger, Du Trottel.");
	cout << "[1] Yeah, " <<  typeid(T).name() << " ist ein Zeiger.\n";
    }

    template <bool Condition, typename T= void>
    struct enable_if
    {
	using type= T;
    };

    template <typename T>
    struct enable_if<false, T>
    {};

    template <bool Condition, typename T= void>
    using enable_if_t= typename enable_if<Condition, T>::type;
    
    template <typename T>
    typename enable_if<is_pointer_v<T>, void>::type
    pointer_only2(T)
    {
	cout << "[2] Yeah, " <<  typeid(T).name() << " ist ein Zeiger.\n";
    }

    template <typename T>
    enable_if_t<is_pointer_v<T>> print_value1(T x)
    {
	cout << "Der Wert ist " << *x << ".\n";
    }
    
    template <typename T>
    enable_if_t<! is_pointer_v<T>> print_value1(T x)
    {
	cout << "Der Wert ist " << x << ".\n";
    }

    // wie std::integral_constant<bool, Value>
    template <bool Value>
    struct bool_constant
    {
	static constexpr bool value= Value;
    };

    using true_type= bool_constant<true>;
    using false_type= bool_constant<false>;
    
    template <typename T>
    void print_value2_dispatch(T x, true_type)
    {
	cout << "Der Wert ist " << *x << ".\n";
    }
    
    template <typename T>
    void print_value2_dispatch(T x, false_type)
    {
	cout << "Der Wert ist " << x << ".\n";
    }

    template <typename T>
    void print_value2(T x)
    {
	print_value2_dispatch(x, bool_constant<is_pointer_v<T>>{});
    }

    // Ab C++17
    template <typename T>
    void print_value3(T x)
    {
	if constexpr (is_pointer_v<T>)
	    cout << "Der Wert ist " << *x << ".\n";
	else
	    cout << "Der Wert ist " << x << ".\n";
    }

    template <typename T, size_t N>
    inline T* end(T (&array)[N])
    {
	return array + N;
    }

    template <typename C>
    auto end(C& c) -> decltype(c.end())
    {
	return c.end();
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    int i{4};
    print_is_pointer(i);
    print_is_pointer(&i);

    // pointer_only1(i);
    pointer_only1(&i);

    // pointer_only2(i);
    pointer_only2(&i);

    print_value1(i);
    print_value1(&i);

    print_value2(i);
    print_value2(&i);
    
    print_value3(i);
    print_value3(&i);
    
    return 0;
}
  
 
