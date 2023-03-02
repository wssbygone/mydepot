// good_user.cc:
//#include "b.h"
#include<iostream>

struct B;
struct D;

void f(B*)
{
  std::cout<<"f(B*)"<<std::endl;
}
void f(void*)
{
  std::cout<<"f(void*)"<<std::endl;
}
void test(D* x) { f(x); }


int main()
{
  D *d;
  test(d);
  return 0;
} 
