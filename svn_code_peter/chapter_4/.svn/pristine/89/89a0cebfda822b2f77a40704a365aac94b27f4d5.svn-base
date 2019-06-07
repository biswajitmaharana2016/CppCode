#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <array>
#include <mutex>

using namespace std;

namespace le {

    template <size_t N>
    class array_lock_guard
    {
	template <size_t ...I>
	void lock_all(index_sequence<I...>)
	{
	    // lock(mutexes[0], mutexes[1], ..., mutexes[N-1]);
	    lock(mutexes[I]...);
	}

      public:
	array_lock_guard(array<mutex, N>& mutexes) : mutexes{mutexes}
	{
	    // index_sequence<0, 1, ..., N-1>;
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
    
    std::array<mutex, 16> mutexes;
    
    void task(int id, int ms)
    {
	array_lock_guard   alg{mutexes};
	cout << "Starte Aufgabe " << id << endl;
	this_thread::sleep_for(chrono::milliseconds(ms));
	cout << "Beende Aufgabe " << id << endl;
    }
 
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    future<void> f1= async(task, 1, 1000);
    this_thread::sleep_for(500ms);
    future<void> f2= async(task, 2, 200);

    f1.wait();
    f2.wait();
    

    return 0;
}
  
 
