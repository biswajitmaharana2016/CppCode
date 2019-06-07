#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <memory>

using namespace std;


template <typename ...Args>
class const_vari{
    public:
    template< typename F, size_t ...I>
    void call_helper(F f,index_sequence<I...>){
        f(get<I>(para)...);

    }


    template <typename ...Args2>
    const_vari(Args2&& ...a):para{ forward<Args2>(a)... }
    {

    }
    template <typename F>
    void call(F f)
    {
        fun( get<0>(f), get<1>(f));
    } 
    template <typename F>
    void call(F f)
    {
        call_helper( f, make_index_sequence<sizeof ...(Args)>{});
    }
    tuple<Args...> para;
};

    void fun(int i, float f)
    {
            cout << " i:" << i << "f:" << f << endl;
    }

template<typename ...Args>
auto get_third(Args&& ...a )
{
    tuple<Args...> t {a...};
    return get<5>(t);

}
template <typename T> struct wrap {};
    
template <typename T>
void cp(T arg)
{
    cout << "T = " << typeid(T).name() << ", arg = "
	 << typeid(arg).name() << endl;
}
    
template <typename T>
void cr(const T& arg)
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
void pass(T&& arg)
{
    // fr(arg); // immer lvalue
    // fr(move(arg)); // immer rvalue
    fr(forward<T>(arg)); // rvalue-ref -> rvalue
}
struct s{ s( int a, int j,int k){}};
template <typename Target, typename ...Args>
std::unique_ptr<Target> our_make_unique(Args&& ...a)
{
    return std::unique_ptr<Target>{ new Target{ forward<Args>(a)... } };
}

template <typename T>
void rvalue_only1(T&& arg) { cout << "Yeah, ein rvalue.\n"; }

template <typename T>
void rvalue_only1(T&) = delete;

void double_only(double ) { cout << "Yeah, ein double.\n"; }

template <typename T> void double_only(T) = delete;

template <typename T>
void rvalue_only2(T&& arg)
{
    static_assert(is_rvalue_reference<decltype(arg)>::value,
		  "Nee, das ist ein lvalue.");
}


int main (int argc, char* argv[]) 
{


  const_vari<int, float> param{ 2,4.5};
  param.call(fun);
    cout <<" Tuple:" << get_third(2,3,4,5,4l, 6.55) <<std::endl;
    int        i{4};
    int&       r{i};
    const int& c{i};

    unique_ptr<s> temp = our_make_unique<s>(1,2,3);
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

    pass(3);
    pass(i);
    pass(r);
    pass(c);
    cout << endl;

    rvalue_only1(3);
    // rvalue_only1(i);
    // rvalue_only1(c);
 
    rvalue_only2(3);
    // rvalue_only2(i);
    // rvalue_only2(c);

    double_only(3.4);
    // double_only(4); // deleted function


    
    return 0;
}
  
 
