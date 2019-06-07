#include <iostream>
#include <typeinfo>
#include <type_traits>

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
    // fr(arg); // immer lvalue
    // fr(move(arg)); // immer rvalue
    fr(forward<T>(arg));
}

// Args sind Konstruktorargumente
template <typename Target, typename ...Args>
Target* make_pointer(Args&& ...a)
{
    return new Target{forward<Args>(a)...};
}

template <typename T>
void rvalue_only1(T&& )
{   cout << "Ein rvalue.\n"; }

template <typename T>
void rvalue_only1(T&) = delete;

void int_only(int) {}

template <typename T> void int_only(T) = delete;

template <typename T>
void rvalue_only2(T&& arg)
{
    static_assert(is_rvalue_reference_v<decltype(arg)>,
		  "Nur fuer rvalues");
    cout << "Yeah, ein rvalue.\n";
}

int main (int argc, char* argv[]) 
{
    int        i{3};
    int&       r{i};
    const int& c{i};

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

    return 0;
}
  
 
