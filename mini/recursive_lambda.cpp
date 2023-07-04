//https://stackoverflow.com/questions/18085331/recursive-lambda-functions-in-c14
#include <iostream>
#include <algorithm>
#include <set>     
using namespace std;

int main1 () {
  //auto f = [&f](int n) -> int
  std::function<int(int)> f = [&f](int n)
  {
    return n <= 1 ? 1 : n * f(n - 1);
  };
  
  int xx = f(4);
   
  std::cout<<"~~~~~~~~~"<<std::endl;
  std::cout<<xx<<std::endl;

  struct {
    int operator()(int n) const {
      return n < 2 ? 1 : n * (*this)(n-1);
  }
  }fact;
  std::cout<<"========="<<std::endl;  
  std::cout<< fact(5)<<std::endl;

  //------------------------------
  auto func = [](auto & self,int x)->int {
    if (x == 1||x==0)
      return 1;
  else
    return x*self(self, x - 1);
  };

  int x;
  while(cout<<"input a number [1,15):"<<endl,cin >> x,(x<=15) && cin.good())
    cout << func(func, x) << endl;



  return 0;
}


int main()
{
  
    int n = 12345;
 
    // Recursive lambda function to
    // print the digits of a number
    auto printReverse = [&]() {
        if (n == 0)
            return;
        cout << n % 10;
        n = n / 10;
        printReverse();
 
        // As it is a part of main body,
        // semicolon is must
    };
 
    printReverse();
  return 0;
}
