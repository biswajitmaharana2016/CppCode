#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <atomic>

using namespace std;
using namespace std::chrono;

namespace ct {

#if 0
    int   cnt{0};
    mutex m;
    
    void inc()
    {
	for (int i= 0; i < 1'000'000; ++i) {
	    lock_guard<mutex> lg{m};
	    ++cnt;
	}
    }


    struct shared_stuff
    {
	int getter1() const
	{
	    m.lock();
	    int cp{i};
	    m.unlock();
	    return cp;
	}

	int getter2() const
	{
	    lock_guard<mutex> lg{m};
	    return i;
	}
	
	mutable mutex m;
	int i{4};
    };
#endif
    
    atomic<int>   cnt{0};

    void inc()
    {
    	// for (int i= 0; i < 1'000'000; ++i)
    	//     ++cnt;
	for (int i= 0; i < 1'000'000; ++i) {
	    int cp{cnt}, neu;
	    do {
		neu= cp + 1;
	    } while (! cnt.compare_exchange_weak(cp, neu));
	}
    }
}

int main () 
{
    using namespace ct;

    vector<thread> v;
    auto start= high_resolution_clock::now();
    for (int i= 0; i < 10; ++i)
	v.emplace_back(inc);

    for (thread& t : v)
	t.join();
    auto finish= high_resolution_clock::now();
    cout << "cnt = " << cnt << endl;
    cout << "Dauer: " << duration_cast<microseconds>(finish - start).count() / 1000.0 << "ms.\n";

    return 0;
}
  
 
