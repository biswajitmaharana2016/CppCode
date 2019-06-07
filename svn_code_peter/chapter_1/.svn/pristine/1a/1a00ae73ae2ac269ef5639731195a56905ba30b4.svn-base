#include <iostream>
#include <cmath>
#include <functional>

using namespace std;
using namespace std::placeholders;

namespace mv {

    double sin_cos(double x) { return sin(x) + cos(x); }
    double psc(double alpha, double x)  { return sin(alpha*x) + cos(x); }

    struct psc_f
    {
	explicit psc_f(double alpha) : alpha{alpha} {}
	double operator()(double x) const { return sin(alpha*x) + cos(x); }
	double alpha;
    };

    template <typename F>
    double fin_diff(F f, double x, double h)
    {
	return (f(x+h) - f(x)) / h;
    }

    template <typename F>
    class derivative
    {
      public:
	explicit derivative(F f, double h= 1e-6) : f{f}, h{h} {}

	double operator()(double x) const { return (f(x+h) - f(x)) / h; }
      private:
	F f;
	double h;
    };

    template <size_t N, typename F>
    class nth_derivative
    {
	using prev_der= nth_derivative<N-1, F>;
      public:
	explicit nth_derivative(F f, double h= 1e-3) : fp{f, h}, h{h} {}

	double operator()(double x) const { return (fp(x+h) - fp(x)) / h; }
      private:
	prev_der fp;
	double h;
    };

    template <typename F>
    class nth_derivative<1, F>
      : public derivative<F>
    {
	using derivative<F>::derivative; // C++11
    };
    
    template <size_t N, typename F>
    nth_derivative<N, F> derive(F f, double h= 1e-3)
    {
	return nth_derivative<N, F>{f, h};
    }

    template <size_t N> struct order {};
    
    template <size_t N, typename F>
    nth_derivative<N, F> derive(order<N>, F f, double h= 1e-3)
    {
	return nth_derivative<N, F>{f, h};
    }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    cout << "sin_cos'(1.) ~ " << fin_diff(sin_cos, 1.0, 1e-6) << endl;
    cout << "psc[0.5]'(1.) ~ " << fin_diff(psc_f{0.5}, 1.0, 1e-6) << endl;
    cout << "psc[0.5]'(1.) ~ " << fin_diff(bind(psc, 0.5, _1), 1.0, 1e-6) << endl; // C++11

    derivative<psc_f> d_psc_o{psc_f{0.5}, 1e-6};
    cout << "psc[0.5]'(1.) ~ " << d_psc_o(1.0) << endl;

    derivative<derivative<psc_f>> dd_psc_o{d_psc_o, 1e-6};
    cout << "psc[0.5]''(1.) ~ " << dd_psc_o(1.0) << endl;

    nth_derivative<5, psc_f> d5_psc_o{psc_f{0.5}};
    cout << "psc[0.5]'5(1.) ~ " << d5_psc_o(1.0) << endl;

    auto d5_psc_b= derive<5>(bind(psc, 0.5, _1));
    cout << "psc[0.5]'5(1.) ~ " << d5_psc_b(1.0) << endl;
    
    auto d5_psc_b2= derive(order<5>{}, bind(psc, 0.5, _1));
    cout << "psc[0.5]'5(1.) ~ " << d5_psc_b2(1.0) << endl;

    double alpha{0.5};
    auto d5_psc_l= derive<5>([alpha](double x){ return sin(alpha*x) + cos(x); });
    cout << "psc[0.5]'5(1.) ~ " << d5_psc_l(1.0) << endl;
    
    return 0;
}
  
 
