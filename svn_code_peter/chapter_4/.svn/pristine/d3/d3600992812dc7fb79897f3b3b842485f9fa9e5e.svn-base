#include <iostream>
#include <string>

using namespace std;

namespace ct {


    class person
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
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    person mark{"Mark Markson"};
    mark.all_info();

    student rob{"Rob Robson", "Algebra"};
    rob.all_info();

    person  orob{rob}; // Slicing, nur Personteil kopiert
    person& rrob{rob};
    person* zrob{&rob};

    orob.all_info();
    rrob.all_info();
    zrob->all_info();

    person* knut= new student{"Knut Knutson", "Analysis, Algebra, ................................................................"};
    knut->all_info();

    delete knut;

    return 0;
}
  
 
