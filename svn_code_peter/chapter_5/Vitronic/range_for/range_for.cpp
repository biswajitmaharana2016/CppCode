#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace vit {

    class iiter
    {
    public:
        iiter(int i) : i(i) {}

        
        iiter& operator++() { ++i; return *this; }
        int operator*() const { return i; }

        // Postfix mit Dummy-Argument
        iiter operator++(int)
        {
            iiter cp(*this);
            i++;
            return cp;
        }

    private:
        int i;
    };

    bool operator!=(iiter i1, iiter i2) { return *i1 != *i2; }

    class irange
    {
    public:
        irange(int from, int to) : from(from), to(to) {}

        iiter begin() const { return iiter(from); }
        iiter end() const { return iiter(to); }
    private:
        int from, to;
    };

    void f(int) { cout << "f(int)\n"; }
    void f(irange) { cout << "f(irange)\n"; }

    template <typename T>
    void g(T& x, T& y)
    {
        // ...

        // Tausche x und y
        std::swap(x, y); // Nimm die Funktion aus std

        using std::swap;
        swap(x, y);      // Nimm beste Funktion aus std und Namensraum von T
        // ...
    }

    namespace inner {

        // inneres g verbirgt aeusseres
        void g(int i) {
            f(i);       // aus aeusserem Namensraum
        }


        // machen aeusseres wieder sichtbar
        using vit::g;
        void h() { int i = 3, j = 4; g(i, j); }
    }

}

int main(int argc, char** argv)
{
    // using namespace vit;

    const vit::irange ir(1, 11);
    vit::f(3);       // nur mit Namensraum gefunden
    vit::f(ir);           // ueber ADL

    for (int i : vit::irange(1, 11))
        cout << i << "\n";
    cout << endl;

    vit::iiter start = begin(ir);
    cout << "start = " << *start++ << endl;

 
   for (auto it = begin(ir); it != end(ir); it++) {
        int i = *it;
        cout << i << "\n";
    }
    cout << endl;

    for (auto it = ir.begin(); operator!=(it, ir.end()); it.operator++()) {
        int i = it.operator*();
        cout << i << "\n";
    }
    cout << endl;

    int a[] = { 7, 4, 9, 11 };
    for (int i : a)
        cout << i << "\n";
    cout << endl;

#if 0
    A[3][9];
    sub_matrix(A, 3, 7, 9, 14);
    A[irange(3, 7)][irange(9, 14)];
    irange rr(3, 7), cr(9, 14);
    A[rr][cr] + B[rr][cr];
#endif // 0

    vector<int> v{ 3, 9, 4, 7, 11 };
    for (int i : v)
        cout << "i = " << i << endl;

    map<string, int> telefon{ {"Galina", 7167}, {"Robert", 4711}, {"Daniel", 7404} };
    for (pair<const string, int> t : telefon)
        cout << t.first << "s Nummer ist " << t.second << ".\n";

}