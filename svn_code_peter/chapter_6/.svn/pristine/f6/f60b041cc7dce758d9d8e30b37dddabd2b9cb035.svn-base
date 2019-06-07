// Bereichs_for.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>


using namespace std;

namespace ct {

    class iiter
    {
    public:
        explicit iiter(int i) : i{i} {}

        bool operator!=(iiter that) const { return i != that.i; }

        iiter& operator++() { ++i; return *this; }

        iiter operator++(int)
        {
            iiter cp{ *this };
            i++;
            return cp; 
        }

        int operator*() const { return i; }
    private:
        int i;
    };

    class irange
    {
    public:
        irange(int from, int to): from{from}, to{to} {}

        iiter begin() const {
            return iiter{ from };
        }
        iiter end()  {
            return iiter{ to };
        }
    private:
        int from, to;
    };
}

int main()
{
    using namespace ct;

    for (int i : irange{ 1, 11 })
        cout << i << endl;

    irange r{ 1, 11 };
    for (auto it = begin(r); it != end(r); it++) {
        int i = *it;
        cout << i << endl;
    }

#if 0
    A[3][7];
    sub_matrix(A, 3, 9, 11, 17);
    A[irange{ 3,9 }][irange{ 11,17 }];
    
    for (int i : irows(A)) {
        irange r{ i+1, iend };
        A[r][i] /= A[i][i];
        A[r][r] -= A[r][i] * A[i][r];
    }
#endif
}

