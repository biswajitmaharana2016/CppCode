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

    class mathematician
      : public person
    {
      public:
	mathematician(string name, string proved) : person{name}, proved{proved} {}
    
	virtual void all_info() const override
	{
	    cout << "Mein Name ist " << get_name() << ".\n";
	    cout << "Ich bewies " << proved << ".\n";
	}
	
      private:
	string proved;
    };

    class math_student
      : public student, public mathematician
    {
      public:
	math_student(string name, string passed, string proved)
	  : student{name + " [s]", passed}, mathematician{name + " [m]", proved} {}

	virtual void all_info() const override
	{
	    student::all_info();
	    mathematician::all_info();
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

    // tellme(james);
    
    return 0;
}
  
 
