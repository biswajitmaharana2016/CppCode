#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

namespace le {

    template <typename Container>
    auto find_first_multiple(const Container& vi, decltype(*begin(vi)) i)
    {
	using vtype= decltype(*begin(vi));
	return find_if(begin(vi), end(vi), [i](vtype x){ return x % i == 0; });
    }
}

int main () 
{
    using namespace le;

    // vector<int> vi{3, 5, 4, 12, 15, 7, 9};
    int vi[]= {3, 5, 4, 12, 15, 7, 9};
    for (int i= 2; i < 10; ++i) {
	auto it= find_first_multiple(vi, i);
	if (it != end(vi))
	    cout << "The first multiple of " << i << " is " << *it << endl;
	else
	    cout << "There is no multiple of " << i << endl;
    }
        
    return 0;
}
  
 
