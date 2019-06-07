#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

namespace sn {

    // Benoetige Hilfsfunktion und Indirektion

}


int main () 
{
    cout << sn::to_tuple_string(3) << endl;
    cout << sn::to_tuple_string(3, 3.7) << endl;
    cout << sn::to_tuple_string(3, 3.7, "huhu") << endl;
    
    assert(sn::to_tuple_string(3) == "(3)");
    assert(sn::to_tuple_string(3, 3.7) == "(3, 3.7)");
    assert(sn::to_tuple_string(3, 3.7, "huhu"s) == "(3, 3.7, huhu)");

    return 0;
}

