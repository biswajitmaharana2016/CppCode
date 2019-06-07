#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

namespace sn {

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    vector<int> v{9, 3, 4, 7};
    cout << "Kapazitaet = " << v.capacity() << endl;
    v.push_back(8);
    cout << "Kapazitaet = " << v.capacity() << endl;

    auto it4= find(begin(v), end(v), 4);
    cout << "*it4 = " << *it4 << endl;
    v.push_back(11);
    cout << "*it4 = " << *it4 << endl;
    v.insert(begin(v), 12);
    cout << "*it4 = " << *it4 << endl;

    list<int> l{9, 3, 4, 7};
    auto itl4= find(begin(l), end(l), 4);
    cout << "*itl4 = " << *itl4 << endl;
    l.push_back(11);
    cout << "*itl4 = " << *itl4 << endl;
    l.insert(begin(l), 12);
    cout << "*itl4 = " << *itl4 << endl;

    return 0;
}
  
 
