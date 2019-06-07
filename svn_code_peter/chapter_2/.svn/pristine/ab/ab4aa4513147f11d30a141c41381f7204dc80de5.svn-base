#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <limits>

using namespace std;

namespace sn {

}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    set<int> s{1, 3, 4, 7, 9};
    s.insert(11);

    if (s.count(15) > 0)
	cout << "15 gibt es in s.\n";
    if (s.count(11) > 0)
	cout << "11 gibt es in s.\n";
    cout << "11 gibt es " << s.count(11) << " Mal.\n";
    s.insert(11);
    cout << "11 gibt es " << s.count(11) << " Mal.\n";

    multiset<int> ms(begin(s), end(s));
    cout << "11 gibt es " << ms.count(11) << " Mal.\n";
    ms.insert(11);
    cout << "11 gibt es " << ms.count(11) << " Mal.\n";

    // map<string, unsigned> gewonnene_spiele{{"Roman", 11},
    // 	           {"Ricchi", numeric_limits<unsigned>::max()+1}};
    unordered_map<string, unsigned> gewonnene_spiele{{"Roman", 11},
	           {"Ricchi", numeric_limits<unsigned>::max()+1}};

    gewonnene_spiele["Stefan"]= 12;

    if (gewonnene_spiele.count("Ralf") == 0)
	cout << "Ralf kenne ich nicht.\n";
    auto it= gewonnene_spiele.find("Ralf");
    if (it == end(gewonnene_spiele))
	cout << "Ralf kenne ich nicht.\n";
    else
	cout << "Ralf hat " << it->second << " Spiele gewonnenen.\n";
    
    // cout << "Ralf hat " << gewonnene_spiele.at("Ralf") << " Spiele gewonnenen.\n";
    cout << "Ralf hat " << gewonnene_spiele["Ralf"] << " Spiele gewonnenen.\n";

    for (pair<const string, unsigned> p : gewonnene_spiele)
	cout << p.first << " hat " << p.second << " Spiele gewonnen.\n";
    
    return 0;
}
  
 
