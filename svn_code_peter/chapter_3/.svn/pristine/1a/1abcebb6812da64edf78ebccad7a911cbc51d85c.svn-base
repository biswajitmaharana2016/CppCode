#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;
using namespace std::chrono;

namespace le {

#if 0
    int cnt{0};
    mutex m;

    struct shared_stuff
    {
	int getter1() const {
	    m.lock();
	    int cp{i};
	    m.unlock();
	    return cp;
	}

	int getter2() const {
	    lock_guard<mutex> lg{m};
	    return i;
	    // unlock is done after the return
	}
	
	mutable mutex m;
	int i{4};
    };
    
    void inc() 
    {
	for (int i= 0; i < 1'000'000; ++i) {
	    lock_guard<mutex> lg{m};
	    ++cnt;
	}
    }
#endif

    atomic<int> cnt{0};


#if 0
    void inc() 
    {
	for (int i= 0; i < 1'000'000; ++i) {
	    // ++cnt; // sequential consistency
	    // cnt.fetch_add(1, memory_order_seq_cst);
	    // cnt.fetch_add(1, memory_order_acq_rel);
	    cnt.fetch_add(1, memory_order_relaxed);
	}
    }
#endif

    void inc() 
    {
	for (int i= 0; i < 1'000'000; ++i) {
	    int old{cnt}, neu;
	    do {
		neu= old + 1;
	    } while (! cnt.compare_exchange_weak(old, neu) );
	}
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    vector<thread> v;
    auto start= high_resolution_clock::now();
    for (int i= 0; i < 10; ++i)
	v.emplace_back( inc );

    for(thread& t : v)
	t.join();
    auto finish= high_resolution_clock::now();
    cout << "cnt = " << cnt << endl;
    cout << "It took " << duration_cast<microseconds>(finish-start).count() / 1000.0 << "ms.\n";

    return 0;
}
  
 
