#include <iostream>
#include <memory>
#include <exception>
#include <cassert>
#include <initializer_list>
#include <utility>

// Stack-Implementierung mit int*
// und Kopie
// mit Initializer-Liste

/*
Schreiben Sie eine Stack-Implementierung für eine generische Wertart. 
Die maximale Größe des Stacks wird Konstruktor übergeben. 

Stellen Sie die folgenden Funktionen zur Verfügung:
* Konstruktoren;
* Destruktor;
* Zuweisungsoperatoren;
* top: zeige letztes Element (ohne es zu entfernen);
* pop: entferne letztes Element (ohne es zurückzugeben); 
* push: füge neues Element ein;
* clear: lösche alle Einträge;
* size: Anzahl der Elemente im Stack;
* full: ob der Stack voll ist;
* empty: ob der Stack leer ist;
* capacity: Anzahl der verfügbaren Einträge;
* reserve: Platz für n Einträge reservieren, Daten ggf. kopieren (optional)
* operator<< und
* operator==: zwei Stacks haben die gleiche Größe und gleiche
  Einträge.
Stacküber- und -underlauf sollen eine Ausnahme werfen.

Die Move-Operationen sollen in der Quelle einen leeren Stack hinterlassen,
wobei die Kapazität erhalten bleiben oder auf 0 reduziert werden kann.

Die Implementierung soll für die internen Daten einen
Unique-Pointer verwenden.



 */



namespace sn {

    // Immer gut, von std::exception abzuleiten
    struct underflow
      : std::exception
    {
	virtual const char* what() const noexcept override {return "Stack underflow!\n";}
    };

    struct overflow
      : std::exception
    {
	virtual const char* what() const noexcept override {return "Stack overflow!\n";}
    };

    class stack
    {
	
    };
}


int main () 
{
    using namespace std;
    using namespace sn;

    stack   si(100);

    assert(si.empty());
    assert(!si.full());
    assert(si.size() == 0);
    assert(si.capacity() == 100);
    
    for (int i= 0; i < si.capacity(); ++i)
	si.push(i);

    assert(!si.empty());
    assert(si.full());
    assert(si.size() == 100);
    assert(si.top() == 99);
    
    si.pop();
    assert(!si.empty());
    assert(!si.full());
    assert(si.size() == 99);
    assert(si.top() == 98);

    stack   si2= {3, 9, 4, 8};
    cout << "si2 initial = " << si2 << endl;

    assert(!si2.empty());
    assert(si2.full());
    assert(si2.size() == 4);
    assert(si2.capacity() == 4);
    assert(si2.top() == 8);

    stack   si2ref(4);
    si2ref.push(3);
    si2ref.push(9);
    si2ref.push(4);
    si2ref.push(8);

    assert(si2 == si2ref);
    
    stack si3(si2);
    cout << "si3 nach Copy-Konstruktor = " << si3 << endl;
    assert(si3 == si2ref);

    
    stack si5(4);
    si5= si2;
    cout << "si5 nach Copy-Konstruktor = " << si5 << endl;
    assert(si5 == si2ref);


    stack   si7= {3, 2, 1, 0};
    try {
	si7.push(-1);
	throw "Fehlende Ausnahme";
    } catch (overflow) {
	cout << "Overflow erfolgreich gefangen.\n";
    }

    stack   si8(10);
    try {
	si8.pop();
	throw "Fehlende Ausnahme";
    } catch (underflow) {
	cout << "Underflow erfolgreich gefangen.\n";
    }    
    
    return 0;
}

