#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

namespace le {
template<typename T>
void cr(const T& arg)
{

    cout <<  "T is :" << typeid(w<T>).name() << ".arg is " << typeid(w<decltype(arg)>).name()
}
template<typename T>
void fr( T&& arg)
{

    cout <<  "T is :" << typeid(w<T>).name() << ".arg is " << typeid(w<decltype(arg)>).name()
}
template<typename T>
void cfr( const T&& arg)
{

    cout <<  "T is :" << typeid(w<T>).name() << ".arg is " << typeid(w<decltype(arg)>).name()
}


}

int main (int argc, char* argv[]) 
{
    using namespace le;
    int i{3};
    int& r{i};
    const int& c{i};

    cr(i);
    cr(r);
    cr(c);

    fr(i);
    fr<int&&>(3)
    fr(r);
    fr(c);

     



}
  
 
