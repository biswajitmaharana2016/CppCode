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
    struct out_of_range
      : std::runtime_error
    {
        out_of_range() : std::runtime_error("Out of range in vector") {}
    };



     template <typename value>
    class vector
    {
            public:
            vector(size_t s): s{s},data{new value[s]}{

            }
            vector(initializer_list<value> il): s(il.size()), data{new value[s]}{
                std::copy(il.begin(),il.end(),data);
            }
            value& operator[](size_t i){return data[i];}
          

        size_t size() { return s;}
        
            private:
            size_t s;
            value* data;

    };
   template<typename value>
std::ostream& operator << ( std::ostream& op, vector<value> &v)
        {
             op << "[";
             /*  if(s > 0)
             {
                 op << data[0];
             } */ 
             for(int i = 0; i < v.size(); ++i)
             {
                 op << "," << v[i] ;
             }
             op << "]";
             return op;

     }  
     class vector_bool_proxy
    {
      public:
        using uchar= unsigned char;

        vector_bool_proxy(uchar& byte, size_t pos)
          : byte{byte}, mask{static_cast<uchar>(1 << pos)} {}

        vector_bool_proxy& operator=(bool value)
        {
            if (value)
                byte|= mask;
            else
                byte&= ~mask;
            return *this;
        }

        operator bool() const { return (byte & mask) != 0; }

      private:
        uchar& byte;
        uchar  mask;
    };

    template <>
    class vector<bool>
    {
        using uchar= unsigned char;
        void check(size_t i) const { if (i >= s) throw out_of_range{}; }
      public:
        explicit vector(size_t s) : s{s}, data{new uchar[(s+7)/8]} {}

        bool operator[](size_t i) const { check(i); return (data[i/8] >> i%8 & 1) == 1; }
        vector_bool_proxy operator[](size_t i) { check(i); return {data[i/8], i%8}; }

        size_t size() const { return s; }
      private:
        size_t      s;
        uchar*      data;
    };

     /* size_t array_size( vector<double>& v)
    {
      return v.size();
    } */
}


 int main()
{

    using namespace ct;
    /* //std::vector<double> v{3.4,5.6,6.7};
    vector<double> v{2.5,6.7};
    
    //v[0] =2.3 ;     v[1] = 3.4;

    cout << v[0] << endl;

    cout << array_size(v) << endl; */
   
    vector<bool> v(3);
    v[0]= false; v[1]= true; v[2]= false;
    cout << "v[1] = " << boolalpha << v[1] << endl;
    assert(v[1]);

    cout << "v = " << v << endl;

    //assert(v[0] == 3.4);
   
    return 0;

}  