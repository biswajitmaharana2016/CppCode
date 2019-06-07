#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <initializer_list>

using namespace std;

namespace mv {

    struct size_helper { size_t s; };


    
    template <typename Value>
    class vector
    {
      public:
	void check(size_t i) const { assert(i < s); }
	void size_check(size_t ss) const { assert(ss == s); }

	explicit vector(size_t s) : s{s}, data{new Value[s]} {}
	explicit vector(size_helper sh) : s{sh.s}, data{new Value[s]} {}

	vector(initializer_list<Value> il) : vector(il.size())
	{
	    size_t i{0};
	    for (Value value : il)
		data[i++]= value;
	}

	~vector() { delete[] data; }

	vector(const vector& that) : vector(that.size())
	{
	    cout << "Kopierkonstruktor\n";
	    std::copy(that.data, that.data + s, data);
	}

	vector(vector&& that) : s{that.s}, data{that.data}
	{
	    cout << "Move-Konstruktor\n";
	    that.data= nullptr;
	    that.s= 0;
	}

	vector& operator=(const vector& that)
	{
	    cout << "Kopierzuweisung\n";
	    if (this != &that) {
	    	size_check(that.size());
	    	std::copy(that.data, that.data + s, data);
	    }
	    return *this;
	}

	vector& operator=(vector&& that)
	{
	    cout << "Move-Zuweisung\n";
	    size_check(that.size());
	    delete [] data;
	    data= that.data;
	    that.data= nullptr;
	    that.s= 0;
	    // swap(data, that.data);
	    return *this;
	}
	
	const Value& operator[](size_t i) const { check(i); return data[i]; }
              Value& operator[](size_t i)       { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t  s;
	Value* data;
    };

    vector(size_t) -> vector<double>;
    
    template <typename Value>
    std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
    {
	os << "{";
	// v[1]= 666;
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << "}";
    }

    template <typename Value>
    vector<Value> operator+(const vector<Value>& v1, const vector<Value>& v2)
    {
	v1.size_check(v2.size());
	vector<Value> sum(v2.size());
	for (size_t i= 0; i < v1.size(); ++i)
	    sum[i]= v1[i] + v2[i];
	return sum;
    }

    void rvalue_only(int&&) { cout << "Yeah, Dein int ist temporaer.\n"; }
    void lvalue_only(int&) { cout << "Yeah, Dein int ist eine Variable.\n"; }

    void pass_on(int&& i)
    {
	// rvalue_only(i); // i ist ein lvalue
	rvalue_only(1 * i);
	rvalue_only(static_cast<int&&>(i));
	rvalue_only(std::move(i));
    }

    void rvalue_only(vector<double>&&) { cout << "rvalue_only(vec)\n"; }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    vector<double> v1{{5.1, 8.2, 9.1}}, v2{2.3, 4.3, 9.1}, v3(3);

    vector  v1auto{5.1, 8.2, 9.1};
    vector  v3auto(5);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    v3= v1;
    cout << "v3 = " << v3 << endl;

    v3= v1 + v2;
    cout << "v3 = " << v3 << endl;

    vector<double> v4{v3}, v5{v3 + v2};
    cout << "v4 = " << v4 << endl;
    cout << "v5 = " << v5 << endl;

    move(v4);
    cout << "v4 = " << v4 << endl;

    rvalue_only(move(v4));
    cout << "v4 = " << v4 << endl;

    v5= move(v4);
    cout << "v4 = " << v4 << endl;

    vector<double> v6{move(v5)};
    cout << "v5 = " << v5 << endl;
    
    
    int       i{5};
    const int j{7};
    rvalue_only(3);
    // rvalue_only(i);
    // rvalue_only(j);
    rvalue_only(1 * i);
    rvalue_only(i++);
    // rvalue_only(++i);
    
    // lvalue_only(3);
    lvalue_only(i);
    // lvalue_only(1 * i);
    // lvalue_only(i++);
    lvalue_only(++i);

    pass_on(3);
    
    return 0;
}
  
 
