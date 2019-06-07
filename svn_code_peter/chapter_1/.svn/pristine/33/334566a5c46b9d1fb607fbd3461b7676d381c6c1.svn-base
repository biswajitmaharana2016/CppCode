#include <iostream>
#include <mutex>

using namespace std;

namespace le {

    class lookup_table
    {
      public:
	lookup_table(int para1, int para2)
	{
	    call_once(initialized, setup, para1, para2);
	}

	static void setup(int para1, int para2) { /* ... */ }

	int lookup(int i) const { return table[i]; }
      private:
	static int table[256];
	static std::once_flag initialized;
    };
    std::once_flag lookup_table::initialized;
    
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    lookup_table table(3, 6); // per Thread

    return 0;
}
  
 
