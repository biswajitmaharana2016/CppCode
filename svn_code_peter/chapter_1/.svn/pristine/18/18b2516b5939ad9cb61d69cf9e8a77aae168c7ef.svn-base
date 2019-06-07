#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

namespace mv {

    // Benoetige Hilfsfunktion und Indirektion



}


int main () 
{
    cout << mv::to_tuple_string(3) << endl;
    cout << mv::to_tuple_string(3, 3.7) << endl;
    cout << mv::to_tuple_string(3, 3.7, "huhu") << endl;
    
    assert(mv::to_tuple_string(3) == "(3)");
    assert(mv::to_tuple_string(3, 3.7) == "(3, 3.7)");
    assert(mv::to_tuple_string(3, 3.7, "huhu"s) == "(3, 3.7, huhu)");

    return 0;
}

