#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

namespace sn {

    int& fref() { static int i{9}; return i; }
    const int& cref() { static int i{9}; return i; }

    template <typename C>
    void print_all98(const C& c)
    {
	for (typename C::const_iterator b= c.begin(); b != c.end(); ++b)
	    cout << *b << endl;
    }
    
    template <typename C>
    void print_all11(const C& c)
    {
	for (auto b= begin(c); b != end(c); ++b)
	    cout << *b << endl;
    }
    
    template <typename C>
    void print_all_for(const C& c)
    {
	for (auto&& v : c)
	    cout << v << endl;
    }
    
    // Ab C++14: auto fuer Rueckgabetypen

    // immer kopiert 
    template <typename C>
    auto first_entry_copy(C& c)
    {
	if (begin(c) == end(c))
	    throw std::out_of_range{"Leerer Container"};
	return *begin(c);
    }

    // gleicher Typ wie operator*
    template <typename C>
    decltype(auto) first_entry_as_is(C& c)
    {
	if (begin(c) == end(c))
	    throw std::out_of_range{"Leerer Container"};
	return *begin(c);
    }

    // gleicher Typ wie operator*
    template <typename C>
    auto first_entry_11(C& c) -> decltype(*begin(c))
    {
	if (begin(c) == end(c))
	    throw std::out_of_range{"Leerer Container"};
	return *begin(c);
    }
    
    
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    // auto a0; // Fehler: kein Wert zum Typbestimmen
    auto a1= 9u + 3.7f - 11 + 2.6; // double

    auto a2= fref();        // int
    auto& a3= fref();       // int&
    const auto& a4= fref(); // const int&

    auto a5= cref();        // int
    auto& a6= cref();       // const int&

    auto&& neun= 9;         // int&&
    neun= 3;
    cout << "neun = " << neun << endl;

    auto&& a7= fref();      // int&

    decltype(9u + 3.7f - 11 + 2.6) a1d= 9u + 3.7f - 11 + 2.6; // double
    decltype(fref())               a2d= fref();               // int&

    // C++14, decltype(auto): Typ wie decltype, Verwendung wie auto
    decltype(auto) a2da= fref(); // int&

    vector<int> vi{3, 9, 4, 8};
    print_all98(vi);
    cout << endl;

    print_all11(vi);
    cout << endl;

    print_all_for(vi);
    cout << endl;

    cout << "Erster Eintrag von vi ist " << first_entry_copy(vi) << endl;
    cout << "Erster Eintrag von vi ist " << first_entry_as_is(vi) << endl;

    return 0;
}
  
 
