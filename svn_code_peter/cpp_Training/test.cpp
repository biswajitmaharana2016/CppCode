#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace ct {
    

    
    template<typename Container>
    auto find_first_multiple(Container&& c, int s)
    {
        auto check = [s](int x){ return ((x%s) == 0 );};
        return find_if(begin(c) , end(c), check);
    }
}

int main ()
{
    using namespace ct;

    //vector<int> vi{3, 5, 4, 12, 15, 7, 9};
    int vi[]= {3, 5, 4, 12, 15, 7, 9};
    for (int i= 2; i < 10; ++i) {
        auto it= find_first_multiple(vi, i);
        if ( it != end(vi) )
            cout << "The first multiple of " << i << " is " << *it << endl;
        else
            cout << "There is no multiple of " << i << endl;
    }

    return 0;
}
