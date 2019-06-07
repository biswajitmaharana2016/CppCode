#include <iostream>

using namespace std;

namespace le {

    struct nasty_ole_c
    {
	double d;
	int    i;
    };

    struct empty {};

    template <typename T>
    void f(T)
    {
	T e1;   // Default ctor, nothing for intrinsics
	// T e2(); // Function declaration
	T e3{}; // Default ctor, value init for intrinsics (0, nullptr)
    }
}

int main (int argc, char* argv[]) 
{
    using namespace le;

    // int i1= 2.9;
    // int i2(2.8);

    // int i3{2.7};
    // int i4{2.0};
    // int i5= {2.6};

    int i6{9};
    unsigned u1{5};

    // int i7{u1};  // Narrowing: large values not representable
    // unsigned u2{i6};

    static_assert(sizeof(long) > sizeof(unsigned),
		  "long is not long enough on this machine.");
    long l1{u1};

    int i8{1234567890};

    nasty_ole_c n1{3.8, 2}, n2{4.2};
    // cout << "n2.i = " << n2.i << endl;
    
    le::empty e1;
    // le::empty e2();  // Function declaration, Scott Meyers: Most vexing parse
    le::empty e3{};

    
    return 0;
}
  
 
