#include <iostream>
#include <mutex>

using namespace std;

namespace sn {

    class lookup_table
    {
	static void setup(int para1, int para2) { /* ... */ }
      public:

	lookup_table(int para1, int para2)
	{
	    call_once(initialized, setup, para1, para2);
	}

	static int lookup(unsigned char i) { return table[i]; }
	
      private:
	static int       table[256];
	static once_flag initialized;
    };

    once_flag lookup_table::initialized{};
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    lookup_table table{3, 6}; // pro Thread

    return 0;
}
  
 
