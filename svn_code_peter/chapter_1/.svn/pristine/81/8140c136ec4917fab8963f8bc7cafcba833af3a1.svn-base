#include <iostream>
#include <string>

using namespace std;

namespace mv {

    class camera
    {
      public:
	explicit camera(string name) : name{name} {}

	void all_info() const
	{
	    cout << "Der Name ist " << name << ".\n";
	}
      private:
	string name;
    };

}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    camera sirius{"Sirius"};
    sirius.all_info();
    
    return 0;
}
  
 
