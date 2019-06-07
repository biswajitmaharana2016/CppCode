// thread_local_example.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <thread>

using namespace std;

namespace le {

    void f()
    {
        int              i{ 0 };
        thread_local int t{ 0 };
        static int       s{ 0 };
        cout << "On Thread " << this_thread::get_id()
            << ": i = " << i << ", t = " << t << ", s = "
            << s << endl;
        ++i; ++t; ++s;
    }

    void g() { f(); f(); }
}

int main(int argc, char* argv[])
{
    using namespace le;

    g();
    thread t1{ g };
    thread t2{ g };

    t1.join();
    t2.join();

    return 0;
}


