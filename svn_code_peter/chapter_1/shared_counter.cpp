#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

using namespace std;
using namespace std::chrono;

namespace mv {

#if 0
    int counter{0};
    mutex m;

    struct dings
    {
	int getter1()
	{
	    m.lock();
	    int cp{i};
	    m.unlock();
	    return cp;
	}

	int getter2()
	{
	    lock_guard<mutex> lg{m};
	    return i;
	}

	mutable mutex m;
	int i; 
    };
    
    void inc()
    {
	for (int i= 0; i < 1'000'000; ++i) {
	    lock_guard<mutex> lg{m};
	    ++counter;
	}
    }
#endif

    atomic<int> counter{0};
    
    void inc()
    {
	for (int i= 0; i < 1'000'000; ++i) {
	    // ++counter;
	    // counter.fetch_add(1);
	    int cp{counter}, neu;
	    do {
		neu= cp + 1;
	    } while (!counter.compare_exchange_weak(cp, neu)); 
	}
    }

}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    auto start= high_resolution_clock::now();
    vector<thread> t;
    for (int i= 0; i < 10; ++i)
    	t.emplace_back(inc);

    cout << "Alles gestartet.\n";
    for (auto& ti : t)
	ti.join();

    auto ende= high_resolution_clock::now();
    cout << "Dauer: " << duration_cast<microseconds>(ende - start).count() / 1000.0 << "ms.\n";
    cout << "counter: " << counter << ".\n";

    return 0;
}
  
 
