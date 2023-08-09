#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <typeinfo>
#include <functional>

//sizeof(std::vector<double>)

class Bar
{
public:
  void foo(int a, int b, int c)
  {
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
  }
};

int add(int a, int b)
{
  std::cout<<a << "+" << b<<"="<<std::endl;
  return a + b;
}

int main(int argc, char *argv[]) {
  //Bar bar;
  //auto f = std::bind(&Bar::foo,&bar,1, 2, 3);
  //f(); // 调用foo函数
  int n=8;
//  std::cout<<argc <<"\t"<< argv[1]<<std::endl;
  std::function<int(int)> f = std::bind(add, std::ref(n),std::placeholders::_1);
  n=10;
  std::cout <<f(12) << std::endl; // 调用add函数
  // std::cout << typeid(argv[1]).name() <<std::endl;
 
  std::cout<<"========== "<< sizeof(std::string) <<" ========="<<std::endl; 
  
  return 0;
}
