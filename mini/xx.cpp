#include<stdio.h>
#include<iostream>
using namespace std;

class Base
{
 public:
  void func() { std::cout<<"base func()"<<std::endl;}
  int func(int n) { std::cout<<"base func(n)"<<std::endl; return n;}
};
 
class Sub : public Base
{
 public:
  using Base::func;
  void func() { Base::func(); }
};
 
int main()
{
  Sub s;
  printf("%x\n",(unsigned long)&s);
  s.func();
  s.func(1); // Success!
}
