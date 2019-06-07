#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

namespace ct {

    double sc(double x) { return sin(x) + cos(x); }

    template <typename F>
    double fin_diff(F f, double x, double h)
    {
	return (f(x + h) - f(x)) / h;
    }

    double spc(double alpha, double x)  { return sin(alpha * x) + cos(x); }

    struct spc_f
    {
	spc_f(double alpha) : alpha{alpha} {}
	double operator()(double x) const { return sin(alpha * x) + cos(x); }
	double alpha; 
    };

    template <typename F>
    class derivative
    {
      public:
	explicit derivative(F f, double h) : f{f}, h{h} {}
	
	double operator()(double x) const { return (f(x + h) - f(x)) / h; }
      private:
	F      f;
	double h;
    };

    template <size_t N, typename F>
    class nth_derivative
    {
	using prev_der= nth_derivative<N-1, F>;
      public:
	explicit nth_derivative(F f, double h) : fp{f, h}, h{h} {}

	double operator()(double x) const { return (fp(x + h) - fp(x)) / h; }
      private:
	prev_der fp;
	double   h;
    };

    template <typename F>
    class nth_derivative<1, F>
      : public derivative<F>
    {
      // public:
      // 	nth_derivative(F f, double h) : derivative<F>{f, h} {}
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
    using namespace ct;

    cout << "sc'(1) = " << fin_diff(sc, 1.0, 1e-6) << endl;
    // cout << "spc'(1) = " << fin_diff(spc 0.7, 1.0, 1e-6) << endl;
    cout << "spc'(1) = " << fin_diff(bind(spc, 0.7, placeholders::_1), 1.0, 1e-6) << endl;

    cout << "spc'(1) = " << fin_diff(spc_f{0.7}, 1.0, 1e-6) << endl;

    derivative<double(*)(double)> d_sc{sc, 1e-6};
    cout << "sc'(1) = " << d_sc(1.0) << endl;

    derivative<spc_f> d_spc{spc_f{0.7}, 1e-6};
    cout << "spc'(1) = " << d_spc(1.0) << endl;

    derivative<derivative<spc_f>> dd_spc{d_spc, 1e-6};
    cout << "spc''(1) = " << dd_spc(1.0) << endl;

    nth_derivative<5, spc_f> d5_spc{spc_f{0.7}, 1e-3};
    cout << "spc'5(1) = " << d5_spc(1.0) << endl;

    auto d6_spc= derive<6>(spc_f{0.7}, 0.004);
    cout << "spc'6(1) = " << d6_spc(1.0) << endl;

    auto d6_spc_l= derive<6>([](double x) { return spc(0.7, x); }, 0.004);
    cout << "spc'6(1) = " << d6_spc_l(1.0) << endl;

    double alpha{0.7};
    auto d6_spc_l2= derive<6>([alpha](double x) { return spc(alpha, x); }, 0.004);
    cout << "spc'6(1) = " << d6_spc_l2(1.0) << endl;

    
}
  
 
