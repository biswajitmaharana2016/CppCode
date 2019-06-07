#include <iostream>
#include <memory>

using namespace std;

namespace ct {

    // schmeisst Speicher am Ende weg
    void f(unique_ptr<int> up) {} 

    template <typename T>
    void aendere_das_blos_nicht(const T& x)
    {
	*x= 666;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    unique_ptr<int> up0;
    if (up0 == nullptr)
	cout << "up0 ist tatsaechlich leer.\n";

    if (!up0)
	cout << "up0 ist tatsaechlich leer.\n";

    unique_ptr<int> up1{ new int{7} };
    cout << "*up1 = " << *up1 << endl;

    aendere_das_blos_nicht(up1);
    cout << "*up1 = " << *up1 << endl;

    // unique_ptr<int> up2{up1};

    unique_ptr<int> up3{move(up1)};
    if (!up1)
	cout << "up1 ist jetzt leer.\n";
    cout << "*up3 = " << *up3 << endl;

    unique_ptr<int> up4;

    // up4= up3;

    up4= move(up3);
    // up4.reset(up3.release());
    if (!up3)
	cout << "up3 ist jetzt leer.\n";
    cout << "*up4 = " << *up4 << endl;

    // unique_ptr<int> up5(up4.get());
    // cout << "*up5 = " << *up5 << endl;

    // int i{4};
    // unique_ptr<int> up6{&i};

    unique_ptr<int[]> up7{ new int[12] };
    up7[0]= 8;
    cout << "up7[0] = " << up7[0] << endl;
    
    return 0;
}
  
 
