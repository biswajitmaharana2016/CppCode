// shared_counter.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

using namespace std;
using namespace std::chrono;

namespace ct {

#if 0
    int cnt{ 0 };
    mutex m;

    struct shared_stuff
    {
        int getter1() const {
            m.lock();
            int cp{ i };
            m.unlock();
            return cp;
        }

        int getter2() const {
            lock_guard<mutex> lg{ m };
            return i;
        }

        mutable mutex m;
        int i{ 9 };
    };

    void inc()
    {
        for (int i = 0; i < 1'000'000; ++i) {
            lock_guard<mutex> lg{ m };
            ++cnt;           
        }
    }
#endif 

    atomic<int> cnt;

    void inc()
    {
        for (int i = 0; i < 1'000'000; ++i) {
            // ++cnt;
            // cnt.fetch_add(1, memory_order_seq_cst);
            // cnt.fetch_add(1, memory_order_acq_rel);
            cnt.fetch_add(1, memory_order_relaxed);



            //int cp{ cnt }, neu;
            //do {
            //    neu = cp + 1;
            //} while (!cnt.compare_exchange_weak(cp, neu));
        }
    }
}

int main()
{
    using namespace ct;

    cout << "atomic<int> ist wirklich atomar: " << boolalpha << cnt.is_lock_free() << endl;

    auto start = steady_clock::now();
    vector<thread> v;
    for (int i = 0; i < 10; ++i)
        v.emplace_back(inc);

    for (thread& t : v)
        t.join();
    auto finish = steady_clock::now();
    cout << "cnt = " << cnt << endl;
    cout << "Dauer " << duration_cast<microseconds>(finish - start).count() / 1000.0 << "ms.\n";

}

