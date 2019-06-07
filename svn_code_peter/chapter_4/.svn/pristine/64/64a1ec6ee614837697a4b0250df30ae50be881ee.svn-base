#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <functional>
#include <future>
#include <chrono>
#include <typeinfo>

using namespace std;

namespace ct {

    struct trivial {};

    bool is_prime(size_t i)
    {
	if (i % 10 == 5 && i != 5)
	    throw trivial{};
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	// bis Wurzel reichen, aber dann zu schnell
	for (size_t j= 3; j < i; j+= 2)
	    if (i % j == 0)
		return false;
	return true;
    }

    template <typename T> class ptask;

    template <typename Ret, typename ...Args>
    class ptask<Ret(Args...)>
    {
	using ftype= function<Ret(Args...)>;
      public:
	ptask(ftype f) : f{f} {}

	template <typename ...A>
	void operator()(A&& ...args)
	{
	    try {
		p.set_value_at_thread_exit( f(forward<A>(args)...) );
	    } catch (...) {
		p.set_exception_at_thread_exit( current_exception() );
	    }
	}

	future<Ret> get_future() { return p.get_future(); }
	
      private:
	ftype        f;
	promise<Ret> p;
    };
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // cout << typeid(200.0h).name() << endl;
    // return 0;

    size_t num_threads= 2;
    if (argc > 1)
	num_threads= stoul(argv[1]);

    vector<size_t>     vi;
    for (size_t i= 0, v= 982'451'653; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<future<bool>> futures;
    for (size_t v : vi) {
	ptask<bool(size_t)> p{is_prime};
	futures.push_back(p.get_future());
	thread{move(p), v}.detach();
    }
 
    cout << "Alles gestartet" << endl;

    for (size_t i= 0; i < num_threads; ++i) {
	while (futures[i].wait_for(200ms) != future_status::ready)
	    cout << "Das dauert!!!" << endl;
	try {
	    bool is_it= futures[i].get();
	    cout << vi[i] << " ist " << (is_it ? "eine" : "keine") << " Primzahl.\n";
	} catch (trivial) {
	    cout << vi[i] << " ist offensichtlich keine Primzahl.\n";
	}
    }

    return 0;
}
  
 
