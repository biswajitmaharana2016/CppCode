#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

namespace mv {

    template <typename T>
    string to_string(const T& x)
    {
	std::ostringstream os;
	os << x;
	return os.str();
    }

}


int main () 
{
    assert(mv::to_string(3) == "3");
    assert(mv::to_string(3.7) == "3.7");
    assert(mv::to_string("huhu") == string("huhu"));

    return 0;
}

