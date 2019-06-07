#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <memory>

using namespace std;

namespace sn {

    struct ocz
    {
	int i;
	double d;
    };

    ostream& operator<<(ostream& os, ocz oc)
    {
	return os << "(" << oc.i << ", " << oc.d << ")";
    }

    double mult(double factor, double x)
    {
	return factor * x;
    }

    struct scale_functor
    {
	scale_functor(int factor) : factor{factor} {}
	int operator()(int x) const { return factor * x; }
	int factor;
    };
    
    struct inc_scale_functor
    {
	inc_scale_functor(int factor) : factor{factor} {}
	int operator()(int x) const { return ++factor * x; }
	mutable int factor;
    };

    struct mit_lambda
    {
	int f(int i) const { return i + 4; }
	int g(int i) const {
	    auto l= [i,this](int j) { return f(j + i) + k; };
	    return l(i - 3);
	}
	
	int k{9};
    };

    // C++14: generische Lambdas
    template <typename C>
    void reverse_sort(C& c)
    {
	sort(begin(c), end(c), [](auto x, auto y){ return x > y; });
    }

    auto scale_factory(int factor)
    {
	unique_ptr<int> up{ new int{factor} };
	// return [up](int i){ return *up * i; }; // Fehler: kein Kopierktor
	// return [&up](int i){ return *up * i; }; // schale Ref, auf toten Zeiger
	return [u= move(up)](int i){ return *u * i; };
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;
    
    vector<int> v{8, 2, 9, 4, 11};
    sort(begin(v), end(v), [](int x, int y){ return x > y; });
    copy(begin(v), end(v), ostream_iterator<int>(cout, ", ")); cout << endl;

    vector<int> w(v.size());
    int factor{6};
    transform(begin(v), end(v), begin(w), [factor](int x){ return factor * x; });

    auto scale_by_factor= [factor](int x){ return factor * x; };
    transform(begin(v), end(v), begin(w), scale_by_factor);

    copy(begin(w), end(w), ostream_iterator<int>(cout, ", ")); cout << endl;

    transform(begin(v), end(v), begin(w), scale_functor{factor});
    // transform(begin(v), end(v), begin(w), mult);
    copy(begin(w), end(w), ostream_iterator<int>(cout, ", ")); cout << endl;
    
    vector<ocz> vo{{3, 3.1}, {4, -2.1}, {9, 1.8}};
    sort(begin(vo), end(vo), [](ocz o1, ocz o2){ return o1.d < o2.d; });
    copy(begin(vo), end(vo), ostream_iterator<ocz>(cout, ", "));
    cout << endl;

    auto scale_copy= [factor](int x){ return factor * x; };
    auto scale_ref= [&factor](int x){ return factor * x; };
    cout << "Typ von scale_copy ist " << typeid(scale_copy).name() << endl;

    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    ++factor;
    cout << "scale_copy(6) = " << scale_copy(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    // Lieber nicht, Details siehe Scott Meyers
    auto copy_all= [=](int x){ return factor * x; };
    auto ref_all= [&](int x){ return factor * x; };
    auto copy_most= [=,&factor](int x){ return factor * x; };
    auto ref_most= [&,factor](int x){ return factor * x; };

    auto inc_scale= [factor](int x) mutable ->int { return ++factor * x; };
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;
    cout << "inc_scale(6) = " << inc_scale(6) << endl;

    auto inc_scale2= [factor](int x) { static int f{factor}; return ++f * x; };

    cout << "scale_factory(6)(7) = " << scale_factory(6)(7) << endl;
    
    return 0;
}
  
 
