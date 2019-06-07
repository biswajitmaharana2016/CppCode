#include <iostream>
#include <string>

using namespace std;

namespace sn {

    class fahrzeug
    {
      public:
	fahrzeug(string name) : name{name} {}

	virtual ~fahrzeug() = default;

	virtual void all_info() const {
	    cout << "Der Name des Fahrzeugs ist " << name << ".\n\n";
	}

	string get_name() const { return name; }
      private:
	string name;
    };

    class zug : public fahrzeug
    {
      public:
	zug(string name, string antrieb) : fahrzeug{name}, antrieb{antrieb} {}

	virtual void all_info() const override {
	    cout << "Der Name des Fahrzeugs ist " << get_name() << ".\n";
	    cout << "Die Antriebsart ist " << antrieb << ".\n\n";
	}

	string get_antrieb() const { return antrieb; }
      private:
	string antrieb;
    };

    void tellme(fahrzeug& f)
    {
	f.all_info();
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    fahrzeug f{"Alfa Romeo Giulia"};
    f.all_info();

    zug ice3{"ICE 3", "Elektro"};
    ice3.all_info();

    fahrzeug& f2{ice3};
    fahrzeug* f3{&ice3};

    tellme(ice3);

    const zug ice3c{ice3};
    ice3c.all_info();
    // tellme(const_cast<fahrzeug&>(ice3c));
    tellme(const_cast<zug&>(ice3c)); // Risiko, nur mit Legacy Code

    // zug& ice3i{f2}; // Down-cast nicht implicit
    zug& ice3s= static_cast<zug&>(f2); // nur statische Typpruefung
    // zug& ice3sc= static_cast<zug&>(ice3c); // darf kein const entfernen
    zug& ice3d= dynamic_cast<zug&>(f2); // dito, aber Laufzeittest des Objektes

    ice3s.all_info();
    ice3d.all_info();

    zug& alfas= static_cast<zug&>(f); // liegt in Verantw. des Programmierers
    cout << "Antrieb ist " << alfas.get_antrieb() << endl;

    try {
	zug& alfad= dynamic_cast<zug&>(f);
    } catch (std::bad_cast& ) {
	cout << "Das ist gar kein Zug, Aldaa!\n";
    }

    zug* alfap= dynamic_cast<zug*>(&f);
    if (alfap == nullptr)
	cout << "Das ist gar kein Zug, Aldaa!\n";

    // Ab hier wird es schmutzig, sehr schmutzig.
    int& i1= reinterpret_cast<int&>(f);

    int& i2= (int&)f;
    int& i3= (int&)ice3c;

    const double d1{4.8};
    int* p= (int*) (int) d1;
    int* p2= reinterpret_cast<int*>(const_cast<double*>(&d1));
   
    return 0;
}
  
 
