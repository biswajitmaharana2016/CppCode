#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <future>
#include <chrono>

using namespace std;

namespace mv {

    struct trivial {};
    
    bool is_prime(long i)
    {
	if (i % 10 == 5 && i != 5)
	    throw trivial{}; 
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	long max_check= i; // Wurzel ginge zu schnell
	for (unsigned j= 3; j < max_check; j+= 2)
	    if (i % j == 0)
		return false;
	return true;
    }

    template <typename ...T> class ptask;

    template <typename Ret, typename ...Args>
    class ptask<Ret(Args...)>
    {
	using ft= function<Ret(Args...)>;
      public:
	ptask(ft f) : f{f}, p{} {}

	void operator()(Args&& ...a)
	{
	    try {
		p.set_value_at_thread_exit( f(forward<Args>(a)...) );
	    } catch (...) {
		p.set_exception_at_thread_exit( current_exception() );
	    }
	}
	future<Ret> get_future() { return p.get_future(); }
	
      private:
	ft           f;
	promise<Ret> p;
    };
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    int num_threads= 2;
    if (argc > 1)
	num_threads= stoi(argv[1]);
    
    vector<long> vl;
    long first_prime= 982'451'653;
    for (long i= 0, v= first_prime; i < num_threads; ++i, v+=2)
	vl.push_back(v);

    vector<future<bool>> vf;
    for (long i= 0; i < num_threads; ++i) {
	ptask<bool(long)> pt{is_prime};
	vf.push_back(pt.get_future());
	thread{move(pt), vl[i]}.detach();
    }	

    cout << "Alles gestartet." << endl;

    for  (long i= 0; i < num_threads; ++i) {
	while (vf[i].wait_for(200ms) != future_status::ready)
	    cout << "Das dauert!!!" << endl;
	try {
	    bool it_is= vf[i].get();
	    cout << vl[i] << " ist " << (it_is ? "eine" : "keine") << " Primzahl.\n";
	} catch(trivial) {
	    cout << vl[i] << " ist offensichtlich keine Primzahl.\n";
	}
    }
			
    return 0;
}
  
 
