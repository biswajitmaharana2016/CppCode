#include <iostream>
#include <memory>

using namespace std;

namespace sn {

    void f(unique_ptr<int> ) {}

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    unique_ptr<int> up0;
    if (up0 == nullptr)
	cout << "up0 ist echt leer.\n";

    if (up0)
	cout << "Da steht ja doch was drin.\n";

    unique_ptr<int> up1{ new int{7} };
    cout << "Der Wert von up1 ist " << *up1 << endl;

    // unique_ptr<int> up2{up1};

    unique_ptr<int> up3{move(up1)};
    cout << "Der Wert von up3 ist " << *up3 << endl;

    if (up1 == nullptr)
	cout << "up1 ist nun leer.\n";

    // up0= up3;

    up1= move(up3);
    // up1.reset(up3.release());
    cout << "Der Wert von up1 ist " << *up1 << endl;
    if (up3 == nullptr)
	cout << "up3 ist nun leer.\n";

    // Mutwillig kapputt gemacht:
    // unique_ptr<int> up4{ up1.get() }; // selbe Adresse up1
    // cout << "Der Wert von up4 ist " << *up4 << endl;

    unique_ptr<int[]> up5{ new int[3]{4, 9, 7} };
    cout << "up5s erster Wert ist " << up5[0] << endl;

    unique_ptr<int[]> up6= make_unique<int[]>(9);
    
    return 0;
}
  
 
