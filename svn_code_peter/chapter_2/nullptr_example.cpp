#include <iostream>

using namespace std;

namespace sn {

    void f(unsigned) { cout << "unsigned\n"; }
    void f(int*) { cout << "int*\n"; }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    // f(0); // mehrdeutig
    // f(NULL); nicht besser
    f(0u);
    f(nullptr);

    int* p= nullptr;
    if (p == nullptr)
	cout << "p ist tatsaechlich ein Nullzeiger.\n";

    
    return 0;
}
  
 
