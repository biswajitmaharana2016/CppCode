// oop3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

namespace vit {

    class geraet
    {
    public:
        virtual void all_info() const = 0;
        virtual ~geraet() {};
    };

    class camera : public geraet
    {
    public:
        camera(string name) : name{ name } {}

        virtual void all_info() const
        {
            cout << "Der Name der Kamera ist " << name << ".\n";
        }

        virtual ~camera() = default;

        string get_name() const { return name; }
    private:
        string name;
    };

    class sw : public camera
    {
    public:
        sw(string name, string aufl) : camera{ name }, aufl{ aufl } {}

        void all_info() const override
        {
            cout << "Der Name der Kamera ist " << get_name() << ".\n";
            cout << "Die Aufloesung ist " << aufl << ".\n";
        }
    private:
        string aufl;
    };

    void tellme(const geraet& g)
    {
        g.all_info();
    }
}

int main(int argc, char** argv)
{
    using namespace vit;

    sw mv{ "Matrix Vision", "1920x1200" };
    tellme(mv);

    // geraet dings;
    geraet* basler= new sw{ "Basler", "1920x1080" };
    basler->all_info();

    delete basler;  // Speicherloch, wenn Dtor nicht virtual

 }