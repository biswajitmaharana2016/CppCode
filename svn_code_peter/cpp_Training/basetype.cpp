#include<iostream>
#include<type_traits>
#include <exception>
#include <sstream> 
#include <cassert>
#include <cmath>
#include <exception>
#include<assert.h>


using namespace std;
namespace ct{
    template<typename T>
    struct base
    {
        using value_type =T;
        T f(T i){ return i+k;}
        T k{};
    };
    template<>
    struct base<short>
    {
        void  value_type() {};
        short f{4};
        using k = short;
    };
    template<typename T>
    struct derive:base<T>
    {
    void value_type(){}
       T g(T i)
       {
           typename base<T>::value_type j =i +4;
           j+= this->k;
           cout <<  this->f(j +i) << endl;
           return this->f(j +i);
       }
    };
}


 int main()
{

    using namespace ct;
   
   // derive<int> t;
    //t.g(4);
    //short u(2);
    derive<short> t2;
    t2.g(2);
   
    return 0;

}  