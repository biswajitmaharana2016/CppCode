#include <iostream>
#include <tuple>
#include <unordered_map>

using namespace std;

namespace le {

    auto create() { return tuple<int, float, short>{4, 3.4f, 9}; }
    
    struct nasty_ole_c
    {
	double d;
	int    i;
      private:
	int g() { return 3; }
    };

    auto ole_create() { return nasty_ole_c{3.8, 2}; }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    auto t1= create();
    auto t10= get<0>(t1);
    auto t11= get<1>(t1);
    auto t12= get<2>(t1);

    cout << "The int in the tuple is " << get<int>(t1) << endl;

    int   t20;
    float t21;
    short t22;
    tie(t20, t21, t22)= create();

    auto [t30, t31, t32]= create();

    auto [od, oi]= ole_create();

    unordered_map<string, string> sitting{{"Florian", "in front"}, {"Eric", "left"},
					  {"Vedran", "right"}};

    for (pair<const string, string> value : sitting)
	cout << value.first << " is sitting " << value.second << ".\n";

    for (auto [name, place] : sitting)
	cout << name  << " is sitting " << place << ".\n";
    
    return 0;
}
  
 
