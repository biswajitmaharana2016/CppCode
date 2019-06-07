// async_is_prime.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

namespace ct {

    struct trivial {};

    bool is_prime(size_t i)
    {
        if (i % 10 == 5 && i != 5)
            throw trivial{};
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
    for (int i = 0; i < num_threads; ++i, tv += 2)
        vi.push_back(tv);

    vector<future<bool>> futures;
    for (int i = 0; i < num_threads; ++i)
        futures.push_back(async(launch::async, is_prime, vi[i]));
    cout << "Alles gestartet" << endl;

    for (int i = 0; i < num_threads; ++i) {
        while (futures[i].wait_for(200ms) != future_status::ready)
            cout << "Das dauert!!!" << endl;
        try {
            bool it_is = futures[i].get();
            cout << vi[i] << " ist " << (it_is ? "eine" : "keine") << " Primzahl.\n";
        }
        catch (trivial) {
            cout << vi[i] << " ist offensichtlich keine Primzahl.\n";
        }
    }


}