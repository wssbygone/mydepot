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
  //int n=8;
  //std::function<int(int)> f = std::bind(add, std::ref(n),std::placeholders::_1);
  //n=10;
  //std::cout <<f(12) << std::endl; // 调用add函数
  //std::cout<<"========== "<< sizeof(std::string) <<" ========="<<std::endl; 
  
  std::vector<int> vec;
  static int count=0;
  std::cout<<vec.size()<<" "<<(count=vec.capacity())<<std::endl;
  
  for(int i=0;i<100;i++)
  {
    vec.push_back(i);
    if(count!=vec.capacity())
      std::cout<<vec.size()<<" "<<(count=vec.capacity())<<std::endl;
  }
   
  return 0;
}
