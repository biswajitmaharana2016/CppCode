#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <iterator>
#include <typeinfo>
#include <functional>
#include <memory>

using namespace std;

namespace mv {

    struct dings
    {
	int f(int i) { return i; }
	int g(int i)
	{
	    auto l= [i, this](int j){ return f(i + j + k); };
	    return l(9 * i);
	}
	int k{4};
    };

    // Seit C++14 mit auto
    template <typename Container>
    void reverse_sort(Container& c)
    {
	// using vt= decltype(*begin(c));
	sort(begin(c), end(c), [](auto x, auto y){ return x > y; });
    }

    auto scale_factory(int factor)
    {
	unique_ptr<int> up{ new int{factor} };
	// return [up](int i) { return *up * i; };
	// return [&up](int i) { return *up * i; };
	return [u= move(up)](int i) { return *u * i; };
	// return [u= move(up), f= factor, e= factor * factor](int i) { return *u * i; };
	// return [factor](int i) { unique_ptr<int> up{ new int{factor} }; return *up * i; };
    }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    using ci= complex<int>;
    vector<ci> vi{{2, 3}, {4, 9}, {1, 3}};
    sort(begin(vi), end(vi), [](ci x, ci y){ return real(x) <= real(y); });
    copy(begin(vi), end(vi), ostream_iterator<ci>(cout, ", ")); cout << endl;

    vector<int> v2{3, 9, 4}, vs(v2.size());
    sort(begin(v2), end(v2), [](int x, int y){ return x > y; });
    copy(begin(v2), end(v2), ostream_iterator<int>(cout, ", ")); cout << endl;

    transform(begin(v2), end(v2), begin(vs), [](int x) { return x * x; });

    int factor1 =7;
    auto scale_ = [factor1](int x) { return factor1* x; };

    transform(begin(v2), end(v2), begin(vs),scale_);
    copy(begin(vs), end(vs), ostream_iterator<int>(cout, ", ")); cout << endl;

    cout << "Typ vom Lambda ist " << typeid([](int x) { return x * x; }).name() << endl;
    cout << "Typ vom Lambda ist " << typeid([](int x) { return x * x; }).name() << endl;

    auto square_int= [](int x) { return x * x; };

    int factor{6};
    auto scale= [factor](int x){ return factor * x; };
    auto scale_ref= [&factor](int x){ return factor * x; };

    cout << "scale(6) = " << scale(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    ++factor;
    cout << "scale(6) = " << scale(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    // Lieber nicht verwenden, siehe Meyers' Kampfreden
    auto copy_all= [=](int x){ return factor * x; };
    auto ref_all= [&](int x){ return factor * x; };
    auto copy_most= [=, &factor](int x){ return factor * x; };
    auto ref_most= [&, factor](int x){ return factor * x; };

    cout << "scale_factory(6)(7) = " << scale_factory(6)(7) << endl;

    struct inc_scale_f
    {
	inc_scale_f(int factor) : factor{factor} {}
	int operator()(int x) const { return ++factor * x; };
	mutable int factor;
    };
    
    auto inc_scale= [factor](int x) mutable { return ++factor * x; };
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    
    return 0;
}
  
 
