#include <iostream>
#include <string>

using namespace std;

namespace sn {

    // Abstrakte Klasse
    class geraet
    {
      public:
	virtual void all_info() const = 0;
	virtual ~geraet() {}
    };

    // Polymorphe Klasse (enthaelt virtuelle Funktion)
    class fahrzeug : public geraet
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

    void tellme(const geraet& f)
    {
	f.all_info();
    }

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    // geraet g; // kann keine Objekte von abstrakten Klassen bauen
    
    fahrzeug f{"Alfa Romeo Giulia"};
    f.all_info();

    zug ice3{"ICE 3", "Elektro"};
    ice3.all_info();
    
    return 0;
}
  
 
