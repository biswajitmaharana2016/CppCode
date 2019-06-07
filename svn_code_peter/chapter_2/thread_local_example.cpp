#include <iostream>
#include <thread>

using namespace std;

namespace sn {

    void f()
    {
	int              i{0};
	thread_local int t{0};
	static int       s{0};
	cout << "Auf Thread " << this_thread::get_id() 
	     << ": i = " << i << ", t = " << t << ", s = "
	     << s << endl;
	++i; ++t; ++s;
    }
    
    void g() { f(); f(); }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    g();
    thread t1{g};
    thread t2{g};

    t1.join();
    t2.join();

    return 0;
}
  
 
