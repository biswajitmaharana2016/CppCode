#include<iostream>

using namespace std;
namespace ct{

struct  B{

    float m;
    float t;
};
struct  A{

    float m;
    float &t;
    A(float t_):t(t_){ cout << t << endl ;}
};

// template <typename T>
// void fun(T x)
// {
//      T o;//Default constructor,instict types of uninitilaized
//      T o();//Function declaration
//      T o{};//Default ctor, intrinsic type value-init .(o,nullptr)
// }

template <typename T>
T max(T x,T y)
{
     return x > y ? x:y;
}
}


// int main()
// {

//     using namespace ct;
//     //int i{6.5};
//     int i4(6.5);
//     //unsigned u2{i};
//     unsigned u1(i4);
//     static_assert(sizeof(long) > sizeof(int) ,"Long should be more than int");
//     //int i7{1234455667000};
//     long double l{6.7};
//     A ob{2.3};
//     A c1{4.5},c2{l};
//     cout << " c2 " << c2.m << c2.t << endl;
//     B ob1{};//

// }