#include <iostream>
#include <string>
#include <utility>

using namespace std;

namespace sn {

    inline int maxi(int i, int j)
    {
	return i > j ? i : j;
	// return [j, i][i > j];      in Python
	// return i if i > j else j;  dito
    }


    namespace drinnen {

	int g(int i, int j) { return maxi(i, j); }
	int h(int i, int j) { return maxi(i, j); }

	struct meine_klasse {};
	void f(int) {}
	void f(meine_klasse) {}

	void swap(meine_klasse&, meine_klasse&)
	{
	    cout << "Mein swap, ist total schnell.\n";
	}
	
    }
}

// drinnen::meine_klasse mk_global;

int main (int argc, char* argv[]) 
{
    using namespace sn;
    using sn::drinnen::h;
    namespace sd= sn::drinnen;

    cout << "maxi(3, 7) = " << sn::maxi(3, 7) << "\n";

    cout << "g(9, 8) = " << drinnen::g(9, 8) << endl;
    cout << "g(9, 8) = " << sd::g(9, 8) << endl;
    cout << "h(9, 8) = " << h(9, 8) << endl;

    // f(3);
    drinnen::meine_klasse mk, mk2;
    f(mk);

    int i= 4;                         // #1
    cout << "i = " << i << endl;

    {
	cout << "i = " << i << endl;

	++i;
	cout << "i = " << i << endl;

	int i= 44;                    // #2
	cout << "i = " << i << endl;

	++i;
	cout << "i = " << i << endl;
    }
    cout << "i = " << i << endl;
   
    int j= 44;

    std::swap(i, j);
    cout << "i = " << i << ", j = " << j << endl;

    using std::swap;
    swap(i, j);
    cout << "i = " << i << ", j = " << j << endl;

    std::swap(mk, mk2);

    swap(mk, mk2);

    return 0;
}
  
 
