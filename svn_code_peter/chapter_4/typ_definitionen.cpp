#include <iostream>

using namespace std;

namespace ct {

    
    typedef int value_type;
    typedef int array_type[15];
    typedef int (*fpointer)(int, double);


    using value_type2= int;
    using array_type2= int[15];
    using fpointer2= int (*)(int, double);

    template <typename T>
    using zeiger= T*;

    // zeiger<int> wird substituiert zu int*;
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;


    return 0;
}
  
 
