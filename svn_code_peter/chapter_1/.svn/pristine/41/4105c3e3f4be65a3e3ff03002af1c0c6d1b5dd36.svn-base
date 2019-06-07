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
	explicit camera(string name= "") : name{name} {}

        virtual void all_info() const
	{
	    my_info();
	}

	void my_info() const
	{
	    cout << "Der Name ist " << name << ".\n";
	}
	
	virtual ~camera() = default;
     private:
	string name;
    };

    class industrial
      : virtual public camera
    {
      protected:
	explicit industrial(string ss) : camera{}, ss{ss} {}
      public:
	explicit industrial(string name, string ss)
	  : camera{name}, ss{ss} {}

	virtual void all_info() const override
	{
	    camera::my_info();
	    my_info();
	}
	
	void my_info() const
	{
	    cout << "Schnittstelle ist " << ss << ".\n";
	}
	
      private:
	string ss;
    };

    class smart
      : virtual public camera
    {
      protected:
	explicit smart(string os) : camera{}, os{os} {}
	
      public:
	explicit smart(string name, string os)
	  : camera{name}, os{os} {}
	    
	virtual void all_info() const override
	{
	    camera::my_info();
	    my_info();
	}

	void my_info() const
	{
	    cout << "Das OS ist " << os << ".\n";
	}
	
      private:
	string os;
    };

    class vision final
      : public industrial, public smart
    {
      public:
	explicit vision(string name, string ss, string os)
	  : camera{name}, industrial{ss}, smart{os} {}
	    
	virtual void all_info() const override final
	{
	    industrial::all_info();
	    smart::my_info();
	}
    };
    
    void tellme(const picture_grabber& p)
    {
	p.all_info();
    }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    vision baukasten{"Baukasten", "USB 4.0", "Windux"};
    baukasten.all_info();
    cout << endl;

    tellme(baukasten);
    
    return 0;
}
  
 
