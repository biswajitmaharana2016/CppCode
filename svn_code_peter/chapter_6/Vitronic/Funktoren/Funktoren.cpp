// Funktoren.cpp 

#include "pch.h"
#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

namespace ct {

    double sin_cos(double x) { return sin(x) + cos(x); }
    double spc(double alpha, double x) { return sin(alpha * x) + cos(x); }

    struct spc_f
    {
        explicit spc_f(double alpha) : alpha{alpha} {}
        double operator()(double x) const { return sin(alpha * x) + cos(x); }
        double alpha;
    };

    template <typename F>
    double fin_diff(F f, double x, double h)
    {
        return (f(x + h) - f(x)) / h;
    }

    template <typename F>
    class derivative
    {
    public:
        derivative(F f, double h) : f{f}, h{h} {}
        double operator()(double x) const { return (f(x + h) - f(x)) / h; }
    private:
        F      f;
        double h;
    };

    template <size_t N, typename F>
    class nth_derivative
    {
        using prev_der = nth_derivative<N - 1, F>;
    public:
        nth_derivative(F f, double h) : fp{ f, h }, h{ h } {}
        double operator()(double x) const { return (fp(x + h) - fp(x)) / h; }
    
    private:
        prev_der fp;
        double   h;
    };

    template <typename F>
    class nth_derivative<1, F>
        : public derivative<F>
    {
    //public:
    //    nth_derivative(F f, double h) : derivative<F>{f, h} {}
        using derivative<F>::derivative;
    };

    template <size_t N, typename F>
    nth_derivative<N, F> derive(F f, double h = 1e-3)
    {
        return nth_derivative<N, F>{ f, h };
    }
}

int main()
{
    using namespace ct;

    cout << "sin_cos'(1.0) = " << fin_diff(sin_cos, 1.0, 1e-6) << endl;
    cout << "spc[0.5]'(1.0) = " << fin_diff(bind(spc, 0.5, placeholders::_1), 1.0, 1e-6) << endl;
    cout << "spc[0.5]'(1.0) = " << fin_diff(spc_f{0.5}, 1.0, 1e-6) << endl;

    using d_spc_f = derivative<spc_f>;
    d_spc_f d_spc{ spc_f{0.5} , 1e-6 };
    cout << "spc[0.5]'(1.0) = " << d_spc(1.0) << endl;

    derivative<d_spc_f> dd_spc{ d_spc, 1e-6 };
    cout << "spc[0.5]''(1.0) = " << dd_spc(1.0) << endl;

    nth_derivative<4, spc_f> d4_spc{ spc_f{0.5} , 1e-3 };
    cout << "spc[0.5]('4)(1.0) = " << d4_spc(1.0) << endl;

    auto d5_spc = derive<5>(spc_f{ 0.5 });
    cout << "spc[0.5]('5)(1.0) = " << d5_spc(1.0) << endl;

    // auto d5_spc_l = derive<5>([](double x) { return sin(0.5 * x) + cos(x); });
    auto d5_spc_l = derive<5>([](double x) { return spc(0.5, x); });
    cout << "spc[0.5]('5)(1.0) = " << d5_spc_l(1.0) << endl;
}
