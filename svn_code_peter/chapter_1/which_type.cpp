#include <iostream>
#include <typeinfo>
#include <memory>

using namespace std;

namespace mv {

    template <typename T> struct wrap {};

    template <typename T>
    void cp(T arg)
    {
	cout << "T = " << typeid(wrap<T>).name() << ", arg= "
	     << typeid(wrap<decltype(arg)>).name() << endl;
    }

    template <typename T>
    void cr(const T& arg)
    {
	cout << "T = " << typeid(wrap<T>).name() << ", arg= "
	     << typeid(wrap<decltype(arg)>).name() << endl;
    }

    template <typename T>
    void mr(T& arg)
    {
	cout << "T = " << typeid(wrap<T>).name() << ", arg= "
	     << typeid(wrap<decltype(arg)>).name() << endl;
    }

    template <typename T>
    void fr(T&& arg)
    {
	cout << "T = " << typeid(wrap<T>).name() << ", arg= "
	     << typeid(wrap<decltype(arg)>).name() << endl;
    }

    template <typename T>
    void pass_on(T&& arg)
    {
	// fr(arg); // immer lvalue
	// fr(move(arg));  // immer rvalue
	fr(forward<T>(arg));
    }

    // konstruiere unique_ptr<Target>, rufe Ktor Target(arg1, arg2, ...)
    template <typename Target, typename ...Args>
    std::unique_ptr<Target> our_make_unique(Args&& ...a)
    {
	return std::unique_ptr<Target>{ new Target{forward<Args>(a)...} };
    }

    template <typename T>
    void wraprr(wrap<T>&& w) {}

    template <typename T>
    void rvalue_only1(T&& arg) { cout << "rvalue\n"; }

    template <typename T>
    void rvalue_only1(T& arg) = delete;

    template <typename T>
    void rvalue_only2(T&& arg)
    {
	static_assert(is_rvalue_reference<decltype(arg)>::value,
		      "arg ist ein lvalue!!!");
    }

    void double_only(double) {}
    
    template <typename T>
    void double_only(T) = delete;
} 

int main (int argc, char* argv[]) 
{
    using namespace mv;

    double_only(3.1);
    // double_only(3);

    int  i{5};
    int& r{i};
    const int& c{i};

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
    fr(i);
    fr(r);
    fr(c);
    cout << endl;

    pass_on(3);
    pass_on(i);
    pass_on(r);
    pass_on(c);
    cout << endl;

    

    wraprr(wrap<int>{});
    wrap<int> w;
    // wraprr(w);

    rvalue_only1(3);
    // rvalue_only1(i);
    
    rvalue_only2(3);
    // rvalue_only2(i);
    
    return 0;
}
  
 
