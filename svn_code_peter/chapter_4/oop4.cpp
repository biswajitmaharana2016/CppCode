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
	    my_info();
	}

	void my_info() const
	{
	    cout << "Mein Name ist " << name << ".\n";
	}
      private:
	string name;
    };

    class student
      : virtual public person
    {
      protected:
	student(string passed) : person{""}, passed{passed} {}
      public:
	student(string name, string passed) : person{name}, passed{passed} {}

	virtual void all_info() const override
	{
	    person::my_info();
	    my_info();
	}
	void my_info() const
	{
	    cout << "Ich bestand " << passed << ".\n";
	}
		
      private:
	string passed;
    };

    class mathematician
      : virtual public person
    {
      protected:
	mathematician(string proved) : person{""}, proved{proved} {}
      public:
	mathematician(string name, string proved) : person{name}, proved{proved} {}
    
	virtual void all_info() const override 
	{
	    person::my_info();
	    my_info();
	}

	void my_info() const
	{
	    cout << "Ich bewies " << proved << ".\n";
	}
	
      private:
	string proved;
    };

    class math_student final
      : public student, public mathematician
    {
      public:
	math_student(string name, string passed, string proved)
	  : person{name + " [p]"}, student{passed}, mathematician{proved} {}

	void all_info() const override final
	{
	    student::all_info();
	    mathematician::my_info();
	}
    };

    void tellme(const creature& c)
    {
	c.all_info();
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    math_student james{"James Jameson", "Analysis", "P != NP"};
    james.all_info();
    cout << endl;

    tellme(james);
    cout << endl;

    student& sjames= james;

    math_student& stjames= static_cast<math_student&>(sjames);
    math_student& djames=  dynamic_cast<math_student&>(sjames);

    student rob{"Rob", "Algebra"};
    
    math_student& strob= static_cast<math_student&>(rob);
    rob.all_info(); // undefiniertes Verhalten

    try {
	math_student& drob= dynamic_cast<math_student&>(rob);
    } catch (std::bad_cast&) {
	cout << "Schlimmer Cast. Mach trotzdem weiter.\n";
    }

    math_student* prob= dynamic_cast<math_student*>(&rob);
    if (prob == nullptr)
	cout << "Schlimmer Cast. Mach trotzdem weiter.\n";
    
    return 0;
}
  
 
