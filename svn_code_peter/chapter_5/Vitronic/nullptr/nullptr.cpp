#include "pch.h"
#include <iostream>

using namespace std;

namespace vit {

    void f(long) { cout << "long\n"; }
    void f(int*) { cout << "int*\n"; }
}

int main(int argc, char** argv)
{
    using namespace vit;
    // f(0);
    // f(NULL);
    f(0l);
    f(nullptr);

    int* ip = nullptr;
    if (ip == nullptr)
        cout << "ip ist tatsaechlich leer.\n";

 }