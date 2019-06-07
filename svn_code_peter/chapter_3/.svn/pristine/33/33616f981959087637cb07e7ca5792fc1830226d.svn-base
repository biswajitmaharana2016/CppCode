#include <iostream>
#include <cmath>
#include <chrono>
#include <typeinfo>

using namespace std;

namespace le {


    class length
    {
      public:
	explicit length(double l) : l{l} {}

	friend std::ostream& operator<<(ostream& os, length ll)
	{
	    if (abs(ll.l) >= 1000.0)
		return os << ll.l / 1000.0 << "km";
	    else
		return os << ll.l  << "m"; 
	}

	length operator+(length l2) const { return length{l + l2.l}; }
	length operator-() const { return length{-l}; }

      private:
	double l;
    };

    length operator""_m(long double ld) { return length(ld); }
    length operator""_m(unsigned long long ld) { return length(ld); }
    
    length operator""_nm(long double ld) { return length(1852.0 * ld); }
    length operator""_nm(unsigned long long ld) { return length(1852.0 * ld); }
}

int main (int argc, char* argv[]) 
{
    // using namespace le;
    using le::operator""_m;
    using le::operator""_nm;

    le::length l1{3.4};
    cout << "l1 = " << l1 << endl;

    auto l2= 5.6_m;
    cout << "l2 = " << l2 << endl;

    auto l3= 2.3_nm;
    cout << "l3 = " << l3 << endl;

    cout << "4.3_nm + 240_m = " << 4.3_nm + 240_m << endl;
    cout << "-4.3_nm + 240_m = " << -4.3_nm + 240_m << endl;

    chrono::milliseconds d1(300);
    auto d2= 300ms;
    auto d3= 300.0ms;
    auto d4= 4h;
    auto d5= 5h + 400.0ms;
    auto d6= 434'341'156ms;

    cout << "Type of d2 is " << typeid(d2).name() << endl;
    cout << "Type of d3 is " << typeid(d3).name() << endl;

    cout << "Type of d4 is " << typeid(d4).name() << endl;
    cout << "Type of d5 is " << typeid(d5).name() << endl;

    
    
    return 0;
}
  
 
