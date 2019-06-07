// call_once_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <mutex>

using namespace std;

namespace ct {

    class lookup_table
    {
        static void setup(int p1, int p2) { /*... */ }
    public:
        lookup_table(int p1, int p2)
        {
            call_once(initialized, setup, p1, p2);
        }

        int lookup(unsigned char i) const { return table[i]; }
    private:
        static int table[256];
        static once_flag initialized;
    };

    once_flag lookup_table::initialized{};
}

int main()
{
    using namespace ct;

    lookup_table table{ 3, 6 }; // pro Thread

}