#include <iostream>
#include "irange.hpp"

using namespace std;

int main (int argc, char* argv[]) 
{
    using namespace sn;

    // A[4][6];
    // sub_matrix(A, 3, 7, 9, 12);
    // A[irange(3, 7)][irange(9, 12)];
    // irange rr(3, 7), rc(9, 12);
    // A[rr][rc];
    // A[4][rc]; // Zeilenvektor

    for (int i : irange{1, 11})
	cout << "i = " << i << endl;

    const irange ir{1, 11};
    for (auto it= begin(ir); it != end(ir); ++it) {
	int i= *it;
	cout << "i = " << i << endl;
    }

    int arr[]= {1, 9, 13, 98, 99};
    for (int i : arr)
	cout << "i = " << i << endl;

    return 0;
}
  
 
