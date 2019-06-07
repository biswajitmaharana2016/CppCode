#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

namespace le {

    struct trivial {};
    
    bool is_prime(size_t n)
    {
	// if (n % 10 == 5 && n != 5)
	//     throw trivial{};
	if (n == 1)
	    return false;
	if (n % 2 == 0)
	    return n == 2;
	// size_t max_check= ceil(sqrt(n)); // would be too fast
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

    vector<thread> threads;
    vector<short>  results(num_threads);
    for (int i= 0; i < num_threads; ++i)
	threads.emplace_back( [&results, &vi, i](){ results[i]= is_prime(vi[i]); } );

    cout << "Everything started." << endl;

    for (int i= 0; i < num_threads; ++i) {
	threads[i].join();
	cout << vi[i] << " is " << (results[i] ? "" : "not ") << "a prime number.\n";
    }
    
    return 0;
}
  
 
