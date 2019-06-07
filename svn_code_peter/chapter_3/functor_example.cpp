#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

namespace le {

    double sc(double x) { return sin(x) + cos(x); }
    double spc_f(double alpha, double x) { return sin(alpha*x) + cos(x); }

    template <typename F>
    double fin_diff(F f, double x, double h)
    {
	return (f(x+h) - f(x)) / h;
    }

    struct spc
    {
	explicit spc(double alpha) : alpha{alpha} {}

	double operator()(double x) const { return sin(alpha*x) + cos(x); }
	
	double alpha;
    };

    template <typename F>
    class derivative
    {
      public:
	explicit derivative(F f, double h) : f{f}, h{h} {}
	
	double operator()(double x) const 
	{
	    return (f(x+h) - f(x)) / h;
	}
      private:
	F f;
	double h;
    };

    template <size_t N, typename F>
    class nth_derivative
    {
	using prev_der= nth_derivative<N-1, F>;
      public:
	explicit nth_derivative(F f, double h) : fp{f, h}, h{h} {}

	double operator()(double x) const 
	{
	    return (fp(x+h) - fp(x)) / h;
	}
      private:
	prev_der fp;
	double   h;
    };

    template <typename F>
    class nth_derivative<1, F>
      : public derivative<F>
    {
      // public:
      // 	explicit nth_derivative(F f, double h) : derivative<F>{f, h} {}
	using derivative<F>::derivative;
    };

    template <size_t N, typename F>
    nth_derivative<N, F> derive(F f, double h= 1e-3)
    {
	return nth_derivative<N, F>{f, h};
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    cout << "sc'(1.0) ~ " << fin_diff(sc, 1.0, 1e-6) << endl;
    // cout << "spc[0.5]'(1.0) ~ " << fin_diff(spc_f(0.5), 1.0, 1e-6) << endl;
    cout << "spc[0.5]'(1.0) ~ " << fin_diff(bind(spc_f, 0.5, placeholders::_1), 1.0, 1e-6) << endl;

    cout << "spc[0.5]'(1.0) ~ " << fin_diff(spc{0.5}, 1.0, 1e-6) << endl;

    derivative<spc> d_spc{spc{0.5}, 1e-6};
    cout << "spc[0.5]'(1.0) ~ " << d_spc(1.0) << endl;

    derivative<derivative<spc>> dd_spc{d_spc, 1e-6};
    cout << "spc[0.5]''(1.0) ~ " << dd_spc(1.0) << endl;

    nth_derivative<5, spc> d5_spc{spc{0.5}, 1e-3};
    cout << "spc[0.5]'5(1.0) ~ " << d5_spc(1.0) << endl;

    auto d6_sc= derive<6>(sc);
    cout << "sc'6(1.0) ~ " << d6_sc(1.0) << endl;

    auto d6_spc= derive<6>(spc{0.5});
    cout << "spc[0.5]'6(1.0) ~ " << d6_spc(1.0) << endl;

    double alpha{0.5};
    auto d6_spc_l= derive<6>( [alpha](double x){ return sin(alpha*x) + cos(x); } );
    cout << "spc[0.5]'6(1.0) ~ " << d6_spc_l(1.0) << endl;

    auto d6_spc_f= derive<6>( [](double x){ return spc_f(0.3, x); } );
    cout << "spc[0.3]'6(1.0) ~ " << d6_spc_f(1.0) << endl;
					    
    return 0;
}
  
 
