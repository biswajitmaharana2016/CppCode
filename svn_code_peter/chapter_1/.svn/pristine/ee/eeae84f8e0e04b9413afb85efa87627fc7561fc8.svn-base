#include <iostream>

using namespace std;

namespace mv {

    struct leer {};

    template <typename T>
    void f(T x)
    {
	T leer1;   // Default-Ktor, intr. Typen nicht init.
	T leer2(); // Funktionsdeklaration
	T leer3{}; // Default-Ktor, intr. Typen init. (0, nullptr)
    }

    struct olles_c_zeug
    {
	int i;
	double d;
    };
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    int i1= 3.4;
    int i2(3.5);
    // int i3{3.6}; // Fehler: narrowing
    // int i4= {3.7};  // Fehler: narrowing

    int i5{5};
    unsigned u1{2};
    // int i7{u1}; // Fehler/Warnung: narrowing
    // unsigned u2{i5}; // Fehler/Warnung: narrowing

    static_assert(sizeof(long) > sizeof(unsigned),
		  "long ist hier genauso gross wie uns, du Nase.");
    long l1{u1};

    int i8{1234567901};

    leer l2;
    leer l3(); // Funktionsdeklaration
    leer l4{}; // Default-Konstruktor

    f(leer());
    f(leer{});

    olles_c_zeug o1{4, 9.3}, o2{3};
    cout << "o2.d = " << o2.d << endl;
    
    
    return 0;
}
  
 
