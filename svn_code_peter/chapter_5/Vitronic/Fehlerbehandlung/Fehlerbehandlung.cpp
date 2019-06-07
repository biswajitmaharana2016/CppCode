#include "pch.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <exception>


using namespace std;

namespace vit {

#if 0
    // bricht bei negativen Werten
    double wurzel(double x)
    {
        assert(x >= 0.0);
        return sqrt(x); 
    }

    bool wurzel(double x, double& res) 
    {
        if (x < 0.0)
            return false;
        res = sqrt(x);
        return true;
    }
#endif

    //struct negative_wurzel : std::exception 
    //{
    //    virtual const char* what() const noexcept override { return "Negative Wurzel"; }
    //};

    struct negative_wurzel : std::runtime_error
    {
        negative_wurzel() : runtime_error("Negative Wurzel") {}
    };

    double wurzel(double x)
    {
        if (x < 0.0)
            throw negative_wurzel{};
        return sqrt(x);
    }

}

int main(int argc, char** argv)
{
    using namespace vit;

 #if 0
   double res;
    if (wurzel(2.0, res))
        cout << "Wurzel(2) = " << res << endl;
    else
        cout << "Wurzel(2) nicht definiert.\n";

    wurzel(-3, res); 
    cout << "Wurzel(-3) = " << res << endl;

    bool success = wurzel(-2.0, res);
    if (success)
        cout << "Wurzel(-2) = " << res << endl;
    else
        cout << "Wurzel(-2) nicht definiert.\n";
#endif



    cout << "Wurzel(2) = " << wurzel(2.0) << endl;
    try {
        double w = wurzel(-2.0);
        cout << "Wurzel(-2) = " << w << endl;
    }
    catch (negative_wurzel& e) {
        cout << e.what() << endl;
        cout << "Wurzel(-2) nicht definiert.\n";
    }
    catch (std::exception& e) {
        cout << "Standard-Ausnahme: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unbekannte Ausnahme\n";
        // throw;
    }

}

