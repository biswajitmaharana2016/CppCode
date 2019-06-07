// unique_ptr_examples.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <memory>

using namespace std;

namespace vit {

    void f(unique_ptr<int> up) {} // loescht Speicher am Ende
}

int main(int argc, char** argv)
{
    using namespace vit;
    using ui = unique_ptr<int>;

    ui up0;
    if (up0 == nullptr)
        cout << "up0 ist tatsaechlich leer.\n";
    if (!up0)
        cout << "up0 ist tatsaechlich leer.\n";

    // keine implizite Konvertierung
    // ui up1 = new int{ 7 }; 
    ui up1{ new int{7} };
    cout << "up1 = " << *up1 << endl;

    // ui up2{ up1 };  kein Kopierkonstruktor

    ui up3{ move(up1) };
    cout << "up3 = " << *up3 << endl;
    if (!up1)
        cout << "up1 ist jetzt leer.\n";

    ui up4;
    // up4 = up3; // keine Kopierzuweisung
    up4 = move(up3); // Move-Zuweisung
    // up4.reset(up3.release());  // Move-Zuweisung umstaendlich

    cout << "up4 = " << *up4 << endl;
    if (!up3)
        cout << "up3 ist jetzt leer.\n";

    // ui up5(up4.get()); // zeigen auf selbe Adresse
    //int i;
    //ui up6{ &i };

    // ui up7{ new int[12] }; // falsches delete (braeuchten delete[] sein)
    unique_ptr<int[]> up7{ new int[12] };
    // *up7 = 999;
    up7[0] = 999;
    cout << "up7[0] = " << up7[0] << endl;

}

