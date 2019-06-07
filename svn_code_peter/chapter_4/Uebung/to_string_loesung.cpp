#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

namespace ct {

    template <typename T>
    string to_string(const T& x)
    {
	ostringstream os;
	os << x;
	return os.str();
    }

}


int main () 
{
    cout << ct::to_string(3) << endl;
    cout << ct::to_string(3.7) << endl;
    cout << ct::to_string("huhu") << endl;

    assert(ct::to_string(3) == "3");
    assert(ct::to_string(3.7) == "3.7");
    assert(ct::to_string("huhu") == string("huhu"));

    return 0;
}

