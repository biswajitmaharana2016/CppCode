#include <iostream>
#include <tuple>
#include <string>
#include <cmath>

using namespace std;

namespace sn {

    tuple<bool, double> wurzel(double x)
    {
	if (x < 0)
	    return tuple<bool, double>{false, 0.0};
	else
	    return {true, sqrt(x)};
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    tuple<int, float, string> t1{3, 4.2, "Huhu"};

    auto w2= wurzel(2.0);
    if (get<0>(w2))
	cout << "Die Wurzel ist " << get<1>(w2) << endl;
    else
	cout << "Es gibt keine Wurzel.\n";
    
    auto wm2= wurzel(-2.0);
    if (get<bool>(wm2))
	cout << "Die Wurzel ist " << get<double>(wm2) << endl;
    else
	cout << "Es gibt keine Wurzel.\n";

    bool valid;
    double sq;
    tie(valid, sq)= wurzel(-4.0);

    return 0;
}
  
 
