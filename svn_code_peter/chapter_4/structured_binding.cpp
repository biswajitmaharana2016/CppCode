#include <iostream>
#include <tuple>
#include <unordered_map>

using namespace std;

namespace ct {

    tuple<int, float, double> f() { return {3, 3.7f, 4.2}; }

    struct olles_c_zeug
    {
	int i;
	double d;
    };

    olles_c_zeug g() { return {3, 4.9}; }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    auto t1= f();
    auto t10= get<0>(t1);
    cout << "t10 = " << t10 << endl;

    auto t1i= get<int>(t1);

    int i2;
    float f2;
    double d2;
    tie(i2, f2, d2)= f();

    auto [t30, t31, t32]= f();
    cout << "t30 = " << t30 << endl;

    auto [o1, o2]= g();

    unordered_map<string, int> telefon{{"Ralf", 483}, {"Lutz", 481}, {"Peter", 480}};

    for (pair<const string, int> entry : telefon)
	cout << entry.first << "s Nummer ist " << entry.second << endl;

    for (auto [name, nummer] : telefon)
	cout << name << "s Nummer ist " << nummer << endl;
    return 0;
}
  
 
