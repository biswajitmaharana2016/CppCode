#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <chrono>

#include <thread>
#include <future>

#include "irange.hpp"

using namespace std;

namespace sn {

    struct obvious {};
    
    bool is_prime(size_t i)
    {
	if (i % 10 == 5 && i != 5)
	    throw obvious{};
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	for (size_t j= 3; j < i; j+=2)
	    if (i % j == 0)
		return false;
	return true;
    }

    template <typename ...T> class ptask;

    template <typename Ret, typename ...Args>
    class ptask<Ret(Args...)>
    {
	using ftype= std::function<Ret(Args...)>;
      public:
	ptask(ftype fn) : fn{move(fn)} {}

	void operator()(Args&& ...args)
	{
	    try {
		p.set_value_at_thread_exit( fn(forward<Args>(args)...) );
	    } catch (...) {
		p.set_exception_at_thread_exit( current_exception() );
	    }
	}

	future<Ret> get_future() { return p.get_future(); }
	
      private:
	ftype        fn;
	promise<Ret> p;
    };
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    int num_threads= 2;
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<size_t> vi;
    for (size_t i= 0, v= 982'451'653; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<future<bool>> futures;
    for (size_t i : vi) {
	ptask<bool(size_t)> p{is_prime};
	futures.push_back(p.get_future());
	thread{move(p), i}.detach();
    }
    
    cout << "Alle Threads gestartet." << endl;

    for (size_t i : irange{0, num_threads}) {
	while (futures[i].wait_for(200ms) != future_status::ready)
	    cout << "Das dauert!!!!!" << endl;
	try {
	    bool it_is= futures[i].get();
	    cout << vi[i] << " ist " << (it_is ? "eine" : "keine") << " Primzahl.\n";
	} catch (obvious) {
	    cout << vi[i] << " ist offensichtlich keine Primzahl.\n";
	}
    }
    
    return 0;
}
  
 
