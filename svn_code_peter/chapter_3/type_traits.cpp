#include <iostream>
#include <typeinfo>
#include <utility>

using namespace std;

namespace le {

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
    void print_is_pointer(T)
    {
	cout << typeid(T).name() << " is " << (is_pointer<T>::value ? "" : "not ")
	     << "pointer.\n"; 
    }
    template <typename T>
    void print_is_pointer_const(const T)
    {
	cout << typeid(T).name() << " is " << (is_pointer<T>::value ? "" : "not ")
	     << "pointer.\n"; 
    }

    // Template variables since C++14, for type traits used since C++17
    template <typename T>
    constexpr bool is_pointer_v= is_pointer<T>::value;
    
    template <typename T>
    void print_is_pointer2(T)
    {
	cout << typeid(T).name() << " is " << (is_pointer_v<T> ? "" : "not ")
	     << "pointer.\n"; 
    }
    
    template <typename T>
    void pointer_only1(T)
    {
	static_assert(is_pointer_v<T>, "This isn't a pointer.");
	cout << "Yeah, it is a pointer.\n";
    }

    template <bool Condition, typename T= void>
    struct enable_if
    {
	using type= T;
    };

    template <typename T>
    struct enable_if<false, T>
    {};

    template <typename T>
    typename enable_if<is_pointer_v<T>, void>::type
    pointer_only2(T)
    {
	cout << "Yeah, it is a pointer.\n";
    }

    // Template aliases since C++11, for type traits used since C++14
    template <bool Condition, typename T= void>
    using enable_if_t= typename enable_if<Condition, T>::type;

    template <typename T>
    enable_if_t<is_pointer_v<T>>
    pointer_only3(T)
    {
	cout << "Yeah, it is a pointer.\n";
    }

    template <typename T, typename = enable_if_t<is_pointer_v<T>>>
    void pointer_only4(T)
    {
	cout << "Yeah, it is a pointer.\n";
    }

    template <typename T>
    enable_if_t<is_pointer_v<T>>
    print_value1(T x)
    {
	cout << "The value is " << *x << endl;
    }
    
    template <typename T>
    enable_if_t<! is_pointer_v<T>>
    print_value1(T x)
    {
	cout << "The value is " << x << endl;
    }

    // like integral_constant<bool, Value>
    template <bool Value>
    struct bool_constant {};

    using true_type= bool_constant<true>; // in standard integral_constant<bool, true>
    using false_type= bool_constant<false>;

    
    template <typename T>
    void print_value2_dispatch(T x, true_type)
    {
	cout << "The value is " << *x << endl;
    }
    
    template <typename T>
    void print_value2_dispatch(T x, false_type)
    {
	cout << "The value is " << x << endl;
    }

    template <typename T>
    void print_value2(T x)
    {
	print_value2_dispatch(x, bool_constant<is_pointer_v<T>>{});
    }

    // C++17
    template <typename T>
    void print_value3(T x)
    {
	if constexpr (is_pointer_v<T>) 
	    cout << "The value is " << *x << endl;
	else
	    cout << "The value is " << x << endl;
    }

    template <bool Condition, typename ThenType, typename ElseType>
    struct conditional
    {
	using type= ThenType;
    };
    
    template <typename ThenType, typename ElseType>
    struct conditional<false, ThenType, ElseType>
    {
	using type= ElseType;
    };

    template <typename T, size_t N>
    T* end(T (&array)[N])
    {
	return array + N;
    }

    template <typename Container>
    auto end(Container& c) -> decltype(c.end())
    {
	return c.end();
    }
    struct Veh{};
    struct car : Veh {};
    template< typename T >
    struct is_vehicle : false_type{};
    template< >
    struct is_vehicle<Veh> : false_type{};
    template< typename T > 
    constexpr false_type is_vehicle_(T) { return {};}
     
    constexpr true_type is_vehicle_(const Veh &) { return {};}
    template<typename T>
    constexpr  bool is_a_vehicle_ = decltype(is_vehicle_(declval<T>()));

    template <typename T>
    void print_is_vehicle(T)
    {
	cout << typeid(T).name() << " is " << (is_a_vehicle_<T> ? "" : "not ")
	     << "vehicle.\n"; 
    }

}

int main (int argc, char* argv[]) 
{
    using namespace le;

    int i{3};
    const int * const p = &i;
    print_is_pointer(p);

    print_is_pointer(i);
    print_is_pointer(&i);

    print_is_pointer2(i);
    print_is_pointer2(&i);

    // pointer_only1(i);
    pointer_only1(&i);

    // pointer_only2(i);
    pointer_only2(&i);

    // pointer_only3(i);
    pointer_only3(&i);

    // pointer_only4(i);
    pointer_only4(&i);

    print_value1(i);
    print_value1(&i);

    print_value2(i);
    print_value2(&i);

    print_value3(i);
    print_value3(&i);

    car ob;
    print_is_vehicle(ob);

    return 0;
}
  
 
