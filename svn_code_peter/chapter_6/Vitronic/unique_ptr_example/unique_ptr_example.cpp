// unique_ptr_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <memory>

using namespace std;

namespace ct {

    void f(unique_ptr<int> up)  {}

}

int main()
{
    using namespace ct;

    unique_ptr<int> up0;
    if (up0 == nullptr)
        cout << "up0 ist tatsaechlich leer.\n";
    if (! up0)
        cout << "up0 ist tatsaechlich leer.\n";

    unique_ptr<int> up1{ new int{ 4 } };
    cout << "*up1 = " << *up1 << endl;

    // unique_ptr<int> up2{ up1 };

    unique_ptr<int> up3{ move(up1) };
    cout << "*up3 = " << *up3 << endl;
    if (!up1)
        cout << "up1 ist nun leer.\n";

    unique_ptr<int> up4;
    // up4 = up3;

    //up4.reset(up3.release());
    up4 = move(up3);
    cout << "*up4 = " << *up4 << endl;
    if (!up3)
        cout << "up3 ist nun leer.\n";

    // selber schuld
    // unique_ptr<int> up5{ up4.get() };
    // up4.release();

    //int i{ 4 };
    //unique_ptr<int> up6{ &i };

    unique_ptr<int[]> up7{ new int[12] };
    // *up7 = 11;
    up7[0] = 11;
    cout << "up7[0] = " << up7[0] << endl;
}   
