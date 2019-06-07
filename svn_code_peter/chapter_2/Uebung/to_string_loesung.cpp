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
}


int main () 
{
    assert(sn::to_string(3) == "3");
    assert(sn::to_string(3.7) == "3.7");
    assert(sn::to_string("huhu") == string("huhu"));

    return 0;
}

