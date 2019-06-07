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
	    my_info();
	}

	void my_info() const {
	    cout << "Der Name des Fahrzeugs ist " << name << ".\n";
	}
      private:
	string name;
    };

    class zug : virtual public fahrzeug
    {
      protected:
	zug(string antrieb) : fahrzeug{""}, antrieb{antrieb} {}
	    
      public:
	zug(string name, string antrieb) : fahrzeug{name}, antrieb{antrieb} {}

	virtual void all_info() const override {
	    fahrzeug::my_info();
	    my_info();
	}
	void my_info() const {
	    cout << "Die Antriebsart ist " << antrieb << ".\n";
	}
      private:
	string antrieb;
    };

    class karre : virtual public fahrzeug
    {
      protected:
	karre(unsigned passagiere) : fahrzeug{""}, passagiere{passagiere} {}
      public:
	karre(string name, unsigned passagiere) : fahrzeug{name}, passagiere{passagiere} {}

	virtual void all_info() const override {
	    fahrzeug::my_info();
	    my_info();
	}

	void my_info() const {
	    cout << "Ich kann " << passagiere << " Person transportieren.\n";
	}
      private:
	unsigned passagiere;
    };

    class reparatur_fahrzeug final
      : public zug, public karre
    {
      public:
	reparatur_fahrzeug(string name, string antrieb, unsigned passagiere)
	  : fahrzeug{name}, zug{antrieb}, karre{passagiere} {}

	virtual void all_info() const override final {
	    zug::all_info();
	    karre::my_info();
	}
    };

    // class verbotene_ableitung : public reparatur_fahrzeug {};
    
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
    cout << endl;

    tellme(sfr);
    
    return 0;
}
  
 
