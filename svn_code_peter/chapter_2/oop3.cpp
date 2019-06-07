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

    class karre : public fahrzeug
    {
      public:
	karre(string name, unsigned passagiere) : fahrzeug{name}, passagiere{passagiere} {}

	virtual void all_info() const override {
	    cout << "Der Name des Fahrzeugs ist " << get_name() << ".\n";
	    cout << "Ich kann " << passagiere << " Person transportieren.\n\n";
	}
      private:
	unsigned passagiere;
    };

    class reparatur_fahrzeug
      : public zug, public karre
    {
      public:
	reparatur_fahrzeug(string name, string antrieb, unsigned passagiere)
	  : zug{name+"_z", antrieb}, karre{name+"_k", passagiere} {}

	virtual void all_info() const override {
	    zug::all_info();
	    karre::all_info();
	}
    };
    
    void tellme(const geraet& f)
    {
	f.all_info();
    }

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    reparatur_fahrzeug sfr{"Smart for rail", "Benzin", 2};
    sfr.all_info();

    // tellme(sfr);
    
    return 0;
}
  
 
