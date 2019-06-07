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
      private:
	string antrieb;
    };
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    fahrzeug f{"Alfa Romeo Giulia"};
    f.all_info();

    zug ice3{"ICE 3", "Elektro"};
    ice3.all_info();

    fahrzeug  f1{ice3}; // Slicing: f1 ist eine Kopie eines Teils von ice3
    fahrzeug& f2{ice3};
    fahrzeug* f3{&ice3};

    f1.all_info();
    f2.all_info();
    f3->all_info();

    fahrzeug* ice2= new zug{"ICE 2", "Elektro"};
    ice2->all_info();
    delete ice2;
    
    return 0;
}
  
 
