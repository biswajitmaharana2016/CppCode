#include <iostream>
#include <optional>
#include <string>
#include <cmath>

using namespace std;

namespace sn {

    optional<double> wurzel(double x)
    {
	if (x < 0)
	    return nullopt;
	else
	    return sqrt(x);
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    auto w2= wurzel(2.0);
    if (w2)
	cout << "Die Wurzel ist " << *w2 << endl;
    else
	cout << "Es gibt keine Wurzel.\n";
    
    auto wm2= wurzel(-2.0);
    if (wm2)
	cout << "Die Wurzel ist " << *wm2 << endl;
    else
	cout << "Es gibt keine Wurzel.\n";

    return 0;
}
  
 
