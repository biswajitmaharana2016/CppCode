// shared_ptr_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.


#include "pch.h"
#include <iostream>
#include <memory>

using namespace std;

namespace vit {

    void f(shared_ptr<int> sp) {} // loescht Speicher am Ende

    void nodelete(int*) {}
}

int main(int argc, char** argv)
{
    using namespace vit;
    using si = shared_ptr<int>;

    si sp0;
    if (sp0 == nullptr)
        cout << "sp0 ist tatsaechlich leer.\n";
    if (!sp0)
        cout << "sp0 ist tatsaechlich leer.\n";

    // keine implizite Konvertierung
    // si sp1 = new int{ 7 }; 
    si sp1{ new int{7} };
    cout << "sp1 = " << *sp1 << endl;

    si sp2{ sp1 };  // Kopierkonstruktor
    cout << "sp2 = " << *sp2 << ", (" << sp2.use_count() << " mal geteilt).\n";

    si sp3{ move(sp2) };
    cout << "sp3 = " << *sp3 << ", (" << sp3.use_count() << " mal geteilt).\n";
    if (!sp2)
        cout << "sp2 ist jetzt leer.\n";


    si sp4, sp4m;
    sp4 = sp3; // Kopierzuweisung
    cout << "sp4 = " << *sp4 << ", (" << sp4.use_count() << " mal geteilt).\n";

    sp4m = move(sp3); // Move-Zuweisung
    cout << "sp4m = " << *sp4m << ", (" << sp4m.use_count() << " mal geteilt).\n";
    if (!sp3)
        cout << "sp3 ist jetzt leer.\n";

    //si sp5(sp4.get()); // zeigen auf selbe Adresse
    //cout << "sp4m = " << *sp4m << ", (" << sp4m.use_count() << " mal geteilt).\n";
    //cout << "sp5 = " << *sp5 << ", (" << sp5.use_count() << " mal geteilt).\n";

    //int i;
    //si sp6{ &i };

    // ui sp7{ new int[12] }; // falsches delete (braeuchten delete[] sein)
    shared_ptr<int[]> sp7{ new int[12] };
    // *sp7 = 999;
    sp7[0] = 999;
    cout << "sp7[0] = " << sp7[0] << endl;

    int* ip = new int{ 9 };
    // f(shared_ptr<int>{ip}); // gibt Speicher von ip frei
    f(shared_ptr<int>{ip, nodelete}); // gibt Speicher von ip nicht frei

    delete ip;
    cout << "Hab's ueberlebt!\n";

    si sp8 = make_shared<int>(9);
}
