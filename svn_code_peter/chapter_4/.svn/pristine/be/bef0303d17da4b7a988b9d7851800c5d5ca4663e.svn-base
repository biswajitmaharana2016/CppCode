#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <complex>
#include <typeinfo>
#include <memory>

using namespace std;

namespace ct {

    struct inc_scale_f
    {
	inc_scale_f(int factor) : factor{factor} {}

	int operator()(int i) const { return ++factor * i; }
	mutable int factor;
    };

    template <typename Container>
    void reverse_sort(Container& c)
    {
	sort(begin(c), end(c), [](auto x, auto y) { return x < y; });
	// using vt= decltype(*begin(c));
	// sort(begin(c), end(c), [](vt x, vt y) { return x < y; });
    }

    auto scale_factory(int factor)
    {
	unique_ptr<int> up{ new int{factor} };
	// return [up](int i) { return *up * i; };
	// return [&up](int i) { return *up * i; };
	return [u= move(up)](int i){ return *u * i; };
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    vector<int> v{3, 9, 2, 11, 14}, x(5);
    // sort(begin(v), end(v), [](int x, int y) { return x < y; });
    reverse_sort(v);
    copy(begin(v), end(v), ostream_iterator<int>(cout, ", ")); cout << endl;

    int factor{6};
    transform(begin(v), end(v), begin(x), [factor](int i) { return factor * i; }); 
    copy(begin(x), end(x), ostream_iterator<int>(cout, ", ")); cout << endl;

    using ci= complex<int>;
    vector<ci>  w{{4, 2}, {3, 7}, {2, 9}};
    sort(begin(w), end(w), [](ci x, ci y){ return real(x) < real(y); });
    copy(begin(w), end(w), ostream_iterator<ci>(cout, ", ")); cout << endl;

    auto scale= [factor](int i) { return factor * i; };
    cout << "Typ von scale ist " << typeid(scale).name() << endl;
    auto scale_ref= [&factor](int i) { return factor * i; };

    cout << "scale(6) = " << scale(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;
    
    ++factor;
    cout << "scale(6) = " << scale(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    // Lieber nicht, Details bei Scott Meyers
    auto copy_all= [=](int i) { return factor * i; };
    auto ref_all= [&](int i) { return factor * i; };
    auto copy_most= [=,&factor](int i) { return factor * i; };
    auto ref_most= [&,factor](int i) { return factor * i; };

    auto inc_scale=[factor](int i) mutable { return ++factor * i; };
    // auto inc_scale=[factor](int i) { static int f{factor}; return ++f * i; };
    
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;

    cout << "scale_factory(7)(6) = " << scale_factory(7)(6) << endl;
    
    return 0;
}
  
 
