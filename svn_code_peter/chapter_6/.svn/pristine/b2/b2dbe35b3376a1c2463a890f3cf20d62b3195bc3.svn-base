// nullptr_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

namespace ct {

    void f(unsigned) { cout << "unsigned\n"; }
    void f(int*) { cout << "Zeiger\n"; }

}

int main()
{
    using namespace ct;

    // f(0);
    // f(NULL);
    f(0u);
    f(nullptr);

    int* ip = nullptr;
    if (ip == nullptr)
        cout << "ip ist tatsaechlich leer\n";
}
