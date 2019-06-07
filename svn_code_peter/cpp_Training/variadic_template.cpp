#include<iostream>
#include<type_traits>
#include<vector>
#include <sstream> 

using namespace std;
namespace ct{
#if 0
    typedef double real;
    typedef double array_int[4];
    typedef int (*f_type)(int,int);

#else
    using real = double;
    using array_int = int[4];
    using f_type = int(*)(int, int);
    
    
#endif
    template <typename T>
    T sum(T x)
    {
        cout << "T type" << endl;
        return x;
    }
//C++14
    template <typename ...Args>
    using ct = typename common_type<Args... >::type;
    template<typename  First, typename ...Rest>
    //First
    //typename common_type<First, Rest...>::type 
    ct<First ,Rest...>
    sum(First f, Rest ...r)
    {
            cout << " First not consider " << sizeof...(r) << "values" << endl;
            return f + sum(r...);

    }
//C++17
    template <typename ...Args>
    auto sumr(Args ...a)
    {
        cout << "called 17 " << endl;
        return (a + ...);
    }
    template <typename ...Args>
    auto sum_v(Args ...a)
    {
        cout << "called 17 " << endl;

        return (a + ...);
    }
    //  template<typename ...Args1>
    // auto operator <<( std::ostream& op, Args1... v)
    // {
    //     op << "[";
    //     for(auto op1: v)
    //     {
    //         op << op1 ;
    //     }
    //     op << "]";
    //     return op;

    // } 
}

/* 
 int main()
{

    using namespace ct;
    //cout << "taking no various argument " << sum(-5.6,6.6) <<endl;
    //cout << "taking various argument " << sum(-5.6,6.6,9u,7l, -43.4) <<endl;
    std::vector<int> v{1,2,3};
   //  std::vector<int> v1{1,2,3};
   // std::stringstream s;
    std::cout << "taking various argument " << sumr(-5.6,6.6,9u,7l, -43.4,v.at(1)) <<endl;
   //cout << "taking various argument " << sumr() <<endl;
   //cout << "taking various argument " << sum_v(v,v1) <<endl;
    return 0;

}  */