#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <algorithm>
#include <exception>

using namespace std;

namespace ct { 

    struct size_value { size_t i; };

    struct out_of_range : std::runtime_error
    {
	out_of_range() : runtime_error{"Vector index out of range"} {}
    };

    struct incompatible : std::runtime_error
    {
	incompatible() : runtime_error{"Incompatible vector size"} {}
    };
    
    class vector
    {
	void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
	void size_check(size_t s) const { if (s != this->s) throw incompatible{}; }

	vector(size_t s= 0) : s{s}, data{ s > 0 ? new double[s] : nullptr } {}

	vector(initializer_list<double> il) 
	  : vector(il.size())
	{
	    copy(begin(il), end(il), data); 
	}

	vector(const vector& that) : vector(that.size())
	{
	    cout << "Kopierkonstruktor.\n";
	    copy(that.data, that.data + s, data);
	    // *this= that;
	}

	vector(vector&& that) : s{that.s}, data{that.data}
	{
	    cout << "Move-Konstruktor.\n";
	    that.data= nullptr;
	    that.s= 0;
	}

	vector& operator=(const vector& that)
	{
	    cout << "Kopierzuweisung.\n";
	    size_check(that.size());
	    copy(that.data, that.data + s, data);
	    return *this;
	}

	vector& operator=(vector&& that)
	{
	    cout << "Move-Zuweisung.\n";
	    size_check(that.size());
	    // swap(data, that.data);
	    delete[] data;
	    data= that.data;
	    that.data= nullptr;
	    that.s= 0;
	    return *this;
	}
	
	~vector() { delete[] data; }

	const double& operator[](size_t i) const { check(i); return data[i]; }
	double& operator[](size_t i)       { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t  s;
	double* data;
    };

    ostream& operator<<(ostream& os, const vector& v)
    {
	os << '{';
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << '}';
    }

    vector operator+(const vector& v1, const vector& v2)
    {
	size_t s= v1.size();
	v2.size_check(s);
	vector sum(s);
	for (size_t i= 0; i < s; ++i)
	    sum[i]= v1[i] + v2[i];
	return sum;
    }

    size_t vsize(const vector& v) { return v.size(); }

    void lvalue_only(int&) { cout << "Yeah, ein lvalue.\n"; }
    void rvalue_only(int&&) { cout << "Yeah, ein rvalue.\n"; }

    void pass_on(int&& i)
    {
	// rvalue_only(i); // lvalue
	rvalue_only(static_cast<int&&>(i));
	rvalue_only(move(i));
    }

    void rvalue_only(vector&&) {}
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    int i{4};
    
    lvalue_only(i);
    // lvalue_only(1 * i);
    lvalue_only(++i);
    // lvalue_only(i++);

    cout << "Adresse von ++i = " << &++i << endl;

    //rvalue_only(i);
    rvalue_only(1 * i);
    // rvalue_only(++i);
    rvalue_only(i++);
    
    vector w{3.8, 4.2, 9.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 4.2) < 1e-10);

    vector v{w};
    cout << "v = " << v << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "w = " << w << endl;
    cout << "v = " << v << endl;

    vector x(3);
    x= v;
    cout << "x = " << x << endl;
    cout << "v = " << v << endl;

    x= v + w;
    cout << "x = " << x << endl;

    vector y{x + w};
    cout << "y = " << y << endl;

    move(y);
    cout << "y = " << y << endl;

    rvalue_only(move(y));
    cout << "y = " << y << endl;

    x= move(y);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    vector z{move(w)};
    cout << "w = " << w << endl;
    
    return 0;
}
  
 
