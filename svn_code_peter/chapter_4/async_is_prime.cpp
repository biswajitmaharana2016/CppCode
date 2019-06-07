#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <functional>
#include <future>
#include <chrono>
#include <typeinfo>

using namespace std;

namespace ct {

    struct trivial {};

    bool is_prime(size_t i)
    {
	if (i % 10 == 5 && i != 5)
	    throw trivial{};
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	// bis Wurzel reichen, aber dann zu schnell
	for (size_t j= 3; j < i; j+= 2)
	    if (i % j == 0)
		return false;
	return true;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // cout << typeid(200.0h).name() << endl;
    // return 0;

    size_t num_threads= 2;
    if (argc > 1)
	num_threads= stoul(argv[1]);

    vector<size_t>     vi;
    for (size_t i= 0, v= 982'451'653; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<future<bool>> futures;
    for (size_t v : vi)
	futures.push_back(async(launch::async, is_prime, v));
 
    cout << "Alles gestartet" << endl;

    for (size_t i= 0; i < num_threads; ++i) {
	// while (futures[i].wait_for(200ms) != future_status::ready)
	//     cout << "Das dauert!!!" << endl;
	try {
	    bool is_it= futures[i].get();
	    cout << vi[i] << " ist " << (is_it ? "eine" : "keine") << " Primzahl.\n";
	} catch (trivial) {
	    cout << vi[i] << " ist offensichtlich keine Primzahl.\n";
	}
    }

    return 0;
}
  
 
