#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

namespace le {

    int& fref() { static int i{9}; return i; }
    const int& cref() { static int i{9}; return i; }

    template <typename Container>
    void print_all98(const Container& c)
    {
	for (typename Container::const_iterator it= c.begin(); it != c.end(); ++it)
	    cout << *it << endl;
    }
    
    template <typename Container>
    void print_all11(const Container& c)
    {
	for (auto it= begin(c); it != end(c); ++it)
	    cout << *it << endl;
    }

    template <typename Container>
    void print_all_for(const Container& c)
    {
	for (auto&& value : c)
	    cout << value << endl;
    }
    
    template <typename Container>
    void print_all_da(const Container& c)
    {
	for (decltype(auto) value : c)
	    cout << value << endl;
    }

    // Return type auto since C++14
    // Always be a copy
    template <typename Container>
    auto first_entry_copy(Container& c) -> decltype(*begin(c))// const and mutable containers
    {
	return *begin(c);
    }
    
    // As it is
    template <typename Container>
    decltype(auto) first_entry_copy(Container& c) 
    {
	return *begin(c);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    // auto a0;

    auto a1= -7 + 3.7f + 9u - 2.6; // double

    auto a2= fref();               // int
    auto& a3= fref();              // int&
    const auto& a4= fref();        // const int&

    auto a5= cref();               // int (not const int)
    auto& a6= cref();              // const int& (auto -> const int)
    const auto& a7= cref();        // const int& (auto -> int)

    auto&& eight= 8;               // int&&
    eight= 4;
    cout << "eight = " << eight << endl;

    auto&& a9= fref();             // int&
    auto&& a10= cref();            // const int&
 
    decltype(cref()) a11= cref();  // const int&

    // C++14
    decltype(auto) a12= cref();    // types like decltype, used like auto (const int&)

    auto a13{3};
    auto a14= {3};
    auto a15({3, 4});
    auto a16= {3, 4};

    cout << "Type of a13 is " << typeid(a13).name() << endl;
    cout << "Type of a14 is " << typeid(a14).name() << endl;
    cout << "Type of a15 is " << typeid(a15).name() << endl;
    cout << "Type of a16 is " << typeid(a16).name() << endl;

    vector<int> v{{3, 4, 8, 9}};
    print_all98(v);
    print_all11(v);

    return 0;
}
  
 
