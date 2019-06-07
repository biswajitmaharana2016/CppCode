#include <iostream>
#include <utility>

using namespace std;

namespace mv {

    struct dings
    {
	double bums() { return 8.3; }

    };

    template <typename T>
    auto f(T x) -> decltype(x.bums())
    {
	using bt= decltype(declval<T>().bums());
	using bt2= decltype(x.bums());

    }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    return 0;
}
  
 
