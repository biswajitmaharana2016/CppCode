#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <memory>

using namespace std;

namespace le {

    struct simple
    {
	int f(int i) { return i * 3 + k; }

	int g(int i) {
	    auto l= [i,this](int j) { return f(i + k); };
	    return l(i + 2);
	}
	
	int k{4};
    };


    struct inc_scale_functor
    {
	inc_scale_functor(int factor) : factor{factor} {}

	int operator()(int x) const { return ++factor * x; }
	mutable int factor;
    };

    // C++14
    template <typename Container>
    void reverse_sort(Container& c)
    {
	sort(begin(c), end(c), [](auto x, auto y){ return x > y; });
    }

    template <typename Container>
    void reverse_sort11(Container& c)
    {
	using rt= decltype(*begin(c));
	sort(begin(c), end(c), [](rt x, rt y){ return x > y; });
    }

    auto scale_factory(int factor)
    {
	unique_ptr<int> up{new int{factor}};
	// return [up](int i){ return *up * i; }; // error: no copy ctor
	// return [&up](int i){ return *up * i; }; // stale reference to pointer with deleted data
	return [u= move(up)](int i){ return *u * i; };
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    vector<int> v{3, 9, 4, 11, 2, 99}, w(v.size());
    sort(begin(v), end(v));
    copy(begin(v), end(v), ostream_iterator<int>(cout, ", ")); cout << endl;

    // sort(begin(v), end(v), [](int x, int y){ return x > y; });
    // reverse_sort(v);
    reverse_sort11(v);
    copy(begin(v), end(v), ostream_iterator<int>(cout, ", ")); cout << endl;

    int factor{6};
    transform(begin(v), end(v), begin(w), [factor](int x){ return factor * x; });
    copy(begin(w), end(w), ostream_iterator<int>(cout, ", ")); cout << endl;
    
    using ci= complex<int>;
    vector<ci> vc{{3, 4}, {8, 3}, {2, 11}};
    sort(begin(vc), end(vc), [](ci x, ci y){ return abs(x) < abs(y); });
    copy(begin(vc), end(vc), ostream_iterator<ci>(cout, ", ")); cout << endl;
    
    sort(begin(vc), end(vc), [](ci x, ci y){ return real(x) < real(y); });
    copy(begin(vc), end(vc), ostream_iterator<ci>(cout, ", ")); cout << endl;

    auto scale_copy= [factor](int x){ return factor * x; };
    auto scale_copy2= [factor](int x){ return factor * x; };
    auto scale_ref= [&factor](int x){ return factor * x; };
    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    ++factor;
    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    // Try to avoid, look in Meyers' book for detail
    auto copy_all= [=](int x){ return factor * x; };
    auto ref_all= [&](int x){ return factor * x; };
    auto copy_most= [=,&factor](int x){ return factor * x; }; 
    auto ref_most= [&,factor](int x){ return factor * x; };

    auto inc_scale= [factor](int x) mutable -> int { return ++factor * x; };
    // auto inc_scale= [factor](int x) { static int f{factor}; return ++f * x; };
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    
    cout << "Type of scale_copy is " << typeid(scale_copy).name() << endl;
    cout << "Type of scale_copy2 is " << typeid(scale_copy2).name() << endl;

    cout << "scale_factory(6)(7) = " << scale_factory(6)(7) << endl;
    
    return 0;
}
  
 
