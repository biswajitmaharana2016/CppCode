#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <functional>
#include <future>
#include <chrono>

using namespace std;

namespace le {

    struct trivial {};
    
    bool is_prime(size_t n)
    {
	if (n % 10 == 5 && n != 5)
	    throw trivial{};
	if (n == 1)
	    return false;
	if (n % 2 == 0)
	    return n == 2;
	for (size_t j= 3; j < n; j+= 2)
	    if (n % j == 0)
		return false;
	return true;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    int num_threads{2};
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<size_t> vi;
    for (int i= 0, v= 982'451'653; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<future<bool>> futures;
    for (size_t v : vi)
	futures.push_back( async( is_prime, v ) );

    cout << "Everything started." << endl;

    for (int i= 0; i < num_threads; ++i) {
	while (futures[i].wait_for(200ms) != future_status::ready)
	    cout << "I'm bored! Get ready!" << endl;
	try {
	    bool it_is= futures[i].get();
	    cout << vi[i] << " is " << (it_is ? "" : "not ") << "a prime number.\n";
	} catch (trivial) {
	    cout << vi[i] << " is obviously not a prime number.\n";
	}
    }
    
    return 0;
}
  
 
