#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

namespace sn {

    double wurzel(double x)
    {
	return sqrt(x); 
    }

    int wurzel_code(double x, double& res)
    {
	if (x < 0.0)
	    return 1;
	res= sqrt(x);
	return 0; 
    }

#if 0
    struct arithmetischer_fehler : std::exception {};
    struct wurzel_von_negativ : arithmetischer_fehler
    {
	virtual const char* what() const noexcept override {
	    return "Wurzel von negativem Wert.";
	}
    };
#endif
    
    struct arithmetischer_fehler
      : std::runtime_error
    {
        arithmetischer_fehler() : std::runtime_error("Arithmetischer Fehler") {}
        arithmetischer_fehler(const char* e) : std::runtime_error(e) {}
    };
    
    struct wurzel_von_negativ : arithmetischer_fehler
    {
        wurzel_von_negativ() : arithmetischer_fehler("Wurzel von negativem Wert.") {}
    };

    
    double wurzel_exc(double x)
    {
	if (x < 0.0)
	    throw wurzel_von_negativ{};
	return sqrt(x); 
    }
	
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    cout << "wurzel(2.0) = " << wurzel(2.0) << endl;
    cout << "wurzel(-2.0) = " << wurzel(-2.0) << endl;

    double res;
    int code= wurzel_code(-2.0, res);
    if (res == 0)
	cout << "wurzel(-2.0) = " << res << endl;
    else
	cout << "wurzel konnte nicht berechnet werden.\n";

    wurzel_code(-2.0, res);
    cout << "wurzel(-2.0) = " << res << endl;

    cout << "wurzel(2.0) = " << wurzel_exc(2.0) << endl;
    try {
	cout << "wurzel(-2.0) = " << wurzel_exc(-2.0) << endl;
    } catch (wurzel_von_negativ& ex) {
    	cout << "\nAusnahme gefangen: Wurzel von negativen Wert.\n";
    	cout << "Ich mache absichtlich nichts.\n";
    	// throw; // wirft aktuelle Ausnahme
    } catch (arithmetischer_fehler& ex) {
    	cout << "\nAusnahme gefangen: anderer math. Quatsch.\n";
    } catch (std::exception& ex) {
	cout << "\nstd::exception gefangen: " << ex.what() << endl;
    } catch (...) {
	cout << "Irgendeine Ausnahme.\n";
    }
    
	
    
    return 0;
}
  
 
