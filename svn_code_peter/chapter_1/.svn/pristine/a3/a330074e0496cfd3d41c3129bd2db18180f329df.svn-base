#include <iostream>
#include <string>

using namespace std;

namespace mv {
    
    class camera
    {
      public:
	explicit camera(string name) : name{name} {}

        virtual void all_info() const
	{
	    cout << "Der Name ist " << name << ".\n";
	}

	virtual ~camera() = default;

	string get_name() const { return name; }
	string get_name(string s) const { return name + s; }
      private:
	string name;
    };

    class industrial
      : public camera
    {
	using camera::get_name;
      public:
	explicit industrial(string name, string ss)
	  : camera{name}, ss{ss} {}

	string get_name(float f) const { return "float"; }
	
	virtual void all_info() const override
	{
	    cout << "Der Name ist " << get_name() << ".\n";
	    cout << "Schnittstelle ist " << ss << ".\n";
	}
	
      private:
	string ss;
    };

    void f(double){}

}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    camera sirius{"Sirius"};
    sirius.all_info();

    industrial fox{"Fox", "USB 3.1"};
    fox.all_info();

    camera  fox_copy{fox}; // Slicing
    camera& fox_ref{fox};
    camera* fox_ptr{&fox};

    fox_copy.all_info();
    fox_ref.all_info();
    fox_ptr->all_info();

    camera* fox_factory{new industrial{"Fox", "USB 3.1 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"}};
    fox_factory->all_info();

    delete fox_factory;

    industrial& iref1= static_cast<industrial&>(fox_ref);
    industrial& iref2= dynamic_cast<industrial&>(fox_ref);

    industrial& iref3= static_cast<industrial&>(sirius);
    // iref3.all_info();

    try {
	industrial& iref4= dynamic_cast<industrial&>(sirius); // wirft std::bad_cast
    } catch (std::bad_cast& ) { cout << "Geht nicht.\n"; }

    industrial* pref= dynamic_cast<industrial*>(&sirius);
    if (pref == nullptr)
	 cout << "Geht auch nicht.\n";

    int i{7};
    f(double(i));
    f(static_cast<double>(i));
    
    return 0;
}
  
 
