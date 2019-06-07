#include <iostream>
#include <cassert>
#include <sstream>
#include <initializer_list>

using namespace std;

namespace sn {

    template <typename T>
    string to_string(const T& x)
    {
	ostringstream os;
	os << x;
	return os.str();
    }

#if 0
    template <typename First, typename ...Rest>
    string to_string(const First& f, const Rest& ...r)
    {
	return to_string(f) + ", " + to_string(r...);
    }

    // Benoetige Hilfsfunktion und Indirektion
    template <typename ...Args>
    string to_tuple_string(const Args& ...a)
    {
	return "(" + to_string(a...) + ")";
    }

    template <typename ...Args>
    void dummy(const Args& ...) {}
    
    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
	ostringstream os;
	os << "(" << f;
	// (os << ", " << r)...; // nur in Funktionsaufrufen und Initlisten
	// dummy((os << ", " << r)...);
	initializer_list<int> dummy [[maybe_unused]] = {(os << ", " << r, 0)...};
	os << ")";
	return os.str();
    }
#endif

    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
	return "(" + (to_string(f) + ... + (", " + to_string(r))) + ")";
    }
    
    // template <typename ...Args>
    // string to_tuple_string(const Args& ...a)
    // {
    // 	ostringstream os;
    // 	(os << ... << a);
    // 	return os.str();
    // }

    void f(int k, int j) { cout << "k = " << k << ", j = " << j << endl; } 
}


int main () 
{
    cout << sn::to_tuple_string(3) << endl;
    cout << sn::to_tuple_string(3, 3.7) << endl;
    cout << sn::to_tuple_string(3, 3.7, "huhu") << endl;
    
    // assert(sn::to_tuple_string(3) == "(3)");
    // assert(sn::to_tuple_string(3, 3.7) == "(3, 3.7)");
    // assert(sn::to_tuple_string(3, 3.7, "huhu"s) == "(3, 3.7, huhu)");

    // int i= 0;
    // sn::f(++i, ++i);

    // int k= 8;
    // cout << "--k / --k = " << --k / --k  << endl;
    
    return 0;
}

