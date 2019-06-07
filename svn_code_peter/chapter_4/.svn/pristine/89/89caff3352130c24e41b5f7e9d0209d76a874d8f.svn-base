#include <iostream>

using namespace std;

namespace ct {

    class iiter
    {
      public:
	explicit iiter(int i) : i{i} {}

	bool operator!=(iiter that) const { return i != that.i; }
	iiter& operator++() { ++i; return *this; }
	int operator*() const { return i; }

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
	iiter end() const { return iiter{to}; }
      private:
	int from, to;
    };
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    for (int i : irange{1, 11})
	cout << i << endl;

    irange ir{1, 11};
    for (auto it= begin(ir); it != end(ir); it++) {
	int i= *it;
	cout << i << endl;
    }

#if 0
    A[3][5];
    sub_matrix(A, 3, 9, 12, 17);
    A[irange{3, 9}][irange{12, 17}];
    irange rr{3, 9}, cr{12, 17};
    A[rr][cr];
#endif
    
    return 0;
}
  
 
