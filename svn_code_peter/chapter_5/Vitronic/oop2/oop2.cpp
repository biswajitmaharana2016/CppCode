// oop2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

namespace vit {

    class camera
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
}

int main(int argc, char** argv)
{
    using namespace vit;

    sw mv{ "Matrix Vision", "1920x1200" };
 
    camera mvo{ mv };
    camera& mvr{ mv };
    camera* mvz{ &mv };

    // mvo.all_info();  // Slicing: kopiere nur den camera-Teil heraus
    mvr.all_info();
    mvz->all_info();

     camera* sony = new camera{ "Sony" };

    static_cast<sw&>(mvr).all_info();
    static_cast<sw*>(mvz)->all_info();
    dynamic_cast<sw*>(mvz)->all_info();

    static_cast<sw*>(sony)->all_info(); // undefiniertes Verhalten

    sw* sony_dy = dynamic_cast<sw*>(sony);
    if (sony_dy == nullptr)
        cout << "Das ist gar keine SW-Kamera!\n";
    try {
        dynamic_cast<sw&>(*sony).all_info();
    }
    catch (std::bad_cast) {
        cout << "Das ist gar keine SW-Kamera!\n";
    }
 
    const sw basler{ "Basler", "1920x1080" };
    basler.all_info();

    // static_cast<sw&>(basler).all_info(); // static_cast entfernt kein const
    const_cast<sw&>(basler).all_info(); // entfernt const und volatile (oder fuegt es hinzu)

    cout << "sony als int = " << *reinterpret_cast<int*>(&sony) << endl;

    const double* dp = new double{ 2.3 };
    cout << "dp als int = " << (int)dp << endl;
}