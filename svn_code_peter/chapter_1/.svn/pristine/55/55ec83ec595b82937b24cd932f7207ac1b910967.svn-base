#include <iostream>
#include <array>
#include <mutex>
#include <thread>
#include <chrono>
#include <future>
#include <utility>

using namespace std;

namespace le {

    // Etwa so
    // template <std::size_t ...I>
    // struct index_sequence {};
    
    template <unsigned N>
    class array_lock_guard
    {
	template <std::size_t ...I> // I = 0, 1, ..., N-1
	void lock_all(index_sequence<I...>)
	{
	    // lock(mutexes[0], ..., mutexes[N-1]);
	    lock(mutexes[I]...);
	}
		      
      public:
	array_lock_guard(array<mutex, N>& mutexes) : mutexes(mutexes)
	{
	    // lock_all(index_sequence<0, 1, 2, ..., N-1>{});
	    lock_all(std::make_index_sequence<N>{});
	}

	~array_lock_guard()
	{
	    for (auto& m : mutexes)
		m.unlock();
	}
      private:
	array<mutex, N>& mutexes;
    };

    template <unsigned N>
    array_lock_guard(array<mutex, N>&) -> array_lock_guard<N>;
    
    
    array<mutex, 8> global_mutexes;

    void task(int id, int ms)
    {
	array_lock_guard<8> alg(global_mutexes);
	cout << "Start task " << id << endl;
	this_thread::sleep_for(chrono::milliseconds(ms));
	cout << "Finished task " << id << endl;
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    future<void> f1= async(task, 1, 1000);
    this_thread::sleep_for(500ms);
    cout << "Launch task 2." << endl;
    future<void> f2= async(task, 2, 100);

    f1.wait();
    f2.wait();
    
    return 0;
}
  
 
