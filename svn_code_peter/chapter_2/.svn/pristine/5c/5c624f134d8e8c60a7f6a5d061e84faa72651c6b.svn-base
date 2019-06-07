#include <iostream>
#include <cmath>
#include <functional>

using namespace std;
using namespace std::placeholders;

namespace sn {

    double sc(double x) { return sin(x) + cos(x); }

    // double fin_diff(double (*f)(double), double x, double h)
    // {
    // 	return (f(x + h) - f(x)) / h;
    // }

    template <typename F>
    double fin_diff(F f, double x, double h)
    {
	return (f(x + h) - f(x)) / h;
    }
    
    double spc(double alpha, double x) { return sin(alpha * x) + cos(x); }
    double spc05(double x) { return spc(0.5, x); }

    class spc_f
    {
      public:
	explicit spc_f(double alpha) : alpha{alpha} {}

	double operator()(double x) const { return sin(alpha * x) + cos(x); }
	
      private:
	double alpha;
    };

    template <typename F>
    class derivative
    {
      public:
	explicit derivative(F f, double h) : f{f}, h{h} {}

	double operator()(double x) const
	{
	    return (f(x + h) - f(x)) / h;
	}
      private:
	F      f;
	double h;
    };

    template <size_t N, typename F>
    class nth_derivative
    {
	using Fp= nth_derivative<N-1, F>;
      public:
	nth_derivative(F f, double h) : fp{f, h}, h{h} {}
	
	double operator()(double x) const
	{
	    return (fp(x + h) - fp(x)) / h;
	}

      private:
	Fp     fp;
	double h;
    };

    template <typename F>
    class nth_derivative<1, F>
      : public derivative<F>
    {
	using derivative<F>::derivative;
      // public:
      // 	nth_derivative(F f, double h) : derivative<F>{f, h} {}
    };

    template <size_t N, typename F>
    nth_derivative<N, F> derive(F f, double h= 1e-3)
    {
	return nth_derivative<N, F>{f, h};
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    cout << "sc'(1.0) ~ " << fin_diff(sc, 1.0, 1e-6) << endl;
    // cout << "spc[0.5]'(1.0) ~ " << fin_diff(spc(0.5), 1.0, 1e-6) << endl;
    cout << "spc[0.5]'(1.0) ~ " << fin_diff(spc05, 1.0, 1e-6) << endl;

    cout << "spc[0.5]'(1.0) ~ " << fin_diff(bind(spc, 0.5, _1), 1.0, 1e-6) << endl;

    cout << "spc[0.5]'(1.0) ~ " << fin_diff(spc_f{0.5}, 1.0, 1e-6) << endl;

    derivative<spc_f> d_spc_o{spc_f{0.5}, 1e-6};
    cout << "spc[0.5]'(1.0) ~ " << d_spc_o(1.0) << endl;

    derivative<derivative<spc_f> > dd_spc_o{d_spc_o, 1e-6};
    cout << "spc[0.5]''(1.0) ~ " << dd_spc_o(1.0) << endl;

    nth_derivative<5, spc_f> d5_spc_o{spc_f{0.5}, 1e-3};
    cout << "spc[0.5]'5(1.0) ~ " << d5_spc_o(1.0) << endl;

    auto d6_spc_o= derive<6>(spc_f{0.5});
    cout << "spc[0.5]'6(1.0) ~ " << d6_spc_o(1.0) << endl;

    auto d6_spc_l= derive<6>([](double x){ return spc(0.5, x); });
    cout << "spc[0.5]'6(1.0) ~ " << d6_spc_l(1.0) << endl;
    
    return 0;
}
  
 
