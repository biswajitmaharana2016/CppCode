#include <iostream>
#include <string>
#include "irange.hpp"

using namespace std;

namespace sn {

}

int main (int argc, char* argv[]) 
{
    using namespace sn;
    string kurz{"kurzer String"};
    string lang{"laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String"};

    string s;
    s.reserve(200);
    for (int i : irange{0, 100}) {
	s+= 'i';
	cout << "Stringlaenge = " << s.size() << ", Kapazitaet = " << s.capacity() << endl;
    }
    s.shrink_to_fit();
    cout << "Stringlaenge = " << s.size() << ", Kapazitaet = " << s.capacity() << endl;
    
    return 0;
}
  
 
