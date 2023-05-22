#include <iostream>
using namespace std;

#if 0
template<typename... Args> struct sum;
template<typename First, typename Last>
struct sum<First, Last>
{ 
    enum{ value = sizeof(First) + sizeof(Last) };
};


template<> 
struct sum<> 
{ 
	enum{ value = 0 }; 
};
#endif

 
template<typename... Args> struct Sum;

template<typename Last>
struct Sum<Last> : std::integral_constant<int, sizeof(Last)>
{
}; 
 
template<typename First, typename... Rest>
struct Sum<First, Rest...> : std::integral_constant<int, Sum<First>::value + Sum<Rest...>::value>
{
};
 
/*template<typename Last>
struct Sum<Last> : std::integral_constant<int, sizeof(Last)>
{
};*/

//Sum<int,double,short>::value; 

int main()
{
  cout << (Sum<int,double,int*,char>::value)  << endl;
  cout<<"==="<<endl;
  return 0;
}
