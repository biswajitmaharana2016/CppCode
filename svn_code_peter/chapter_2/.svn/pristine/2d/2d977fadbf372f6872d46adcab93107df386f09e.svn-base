#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

namespace sn {

    struct unbeweglich
    {
	explicit unbeweglich(int i) : i{i} {}
	unbeweglich(const unbeweglich&) = delete;
	unbeweglich(unbeweglich&&) = delete;
	int i;
    };

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    vector<unbeweglich> vu;
    // vector<unbeweglich> vu{ unbeweglich{1}, unbeweglich{2} };
    // vu.push_back(unbeweglich{3});
    // vu.emplace_back(unbeweglich{3});

    deque<unbeweglich> du;
    // du.push_back(unbeweglich{3});
    du.emplace_back(3);
    du.emplace_front(2);
    for (unbeweglich& u : du)
	cout << "Mein Wert ist " << u.i << endl;

    array<int, 5> ai{{4, 3, 9, 1, 8}};

    array<unbeweglich, 2> au{{ unbeweglich{1}, unbeweglich{2} }};
    
    return 0;
}
  
 
