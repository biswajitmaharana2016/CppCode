// Funktionstemplate.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

namespace vit {

    template <typename T>
    T maxi(T x, T y)
    {
        return x >= y ? x : y;
    }
    
    // template int maxi(int, int); // instanziiere fuer int, selten gebraucht
}

int main(int argc, char** argv)
{
    using namespace vit;

    cout << "maxi(3, 7) = " << maxi(3, 7) << endl;
    cout << "maxi(3l, 7l) = " << maxi(3l, 7l) << endl;
    cout << "maxi(3.0, 7.0) = " << maxi(3.0, 7.0) << endl;

    // cout << "maxi(3l, 7.0) = " << maxi(3l, 7.0) << endl;

    cout << "maxi(3l, 7.0) = " << maxi(static_cast<double>(3l), 7.0) << endl;
    cout << "maxi(3l, 7.0) = " << maxi(double(3l), 7.0) << endl; // Ktor bei Klassen, C-Cast bei intr. Typen

    cout << "maxi(3l, 7.0) = " << maxi<long double>(3l, 7.0) << endl; // beide zu long double konvertiert
    cout << "maxi(Hallo, Welt) = " << maxi(std::string{ "Welt" }, "Hallo"s) << endl;
}