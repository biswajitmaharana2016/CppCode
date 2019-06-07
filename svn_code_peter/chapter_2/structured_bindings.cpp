#include <iostream>
#include <tuple>
#include <unordered_map>

using namespace std;

namespace sn {

    tuple<int, float, string> create() { return {4, 2.8, "nee"}; }

    struct olles_c_zeug
    {
	int    i;
	double d;
    };

    auto altlasten_interface() { return olles_c_zeug{9, 2.8}; }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    tuple t1{3, 9.1, "Haha"s};
    auto [anzahl, flaeche, bemerkung]= t1;
    cout << "Die Flaeche ist " << flaeche << endl; 

    auto [zahl, laenge, begeisterung]= create();

    auto [schrauben, spannung]= altlasten_interface();

    unordered_map<string, unsigned> gewonnene_spiele{{"Roman", 11},
	           {"Ricchi", numeric_limits<unsigned>::max()+1}};
    gewonnene_spiele["Stefan"]= 12;

    for (auto [name, anzahl] : gewonnene_spiele)
	cout << name << " hat " << anzahl << " Spiele gewonnen.\n";
    
    return 0;
}
  
 
