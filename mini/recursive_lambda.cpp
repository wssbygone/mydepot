//https://stackoverflow.com/questions/18085331/recursive-lambda-functions-in-c14
#include <iostream>
#include <algorithm>
#include <set>     

int main () {
  //auto f = [&f](int n) -> int
  std::function<int(int)> f = [&f](int n)
  {
    return n <= 1 ? 1 : n * f(n - 1);
  };
  
  int x = f(4);
   
  std::cout<<"~~~~~~~~~"<<std::endl;
  std::cout<<x<<std::endl;

  struct {
    int operator()(int n) const {
      return n < 2 ? 1 : n * (*this)(n-1);
  }
  }fact;
  std::cout<<"========="<<std::endl;  
  std::cout<< fact(5)<<std::endl;


  return 0;
}
