#include <iostream>
#include <vector>

using namespace std;

namespace ct {

    int& fref() { static int i{4}; return i; }
    const int& cref() { static int i{4}; return i; }

    template <typename Container>
    void print_all98(Container const& c)
    {
	for (typename Container::const_iterator it= c.begin(); it != c.end(); ++it)
	    cout << *it << endl;
    }
    
    template <typename Container>
    void print_all11(Container const& c)
    {
	for (auto it= begin(c); it != end(c); ++it)
	    cout << *it << endl;
    }

    template <typename Container>
    void print_all_auto_for(Container const& c)
    {
	// for (auto value : c) // immer eine Kopie
	for (auto&& value : c)  // lvalue- oder rvalue-Reference
	    cout << value << endl;
    }

    template <typename Container>
    auto first_entry11(Container& c) -> decltype(*begin(c))
    {
	return *begin(c);
    }

    // C++14
    // immer Kopie
    template <typename Container>
    auto first_entry_as_copy(Container& c)
    {
	return *begin(c);
    }

    // gleicher Typ wie von operator*, mit & und const
    template <typename Container>
    decltype(auto) first_entry_as_is(Container& c)
    {
	return *begin(c);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // auto a0;

    auto a1= 9u + 3.7f - 9 * 4.2;    // double

    auto a2= fref();                 // int
    auto& a3= fref();                // int&
    const auto& a4= fref();          // const int&

    auto a5= cref();                 // int
    auto& a6= cref();                // const int& (auto mit const int substituiert)

    auto&& drei= 3;                  // int&&
    drei= 4;
    cout << "drei = " << drei << endl;

    auto&& a7= fref();               // int&

    print_all98(vector<int>{3, 9, 4, 8});
    print_all11(vector<int>{3, 9, 4, 8});

    decltype(9u + 3.7f - 9 * 4.2) a8=  9u + 3.7f - 9 * 4.2; // double
    decltype(fref()) a9= fref();                            // int&

    // C++14
    decltype(auto) a10= fref();     // Typ wie decltype, verwendet wie auto
    
    return 0;
}
  
 
