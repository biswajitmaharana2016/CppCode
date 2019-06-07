#include <iostream>

using namespace std;

namespace ct {

    struct empty {};

    template <typename T>
    void f(T)
    {
	T empty1;   // Default-Ktor, fund. Typen nicht initialisiert
	// T empty2(); // Funktionsdeklaration
	T empty3{}; // Default-Ktor, fund. Typen wertinit. (0, nullptr)
    }
	
    struct olles_c_zeug
    {
	int i;
	double d;
    };

    class richtige_klasse
    {
      public:
	richtige_klasse(int i, double d) : i{i}, d{d} {}
      private:
	int i;
	double d;
    };
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    olles_c_zeug o1{4, 3.9}, o2{5};

    richtige_klasse r1{2, 9.1}, r2{2, 9.2};
    
    // int i1= 3.8; // Warnung im clang
    // int i2(3.7); // dito
    // int i3{3.6}; // Fehler: Verengung
    //  int i4= {3.5}; // Fehler: Verengung

    int i5{1234567890};

    int      i6{3};
    unsigned u1{4}; 

    // unsigned u2{i6};
    // int      i7{u1};

    static_assert(sizeof(long) > sizeof(unsigned),
		  "long nicht laenger als unsigned");
    long     l1{u1};

    ct::empty e1;
    // ct::empty e2(); // Funktionsdeklaration, Most Vexing Parse
    ct::empty e3{}; // Default-Konstruktor
    
    return 0;
}
  
 
