// filesystem_example.cpp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
#include "pch.h"

#include <string>
#include <iostream>

#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

int main(int argc, char* argv[])
{
    std::string path = ".";
    if (argc > 1)
        path = argv[1];
    for (auto & p : fs::directory_iterator(path))
        if (is_regular_file(p))
            cout << p.path() << " is a regular file.\n";
        else if (is_directory(p))
            cout << p.path() << " is a directory.\n";
        else
            cout << p.path() << " is neither regular file nor directory.\n";

    return 0;
}

