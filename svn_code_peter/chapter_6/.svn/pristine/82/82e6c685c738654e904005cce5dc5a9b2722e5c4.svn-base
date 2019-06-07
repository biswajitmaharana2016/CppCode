// array_lock_guard.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <mutex>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

namespace ct {

    template <size_t N>
    class array_lock_guard
    {
        template <size_t ...I>
        void lock_all(index_sequence<I...>)
        {
            // lock(mutexes[0], mutexes[1], ..., mutexes[N - 1]);
            lock(mutexes[I]...);
        }

    public:
        array_lock_guard(array<mutex, N>& mutexes) : mutexes{mutexes} 
        {           
            // index_sequence<0, 1, ..., N - 1>;
            lock_all(make_index_sequence<N>{});   
        }

        ~array_lock_guard()
        {
            for (mutex& m : mutexes)
                m.unlock();
        }

    private:
        array<mutex, N>& mutexes;
    };

    array<mutex, 8> global_mutexes;

    void task(int id, int ms)
    {
        array_lock_guard alg{global_mutexes};
        cout << "Start task " << id << endl;
        this_thread::sleep_for(chrono::milliseconds(ms));
        cout << "Beende task " << id << endl;
    }


}

int main()
{
    using namespace ct;

    auto f1 = async(task, 1, 1000);
    this_thread::sleep_for(500ms);
    auto f2 = async(task, 2, 200);

    f1.wait();
    f2.wait();

}

