#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

namespace vit {

}

int main(int argc, char** argv)
{
    using namespace vit;

    string s1;
    s1.reserve(106);
    s1= "Hallo";
    
    for (int i = 0; i < 100; ++i) {
        s1 += "o";
        cout << "Laenge: " << s1.size() << ", Kapazitaet: " << s1.capacity() << endl;
    }

    s1 = "Ferdsch";
    cout << "Laenge: " << s1.size() << ", Kapazitaet: " << s1.capacity() << endl;
    s1.shrink_to_fit();
    cout << "Laenge: " << s1.size() << ", Kapazitaet: " << s1.capacity() << endl;
}