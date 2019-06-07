#include <iostream>
#include <memory>

using namespace std;

namespace le {

    void f(unique_ptr<int> up) {} // deletes memory 

}

int main (int argc, char* argv[]) 
{
    using namespace le;

    unique_ptr<int> up0;
    if (up0 == nullptr)
	cout << "up0 is indeed a nullptr.\n";

    // unique_ptr<int> up1= new int{4}; // Ctor explicit
    unique_ptr<int> up1{ new int{4} };
    if (up1)
	cout << "*up1 = " << *up1 << endl;

    // unique_ptr<int> up2{ up1 };

    unique_ptr<int> up3{ move(up1) };
    cout << "*up3 = " << *up3 << endl;
    if (up1 == nullptr)
	cout << "up1 is now a nullptr.\n";

    // up0= up3;

    up0= move(up3);
    // up0.reset(up3.release());
    cout << "*up0 = " << *up0 << endl;
    if (up3 == nullptr)
	cout << "up3 is now a nullptr.\n";

    // pointing to the same address
    // unique_ptr<int> up4{ up0.get() }; 

    // int i{9};
    // unique_ptr<int> up5{ &i };
    
    unique_ptr<int[]> up6{ new int[12] };
    // *up6= 12;
    up6[0]= 12;

    unique_ptr<int> up7= make_unique<int>(9);

    int* rp= new int;
    delete rp;
    
    return 0;
}
  
 
