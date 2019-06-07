#include "pch.h"
#include <iostream>
#include <string>


namespace vit {

    inline int square(int i) { return i * i; }

    namespace {

        int cubic(int i) { return i * i * i; }
    }
}

int main(int argc, char** argv)
{
    using namespace vit;
    using namespace std;

    cout << "Unser Executable heisst " << argv[0] << endl;

    std::cout << "Das Quadrat von 9 ist " << square(9) << endl;
    std::cout << "Die 3. Potenz von 9 ist " << cubic(9) << endl;

    if (argc > 1) {
        int i = stoi(argv[1]);
        std::cout << "Das Quadrat von " << i << " ist " << square(i) << endl;
    }
}

