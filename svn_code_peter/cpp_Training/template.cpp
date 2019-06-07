#include<iostream>

using namespace std;
namespace ct{



template <typename T>
T maxi(T x,T y)
{
     return x > y ? x:y;
}

template int maxi(int ,int);

long maxi(long x,long y)
{
     cout << "in long " << endl;
     return x > y ? x:y;
}
namespace {
short maxi(short x,short y)
{
     cout << "in short" << endl;
     return x > y ? x:y;
}

}
}


/* int main()
{

    using namespace ct;
    cout << "inter =" << maxi(5.6,6.6) <<endl;
    cout << "inter =" << maxi(5,6) <<endl;


    cout << "inter_long 1 =" << maxi(5l,6.6) <<endl; // call long specilization function
    //cout << "inter =" << maxi((double)5,6) <<endl; //dont' use
    //cout << "inter =" << maxi(double(5),6) <<endl;//not much better
    cout << "inter_ =" << maxi(static_cast<double>(5),6.5) <<endl;
    cout << "inter_int =" << maxi<int>(5,6.5) <<endl;
    cout << "inter_ld =" << maxi<long double>(5,6.5) <<endl;

    cout << "inter_long =" << maxi<long>(5l,6.5) <<endl; //call the template function
    //cout << "inter =" << maxi(5,6.6) <<endl;

    short s1{2},s2{4};
    cout << "inter_long =" << maxi(s1,s2) <<endl; //call the template function
    return 0;

} */