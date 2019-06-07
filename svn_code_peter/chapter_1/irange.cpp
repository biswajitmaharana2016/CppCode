#include <iostream>

using namespace std;

namespace mv {

    class iiter
    {
      public:
	explicit iiter(int i) : i{i} {}

	bool operator!=(iiter that) const { return i != that.i; }
	iiter& operator++() { ++i; return *this; }
	int operator*() const { return i; }
	
	iiter operator++(int)
	{
	    iiter cp{*this};
	    i++;
	    return cp;
	}
      private:
	int i;
    };

    class irange
    {
      public:
	irange(int from, int to) : from{from}, to{to} {}

	iiter begin() const { return iiter{from}; }
	iiter end() const { return iiter{to}; }
	
      private:
	int from, to;
    };
    
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    // sub_matrix(A, 3, 7, 9, 14);
    // Element: A[3][9]
    // A[irange(3, 7)][irange(9, 14)];

    for (int i : irange(1, 11))
	cout << i << endl;

    irange r(1, 11);
    for (auto it= begin(r); it != end(r); it++) {
	int i= *it;
	cout << i << endl;
    }	
    
    return 0;
}
  
 
