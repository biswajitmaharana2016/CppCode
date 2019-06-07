#include <iostream>
#include <string>

using namespace std;

namespace mv {

    struct picture_grabber
    {
      public:
	virtual void all_info() const = 0;
	virtual ~picture_grabber() {}
    };
    
    class camera
      : public picture_grabber
    {
      public:
	explicit camera(string name) : name{name} {}

        virtual void all_info() const
	{
	    cout << "Der Name ist " << name << ".\n";
	}

	virtual ~camera() = default;

	string get_name() const { return name; }
      private:
	string name;
    };

    class industrial
      : public camera
    {
      public:
	explicit industrial(string name, string ss)
	  : camera{name}, ss{ss} {}

	virtual void all_info() const override
	{
	    cout << "Der Name ist " << get_name() << ".\n";
	    cout << "Schnittstelle ist " << ss << ".\n";
	}
	
      private:
	string ss;
    };

    void tellme(const picture_grabber& p)
    {
	p.all_info();
    }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    camera sirius{"Sirius"};
    sirius.all_info();
    tellme(sirius);

    industrial fox{"Fox", "USB 3.1"};
    fox.all_info();
    tellme(fox);

    camera& fox_ref{fox};
    camera* fox_ptr{&fox};

    fox_ref.all_info();
    fox_ptr->all_info();

    // picture_grabber pg;
    
    return 0;
}
  
 
