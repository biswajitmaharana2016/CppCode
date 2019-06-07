#include <iostream>
#include <string>

using namespace std;

namespace sn {

    inline int maxi(int i, int j)
    {
	++j;
	// i > j ? i : j;
	return i > j ? i : j;
    }

    namespace {
	int maxr(int& i, int& j)
	{
	    ++j;
	    // i > j ? i : j;
	    return i > j ? i : j;
	}
    }

    int maxc(const int& i, const int& j)
    {
	// ++j;
	// i > j ? i : j;
	return i > j ? i : j;
    }
    
    void quatsch(ostream&) {}
}


int main (int argc, char* argv[]) 
{
    using namespace sn;

    quatsch(cout << "Huhu\n"); // Auch die Ausgabe ist ein Ausdruck

    // aus sn
    int x= 3, y= 7;
    cout << "maxi(3, 7) = " << sn::maxi(x, y) << "\n";

    int i= 4, j= 5;
    cout << "maxr(4, 5) = " << sn::maxr(i, j) << "\n";

    cout << "maxc(3, 7) = " << sn::maxc(3, 7) << "\n";

    cout << "y = " << y << ", j = " << j << endl;
    
    if (argc > 2) 
	cout << "maxi(" << argv[1] << ", " << argv[2] << ") = "
	     << maxi(stoi(argv[1]), stoi(argv[2])) << endl;

    return 0;
}
  
 
