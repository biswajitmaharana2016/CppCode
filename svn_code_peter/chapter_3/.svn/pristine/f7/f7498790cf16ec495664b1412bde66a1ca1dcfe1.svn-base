#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <functional>
#include <future>
#include <chrono>

using namespace std;

namespace le {

    struct trivial {};
    
    bool is_prime(size_t n)
    {
	if (n % 10 == 5 && n != 5)
	    throw trivial{};
	if (n == 1)
	    return false;
	if (n % 2 == 0)
	    return n == 2;
	for (size_t j= 3; j < n; j+= 2)
	    if (n % j == 0)
		return false;
	return true;
    }

    template <typename T> class ptask;

    template <typename Ret, typename ...Args>
    class ptask<Ret(Args...)>
    {
	using ftype= function<Ret(Args...)>;
      public:
	ptask(ftype fn) : fn(move(fn)) {}

	void operator()(Args... args)
	{
	    try {
		p.set_value_at_thread_exit( fn(args...) );
	    } catch (...) {
		p.set_exception_at_thread_exit( std::current_exception() );
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
    using namespace le;

    int num_threads{2};
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<size_t> vi;
    for (int i= 0, v= 982'451'653; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<future<bool>> futures;
    for (size_t v : vi) {
	ptask<bool(size_t)> p{is_prime};
	futures.push_back( p.get_future() );
	thread{move(p), v}.detach();
    } 

    cout << "Everything started." << endl;

    for (int i= 0; i < num_threads; ++i) {
	while (futures[i].wait_for(200ms) != future_status::ready)
	    cout << "I'm bored! Get ready!" << endl;
	try {
	    bool it_is= futures[i].get();
	    cout << vi[i] << " is " << (it_is ? "" : "not ") << "a prime number.\n";
	} catch (trivial) {
	    cout << vi[i] << " is obviously not a prime number.\n";
	}
    }
    
    return 0;
}
  
 
