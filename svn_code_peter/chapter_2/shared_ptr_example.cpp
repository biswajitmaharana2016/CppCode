#include <iostream>
#include <memory>

using namespace std;

namespace sn {

    void f(shared_ptr<int> ) {}

    void loesche_nicht(int*) { cout << "Ich loesche nicht, nänänäh.\n"; }

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    shared_ptr<int> sp0;
    if (sp0 == nullptr)
	cout << "sp0 ist echt leer.\n";



    
    if (sp0)
	cout << "Da steht ja doch was drin.\n";

    shared_ptr<int> sp1{ new int{7} };
    cout << "Der Wert von sp1 ist " << *sp1 << endl;

    shared_ptr<int> sp2{sp1};
    cout << "Der Wert von sp2 ist " << *sp2 << "; " << sp2.use_count()
	 << " mal geteilt.\n";

    shared_ptr<int> sp3{move(sp1)};
    cout << "Der Wert von sp3 ist " << *sp3 << endl;

    if (sp1 == nullptr)
	cout << "sp1 ist nun leer.\n";

    sp0= sp3;
    cout << "Der Wert von sp0 ist " << *sp0 << "; " << sp0.use_count()
	 << " mal geteilt.\n";

#if 0
    sp1= move(sp3);
    // sp1.reset(sp3.release());
    cout << "Der Wert von sp1 ist " << *sp1 << endl;
    if (sp3 == nullptr)
	cout << "sp3 ist nun leer.\n";
#endif

    // Mutwillig kaputt gemacht:
    // shared_ptr<int> sp4{ sp3.get() }; // selbe Adresse sp1
    // cout << "Der Wert von sp4 ist " << *sp4 << "; " << sp4.use_count()
    // 	 << " mal geteilt." << endl;

    // int i= 9;
    // shared_ptr<int> sp5{ &i };  // versucht Adresse auf Stack zu loeschen

    int* ip= new int{11};
    // f(shared_ptr<int>{ ip }); // doppelt freigegeben
    f(shared_ptr<int>{ ip, &loesche_nicht } );

    delete ip;

    auto sp6= make_shared<int>(13);
    cout << "Der Wert von sp6 ist " << *sp6 << "; " << sp6.use_count()
	 << " mal geteilt.\n";
    
    
    return 0;
}
  
 
