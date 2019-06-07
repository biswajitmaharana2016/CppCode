#include <iostream>
#include <memory>

using namespace std;

namespace ct {

    // schmeisst Speicher am Ende weg
    void f(shared_ptr<int> sp) {} 

    template <typename T>
    void aendere_das_blos_nicht(const T& x)
    {
	*x= 666;
    }

    void array_del(int* p) { delete[] p; }
    
    void dummy_del(int*) {  }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    shared_ptr<int> sp0;
    if (sp0 == nullptr)
	cout << "sp0 ist tatsaechlich leer.\n";

    if (!sp0)
	cout << "sp0 ist tatsaechlich leer.\n";

    shared_ptr<int> sp1{ new int{7} };
    cout << "*sp1 = " << *sp1 << endl;

    aendere_das_blos_nicht(sp1);
    cout << "*sp1 = " << *sp1 << endl;

    shared_ptr<int> sp2{sp1};
    cout << "*sp2 = " << *sp2 << ", " << sp2.use_count() << " mal geteilt.\n";

    shared_ptr<int> sp3{move(sp1)};
    if (!sp1)
	cout << "sp1 ist jetzt leer.\n";
    cout << "*sp3 = " << *sp3 << ", " << sp3.use_count() << " mal geteilt.\n";

    shared_ptr<int> sp4;

    sp4= sp3;
    cout << "*sp4 = " << *sp4 << ", " << sp4.use_count() << " mal geteilt.\n";
    cout << "*sp2 = " << *sp2 << ", " << sp2.use_count() << " mal geteilt.\n";
 
    sp4= move(sp3); 
    if (!sp3)
	cout << "sp3 ist jetzt leer.\n";
    cout << "*sp4 = " << *sp4 << ", " << sp4.use_count() << " mal geteilt.\n";


    // shared_ptr<int> sp5(sp4.get());
    // cout << "*sp5 = " << *sp5 << ", " << sp5.use_count() << " mal geteilt.\n";

    // sp5.reset();
    // cout << "*sp5 " << sp5.use_count() << " mal geteilt.\n";
    // cout << "*sp4 = " << *sp4 << ", " << sp4.use_count() << " mal geteilt.\n";
   

    // int i{4};
    // shared_ptr<int> sp6{&i};


    // shared_ptr<int> sp7{ new int[12] , array_del };
    shared_ptr<int[12]> sp7{ new int[12]  };
    sp7[0]= 14;
    // *sp7= 11;

    int* rp= new int{8};
    f(shared_ptr<int>{rp, dummy_del});
    f(shared_ptr<int>{rp, [](int*){}});

    delete rp;

    auto sp8= make_shared<int>(11);
    
    return 0;
}
  
 
