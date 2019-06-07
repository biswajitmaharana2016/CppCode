// thread_is_prime.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>

using namespace std;

namespace ct {

    bool is_prime(size_t i)
    {
        if (i == 1)
            return false;
        if (i % 2 == 0)
            return i == 2;
        size_t max_check = i;
        for (size_t j = 3; j < max_check; j += 2)
            if (i % j == 0)
                return false;
        return true;
    }

}

int main(int argc, char** argv)
{
    using namespace ct;

    int num_threads = 2;
    if (argc > 1)
        num_threads = stoi(argv[1]);

    vector<size_t> vi;
    size_t tv = 982'451'653;
    for (int i = 0; i < num_threads; ++i, tv+= 2)
        vi.push_back(tv);

    vector<thread> threads;
    vector<short>  results(num_threads);
    for (int i = 0; i < num_threads; ++i)
        threads.emplace_back([&results, i, &vi]() { results[i] = is_prime(vi[i]); });
        // threads.push_back(thread{ [&results, i, &vi]() { results[i] = is_prime(vi[i]); } });

    cout << "Alles gestartet" << endl;
    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
        cout << vi[i] << " ist " << (results[i] ? "eine" : "keine") << " Primzahl.\n";
    }


}