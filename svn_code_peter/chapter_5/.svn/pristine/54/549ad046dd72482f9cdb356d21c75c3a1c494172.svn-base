// oop1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

namespace vit {

    class camera
    {
    public:
        camera(string name) : name{name} {}

        void all_info() const
        {
            cout << "Der Name der Kamera ist " << name << ".\n";
        }

        string get_name() { return name;  }
    private:
        string name;
    };

    class sw : public camera
    {
    public:
        sw(string name, string aufl) : camera{name}, aufl{aufl} {}

        void all_info()
        {
            cout << "Der Name der Kamera ist " << get_name() << ".\n";
            cout << "Die Aufloesung ist " << aufl << ".\n";
        }
    private:
        string aufl;
    };
}

int main(int argc, char** argv)
{
    using namespace vit;

    camera sony{ "Sony" };
    sony.all_info();

    sw mv{ "Matrix Vision", "1920x1200" };
    mv.all_info();
}