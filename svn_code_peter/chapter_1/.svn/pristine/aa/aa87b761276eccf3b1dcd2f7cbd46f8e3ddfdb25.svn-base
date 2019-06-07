#include <iostream>
#include <vector>

using namespace std;

namespace mv {

    int& fref() { static int i= 3; return i; }
    int const& cref() { static int i= 3; return i; }

    template <typename Container>
    void print_all98(const Container& c)
    {
	for (typename Container::const_iterator it= c.begin(), e= c.end(); it != e; ++it)
	    cout << *it << endl;
    }
    
    template <typename Container>
    void print_all_auto(const Container& c)
    {
	for (auto it= c.begin(), e= c.end(); it != e; ++it)
	    cout << *it << endl;
    }

    template <typename Container>
    void print_all_for(const Container& c)
    {
	for (auto&& value : c)
	    cout << value << endl;
    }

    template <typename Container>
    auto first_entry_as_copy(Container& c)
    {
	if (c.empty()) throw "Alles Mist.";
	return *begin(c);
    }

    template <typename Container>
    decltype(auto) first_entry_as_is(Container& c)
    {
	if (c.empty()) throw "Alles Mist.";
	return *begin(c);
    }


    
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    vector<int> v{3, 9, 2, 7};
    print_all98(v);
    print_all_auto(v);

    
    
    // auto a0;
    auto a1= 3.7 + 3u - 4 * 5.1f; // double

    auto a2= fref(); // int, nicht int&
    auto& a3= fref(); // int&
    const auto& a4= fref(); // const int&

    auto a5= cref(); // int
    auto& a6= cref(); // const int& (auto -> const int)

    auto&& a7= fref(); // int& (auto -> int&)
    auto&& neun= 9;    // int&&
    neun= 4;
    cout << "neun = " << neun << endl;

    decltype(fref()) a8= fref();
    decltype(auto) a9= fref(); // Ab C++14: Typ wie decltype, Verwendung wie auto

    return 0;
}
  
 
