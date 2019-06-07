#include <iostream>
#include <chrono>
#include <vector>

#include <thread>
#include <mutex>
#include <atomic>

#include "irange.hpp"

using namespace std;
using namespace std::chrono;

namespace sn {

#if 0
    int   cnt{0};
    mutex m;

    struct java_style
    {
	int get_umstaendlich() const {
	    m.lock();
	    int cp{i};
	    m.unlock();
	    return cp;
	    
	}

	int get()
	{
	    lock_guard<mutex> lg{m};
	    return i;
	    // Destruktor von lg nach return, fuehrt unlock aus
	}

	mutable mutex m;
	int i{9};
    };

    void inc()
    {
	for (int i: irange{0, 1'000'000}) {
	    lock_guard<mutex> lg{m};
	    ++cnt;
	}
    }
#endif

    atomic<int> cnt{0};
	    
    void inc()
    {
	for (int i: irange{0, 1'000'000}) {
	    // ++cnt;
	    // cnt.fetch_add(1, memory_order_seq_cst);
	    // cnt.fetch_add(1, memory_order_acq_rel);
	    // cnt.fetch_add(1, memory_order_relaxed);
	    int cp{cnt}, neu;
	    do {
		neu= cp + 1;
	    } while (!cnt.compare_exchange_strong(cp, neu));
	    
	}
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    vector<thread> v;
    auto start= high_resolution_clock::now();
    for (int i: irange{0, 10})
	v.emplace_back(inc);

    for (thread& t : v)
	t.join();
    auto finish= high_resolution_clock::now();

    cout << "cnt = " << cnt << endl;
    cout << "Dauer: " << duration_cast<microseconds>(finish - start).count() / 1000.0 << "ms.\n";
    
    return 0;
}
  
 
