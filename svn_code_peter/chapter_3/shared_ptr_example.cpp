#include <iostream>
#include <memory>

using namespace std;

namespace le {

    void f(shared_ptr<int> sp) {} // deletes memory 

    void array_delete(int* p) { delete[] p; }
    void no_delete(int*) {}
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    shared_ptr<int> sp0;
    if (sp0 == nullptr)
	cout << "sp0 is indeed a nullptr.\n";

    // shared_ptr<int> sp1= new int{4}; // Ctor explicit
    shared_ptr<int> sp1{ new int{4} };
    if (sp1)
	cout << "*sp1 = " << *sp1 << endl;

    shared_ptr<int> sp2{ sp1 };
    cout << "*sp2 = " << *sp2 << ", shared " << sp2.use_count() << " times.\n";

    shared_ptr<int> sp3{ move(sp2) };
    cout << "*sp3 = " << *sp3 << ", shared " << sp3.use_count() << " times.\n";
    if (sp2 == nullptr)
	cout << "sp2 is now a nullptr.\n";

    sp0= sp3;
    cout << "*sp0 = " << *sp0 << ", shared " << sp0.use_count() << " times.\n";

    shared_ptr<int> sp4{ new int{5} };
    cout << "*sp4 = " << *sp4 << ", shared " << sp4.use_count() << " times.\n";
    sp4= sp3;
    cout << "*sp4 = " << *sp4 << ", shared " << sp4.use_count() << " times.\n";

    // pointing to the same address, doesn't know about other pointers, should crash but doesn't for me
    // shared_ptr<int> sp5{ sp4.get() }; 
    // cout << "*sp5 = " << *sp5 << ", shared " << sp5.use_count() << " times.\n";

    // int i{9};
    // shared_ptr<int> sp6{ &i };

    shared_ptr<int> sp7{new int[12], array_delete};

    int* rp= new int{7};
    f(shared_ptr<int>{rp, no_delete});

    delete rp;

    shared_ptr<int> sp8= make_shared<int>(88);
    cout << "*sp8 = " << *sp8 << ", shared " << sp8.use_count() << " times.\n";
    
    return 0;
}
  
 
