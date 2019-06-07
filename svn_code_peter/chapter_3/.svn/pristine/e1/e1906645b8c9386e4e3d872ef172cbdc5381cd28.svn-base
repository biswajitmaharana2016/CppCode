#include <iostream>

using namespace std;

namespace le {

    class iiter
    {
      public:
	explicit iiter(int i) : i{i} {}

	bool operator!=(iiter that) const { return i != that.i; }
	int operator*() const { return i; }
	
	iiter& operator++() { ++i; return *this; }

	iiter operator++(int) {
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
	explicit irange(int from, int to) : from{from}, to{to} {}

	iiter begin() const { return iiter{from}; }
	iiter end()   const { return iiter{to}; }
      private:
	int from, to;
    };

}

int main (int argc, char* argv[]) 
{
    using namespace le;
    
    const irange rr{4, 8};
    for (int i : rr)
	cout << i << endl;

    for (auto it= begin(rr); it != end(rr); it++) {
	int i= *it;
	cout << i << endl;
    }




#if 0
    A[3][6]; // a_{3,6}
    sub_matrix(A, 4, 8, 9, 12);
    A[irange{4, 8}][irange{9, 12}];

    const irange rr{4, 8}, rc{9, 12};
    A[rr][rc];
#endif
    
    return 0;
}
  
 
