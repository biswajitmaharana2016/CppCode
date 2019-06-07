#include <iostream>
#include <string>

using namespace std;

namespace ct {

    class creature
    {
      public:
	virtual void all_info() const = 0;
	virtual ~creature() {}
    };

    class person
      : public creature
    {
      public:
	person(string name) : name{name} {}

	virtual ~person() {}
	
	virtual void all_info() const
	{
	    cout << "Mein Name ist " << name << ".\n";
	}

	string get_name() const { return name; }
      private:
	string name;
    };

    class student
      : public person
    {
      public:
	student(string name, string passed) : person{name}, passed{passed} {}

	virtual void all_info() const override
	{
	    cout << "Mein Name ist " << get_name() << ".\n";
	    cout << "Ich bestand " << passed << ".\n";
	}
	
      private:
	string passed;
    };

    void tellme(const creature& c)
    {
	c.all_info();
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // creature c;
    
    person mark{"Mark Markson"};
    mark.all_info();

    student rob{"Rob Robson", "Algebra"};
    rob.all_info();

    tellme(rob);

    creature& rrob{rob};
    creature* zrob{&rob};

    rrob.all_info();
    zrob->all_info();

    creature* knut= new student{"Knut Knutson", "Analysis, Algebra, ................................................................"};
    knut->all_info();

    delete knut;

    return 0;
}
  
 
