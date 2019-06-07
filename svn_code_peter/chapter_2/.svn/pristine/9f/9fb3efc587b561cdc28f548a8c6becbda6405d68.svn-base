#include <iostream>
#include <memory>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>
#include "irange.hpp"

using namespace std;

namespace sn {

    struct out_of_range {};
    struct incompatible {};

    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	explicit vector(size_t s) : s{s}, data{ new double[s] } {}

	vector(initializer_list<double> il) : vector(il.size())
	{
	    size_t i{0};
	    for (double d : il)
		data[i++]= d;
	}

	vector(const vector& that) : vector(that.size())
	{
	    cout << "Kopierkonstruktor\n";
	    *this= that;
	}

	vector(vector&& that) : s{that.s}, data{move(that.data)}
	{
	    cout << "Move-Konstruktor\n";
	    // that.data= nullptr;
	    that.s= 0;
	}
	
	// ~vector() { delete[] data; }

	void size_check(size_t s) const { if (s != this->s) throw incompatible{}; }

	const vector& operator=(const vector& that)
	{
	    cout << "Kopierzuweisung\n";
	    size_check(that.size());
	    std::copy(&that.data[0], &that.data[s], &data[0]);
	    return *this;
	}

	const vector& operator=(vector&& that)
	{
	    cout << "Move-Zuweisung\n";
	    size_check(that.size());
	    // delete[] data;
	    // data= that.data;
	    // that.data= nullptr;
	    data= move(that.data);
	    that.s= 0;
	    return *this;
	}

	const double& operator[](size_t i) const& { check(i); return data[i]; }
	      double& operator[](size_t i) &      { check(i); return data[i]; }
	      double  operator[](size_t i) &&     { check(i); return data[i]; }

	size_t size() const { return s; }
	
	// friend std::ostream& operator<<(std::ostream& os, vector& v);
      private:
	size_t  s{0};
	std::unique_ptr<double[]> data;
	// double* data{nullptr};
    };
    
    std::ostream& operator<<(std::ostream& os, const vector& v)
    {
	// v[0]= 666; // darf nicht kompilieren
	os << '{';
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << '}';
    }

    vector operator+(const vector& v1, const vector& v2)
    {
	v1.size_check(v2.size());
	vector sum(v1.size());
	for (int i : irange(0, v1.size()))
	    sum[i]= v1[i] + v2[i];
	return sum;
    }

    void temp_only(vector&&) { cout << "Yeah, dein Argument ist temporaer.\n"; }
    void pass_on(vector&& v)
    {
	// temp_only(v); // v ist lvalue
	temp_only(static_cast<vector&&>(v));
	temp_only(move(v)); // das Gleiche, nur kuerzer
    }

    size_t vsize(const vector& v) { return v.size(); }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    vector w{9.1, 2.7, 3, 5.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 2.7) < 1e-10);

    vector v{w};
    cout << "v = " << v << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;

    vector x(w.size());
    x= w;
    cout << "x = " << x << endl;

    x= w + w;
    cout << "x = " << x << endl;

    vector y{x + w};
    cout << "y = " << y << endl;

    temp_only(w+w);
    pass_on(w+w);

    move(y);
    cout << "y = " << y << endl;

    pass_on(move(y));
    cout << "y = " << y << endl;

    x= move(y);
    cout << "y = " << y << endl;

    vector z{move(w)};
    cout << "z = " << z << endl;
    cout << "w = " << w << endl;

    cout << "z hat " << vsize(z) << " Eintraege.\n";
    // cout << "9 hat " << vsize(9) << " Eintraege.\n";
    cout << "9 hat " << vsize(static_cast<vector>(9)) << " Eintraege.\n";

    vector x9= static_cast<vector>(9);
    cout << "x9 = " << x9 << endl;
    
    return 0;
}
  
 
