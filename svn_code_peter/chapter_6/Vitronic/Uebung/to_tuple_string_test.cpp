#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

namespace ct {

    // Benoetigt Hilfsfunktion und Indirektion
    template <typename ...Args>
    string to_tuple_string(const Args& ...a)
    {
        //sizeof...(a);
        //sizeof...(Args);

    }

}


int main () 
{
    cout << ct::to_tuple_string(3) << endl;
    cout << ct::to_tuple_string(3, 3.7) << endl;
    cout << ct::to_tuple_string(3, 3.7, "huhu") << endl;
    
    assert(ct::to_tuple_string(3) == "(3)");
    assert(ct::to_tuple_string(3, 3.7) == "(3, 3.7)");
    assert(ct::to_tuple_string(3, 3.7, "huhu"s) == "(3, 3.7, huhu)");

    return 0;
}

