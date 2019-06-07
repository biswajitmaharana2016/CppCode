#include <iostream>
#include <cassert>
#include <sstream>
#include <initializer_list>

using namespace std;

namespace mv {

    template <typename T>
    string to_string(const T& x)
    {
	std::ostringstream os;
	os << x;
	return os.str();
    }

    template <typename First, typename ...Rest>
    string to_string(const First& f, const Rest& ...r)
    {
	return to_string(f) + ", " + to_string(r...);
    }

    // Benoetige Hilfsfunktion und Indirektion

#if 0
    template <typename ...Args>
    string to_tuple_string(const Args& ...a)
    {
	return "(" + to_string(a...) + ")";
    }

    template <typename ...Args>
    void dummy(Args& ...) {}

    template <typename First, typename ...Rest>
    string to_tuple_string(const First& f, const Rest& ...r)
    {
	std::ostringstream os;
	os << "(" << f;
	// dummy((os << ", " << r)...); // nicht portabel, abh. von Auswertungsreihenfolge
	initializer_list<int> dummylist [[maybe_unused]] = {((os << ", " << r), 0)...};
	os << ")";
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
	cout << "i = " << i << ", j = " << j << endl;
    }
}


int main () 
{
    cout << mv::to_tuple_string(3) << endl;
    cout << mv::to_tuple_string(3, 3.7) << endl;
    cout << mv::to_tuple_string(3, 3.7, "huhu") << endl;
    
    // assert(mv::to_tuple_string(3) == "(3)");
    // assert(mv::to_tuple_string(3, 3.7) == "(3, 3.7)");
    // assert(mv::to_tuple_string(3, 3.7, "huhu"s) == "(3, 3.7, huhu)");

    int i{0};
    mv::f(++i, ++i);
    
    return 0;
}

