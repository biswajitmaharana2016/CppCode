// oop5.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

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
            my_info();
        }

        void my_info() const
        {
            cout << "Der Name der Kamera ist " << name << ".\n";
        }
    private:
        string name;
    };

    class sw : virtual public camera
    {
    protected:
        sw(string aufl) : camera{""}, aufl{aufl} {}
    public:
        sw(string name, string aufl) : camera{ name }, aufl{ aufl } {}

        virtual void all_info() const override
        {
            camera::my_info();
            my_info();
        }

        void my_info() const
        {
            cout << "Die Aufloesung ist " << aufl << ".\n";
        }

    private:
        string aufl;
    };

    class farbe : virtual public camera
    {
    protected:
        farbe(string tiefe) : camera{ "" }, tiefe { tiefe } {}
    public:
        farbe(string name, string tiefe) : camera{ name }, tiefe{ tiefe } {}

        void all_info() const override
        {
            camera::my_info();
            my_info();
        }

        void my_info() const
        {
            cout << "Die Farbtiefe ist " << tiefe << ".\n";
        }
    private:
        string tiefe;
    };

    class hybrid : public sw, public farbe
    {
    public:
        hybrid(string name, string aufl, string tiefe)
            : camera{ name }, sw{ aufl }, farbe{ tiefe } {}

        void all_info() const override final
        {
            sw::all_info();
            farbe::my_info();
        }
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
    cout << endl;

    hybrid fubar{ "Fu Bar", "800x600", "12" };
    fubar.all_info();
    cout << endl;

    tellme(fubar);
}