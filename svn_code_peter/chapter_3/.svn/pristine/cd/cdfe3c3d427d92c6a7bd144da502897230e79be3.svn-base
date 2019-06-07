#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <memory>

using namespace std;


template <typename T> struct wrap {};

template <typename T>
void cp(T arg)
{
    cout << "T = " << typeid(wrap<T>).name() << ", arg = "
	 << typeid(wrap<decltype(arg)>).name() << endl;
}

template <typename T>
void cr(T const& arg)
{
    cout << "T = " << typeid(wrap<T>).name() << ", arg = "
	 << typeid(wrap<decltype(arg)>).name() << endl;
}

template <typename T>
void mr(T& arg)
{
    cout << "T = " << typeid(wrap<T>).name() << ", arg = "
	 << typeid(wrap<decltype(arg)>).name() << endl;
}

template <typename T>
void fr(T&& arg)
{
    cout << "T = " << typeid(wrap<T>).name() << ", arg = "
	 << typeid(wrap<decltype(arg)>).name() << endl;
}

template <typename T>
void pass_on(T&& arg)
{
    // fr(arg); // always lvalue
    // fr(move(arg)); // always rvalue
    fr(forward<T>(arg));
}

template <typename Target, typename ...Args>
unique_ptr<Target> our_make_unique(Args&& ...args)
{
    return unique_ptr<Target>{ new Target{ forward<Args>(args)... } };
}

// rvalue
template <typename T>
void g(wrap<T>&&) {}

template <typename T>
void rvalue_only1(T&&) {}

template <typename T>
void rvalue_only1(T&) = delete;

void int_only(int) {}

template <typename T>
void int_only(T) = delete;

template <typename T>
void rvalue_only2(T&& arg)
{
    static_assert(is_rvalue_reference<decltype(arg)>::value,
		  "I don't work with variables!");
    static_assert(! is_lvalue_reference<T>::value,
		  "I don't work with variables!");
    
}
	    
int main (int argc, char* argv[]) 
{
    int        i{4};
    int&       r{i};
    int const& c{i};

    rvalue_only1(3);
    // rvalue_only1(i);

    int_only(3);
    // int_only(3.7);

    rvalue_only2(3);
    // rvalue_only2(i);
    
    cp(3);
    cp(i);
    cp(r);
    cp(c);
    cout << endl;

    cr(3);
    cr(i);
    cr(r);
    cr(c);
    cout << endl;

    // mr(3);
    mr(i);
    mr<int&>(i);
    mr<int&&>(i);
    mr(r);
    mr(c);
    cout << endl;
   
    fr(3);
    // fr<int&&>(3);
    fr(i);
    fr(r);
    fr(c);
    cout << endl;

    pass_on(3);
    pass_on(i);
    pass_on(r);
    pass_on(c);
    cout << endl;

    g(wrap<int>{});
    // wrap<int> wi;
    // g(wi);

    return 0;
}
  
 
