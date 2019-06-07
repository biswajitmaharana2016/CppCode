#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <memory>

using namespace std;


template <typename ...Args>
class const_vari{
    public:
    template< typename F, size_t ...I>
    void call_helper(F f,index_sequence<I...>){
        f(get<I>(para)...);

    }


    template < typename ...Args2>
    const_vari(Args2&& ...a):para{ forward<Args2>(a)... }
    {
        //cout << "para 1:" << (get<0>(para) << "para 2: " <<  get<1>(para));
    }
    template <typename F>
    void call(F f)
    {
         f( get<0>(para), get<1>(para));
    } 
    /* template <typename F>
    void call(F f)
    {
        call_helper( f, make_index_sequence<sizeof ...(Args)>{});
    }  */
    tuple<Args...> para;
};

    void fun(int i, float f)
    {
            cout << " i:" << i << "f:" << f << endl;
    }



int main (int argc, char* argv[]) 
{


  const_vari<int, float> param{ 2,4.5};
  param.call(fun);
    

    
    return 0;
}
  
 
