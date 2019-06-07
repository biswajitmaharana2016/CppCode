#include <iostream>
#include <cassert>
#include <sstream>

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
    void dummy_f(const Args& ...) {}
    
    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
	ostringstream os;
	os << "(" << f;
	// dummy_f((os << ", "<< r)...); // order compiler-dependent
	initializer_list<int> dummy [[maybe_unused]] = {(os << ", "<< r, 0)...};
	os << ')';
	return os.str();
    }

    // Eric's solution
    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
	ostringstream os;
	os << "(" << f;
	((os << ", " << r) , ...);
	os << ')';
	return os.str();
    }
#endif

    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
	return "(" + (to_string(f) + ... + (", " + to_string(r))) + ")";
    }
    
    
    void f(int i, int j)
    {
	cout << i << ", " << j << endl;
    }
}


int main () 
{
    cout << sn::to_tuple_string(3) << endl;
    cout << sn::to_tuple_string(3, 3.7) << endl;
    cout << sn::to_tuple_string(3, 3.7, "huhu") << endl;
    
    // assert(sn::to_tuple_string(3) == "(3)");
    // assert(sn::to_tuple_string(3, 3.7) == "(3, 3.7)");
    // assert(sn::to_tuple_string(3, 3.7, "huhu"s) == "(3, 3.7, huhu)");

    int i{0};
    sn::f(++i, ++i); // compiler-dependent

    cout << ++i - ++i << endl; // compiler-dependent

    return 0;
}

