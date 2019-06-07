#include <iostream>

using namespace std;

namespace le {

    void f(unsigned) { cout << "unsigned\n"; }
    void f(unsigned*) { cout << "unsigned*\n"; }
    // void f(int) { cout << "int\n"; }
    
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    // f(0);
    f(0u);
    //f(NULL);
    f(nullptr);

    int* ip= nullptr;
    if (ip == nullptr)
	cout << "Yeah\n";

    return 0;
}
  
 
