// shared_ptr_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <memory>

using namespace std;

namespace ct {

    void f(shared_ptr<int> sp) {}

    void array_del(int* p) { delete[] p; }
    void no_del(int*) {}
}

int main()
{
    using namespace ct;

    shared_ptr<int> sp0;
    if (sp0 == nullptr)
        cout << "sp0 ist tatsaechlich leer.\n";
    if (!sp0)
        cout << "sp0 ist tatsaechlich leer.\n";

    shared_ptr<int> sp1{ new int{ 4 } };
    cout << "*sp1 = " << *sp1 << endl;

    shared_ptr<int> sp2{ sp1 };
    cout << "*sp2 = " << *sp2 << ", Haeufigk.:" << sp2.use_count() << endl;

    {
        shared_ptr<int> sp2a{ sp1 };
        cout << "*sp2a = " << *sp2a << ", Haeufigk.:" << sp2a.use_count() << endl;
    }
    cout << "*sp2 = " << *sp2 << ", Haeufigk.:" << sp2.use_count() << endl;

    shared_ptr<int> sp3{ move(sp2) };
    cout << "*sp3 = " << *sp3 << ", Haeufigk.:" << sp3.use_count() << endl;
    if (!sp2)
        cout << "sp2 ist nun leer.\n";

     // selber schuld
     //shared_ptr<int> sp5{ sp3.get() };
     //
     //cout << "*sp5 = " << *sp5 << ", Haeufigk.:" << sp5.use_count() << endl;
     cout << "*sp3 = " << *sp3 << ", Haeufigk.:" << sp3.use_count() << endl;

     shared_ptr<int> sp6{ new int[12], array_del }; // mit delete[]

     int *ip = new int{ 7 };
     f(shared_ptr<int>{ip, no_del});

     delete ip;

     shared_ptr<int> sp7 = make_shared<int>();

     return 0;


}

