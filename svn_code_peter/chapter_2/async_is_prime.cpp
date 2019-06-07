#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <chrono>

#include <thread>
#include <future>

#include "irange.hpp"

using namespace std;

namespace sn {

    struct obvious {};
    
    bool is_prime(size_t i)
    {
	if (i % 10 == 5 && i != 5)
	    throw obvious{};
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	for (size_t j= 3; j < i; j+=2)
	    if (i % j == 0)
		return false;
	return true;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    int num_threads= 2;
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<size_t> vi;
    for (size_t i= 0, v= 982'451'653; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<future<bool>> futures;
    for (size_t i : vi)
	futures.push_back(async(is_prime, i));
    
    cout << "Alle Threads gestartet." << endl;

    for (size_t i : irange{0, num_threads}) {
	while (futures[i].wait_for(200ms) != future_status::ready)
	    cout << "Das dauert!!!!!" << endl;
	try {
	    bool it_is= futures[i].get();
	    cout << vi[i] << " ist " << (it_is ? "eine" : "keine") << " Primzahl.\n";
	} catch (obvious) {
	    cout << vi[i] << " ist offensichtlich keine Primzahl.\n";
	}
    }
    
    return 0;
}
  
 
