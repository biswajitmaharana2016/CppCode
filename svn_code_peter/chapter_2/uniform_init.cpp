#include <iostream>
#include <vector>

using namespace std;

namespace sn {

    struct olle_c_klasse
    {
	int    i;
	double d;
    };

    struct leer {};

    template <typename T>
    void f(const T& x)
    {
	T e1; // Default-Ktor, fund. Typen uninitialisiert
	// T e2(); // Funktionsdeklaration
	T e3{}; // Default-Ktor, fund. Typen wertinit. (0, nullptr, ...)

    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    // int i1= 3.5;   // evtl. Warnung wegen Verengung
    // int i2(3.6);   // dito
    // int i3{3.7};   // Fehler: Verengung
    // int i4= {3.8}; // Fehler: Verengung

    int      i5{5};
    unsigned u1{9};

    // int      i6{u1}; // Fehler: kann grosse Zahlen nicht darstellen
    // unsigned u2{i5}; // Fehler: kann negative Werte nicht darstellen

    static_assert(sizeof(long) > sizeof(unsigned),
		  "long nicht laenger als unsigned.");
    long l1{u1};

    olle_c_klasse oc1{9, 4.2}, oc2{5};

    leer le1;
    // leer le2(); // Funktionsdeklaration
    leer le3{}; // Default-Konstruktor

    vector<int> v1;
    v1.push_back(7);
    v1.push_back(3);
    v1.push_back(9);
    f(v1);

    vector<int> v2{7, 3, 9};
    f(v2);

    f(vector<int>{7, 3, 9});

    return 0;
}
   
 
