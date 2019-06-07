#include <iostream>
#include <vector>
#include <thread>
#include <string>

using namespace std;

namespace ct {

    bool is_prime(size_t i)
    {
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

    size_t num_threads= 2;
    if (argc > 1)
	num_threads= stoul(argv[1]);

    vector<size_t>     vi;
    for (size_t i= 0, v= 982'451'653; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<thread> threads;
    vector<short> results(num_threads);
    for (size_t i= 0; i < num_threads; ++i)
	threads.emplace_back( [&results, i, &vi]() { results[i]= is_prime(vi[i]); } );
	
	// threads.push_back( thread{[&results, i, &vi]() { results[i]= is_prime(vi[i]); } } );

    cout << "Alles gestartet" << endl;

    for (size_t i= 0; i < num_threads; ++i) {
	threads[i].join();
	cout << vi[i] << " ist " << (results[i] ? "eine" : "keine") << " Primzahl.\n";
    }

    return 0;
}
  
 
