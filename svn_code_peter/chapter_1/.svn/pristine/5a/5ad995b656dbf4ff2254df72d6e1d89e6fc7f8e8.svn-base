#include <iostream>
#include <tuple>
#include <string>

using namespace std;

namespace mv {

    tuple<int, float, string> factory() { return {3, 4.2, "Haha"s}; }

    struct olles_c_zeug
    {
	int i;
	double d;
    };

    olles_c_zeug olle_factory() { return {3, 4.2}; }
}

int main (int argc, char* argv[]) 
{
    using namespace mv;

    tuple<int, float, string> t1{3, 4.2, "Haha"s};
    cout << "t1<0> = " << get<0>(t1) << endl;
    cout << "t1<float> = " << get<float>(t1) << endl;    

    auto t2= factory();
    auto t2_0= get<0>(t2);
    auto t2_1= get<1>(t2);
    auto t2_2= get<2>(t2);

    int i1;
    float f1;
    string s1;
    tie(i1, f1, s1)= factory();

    auto [i2, f2, s2]= factory();
    auto [oi, od]= olle_factory();

    tuple t5{2, 9.1, 34u, "Hihi"s};
    
    return 0;
}
  
 
