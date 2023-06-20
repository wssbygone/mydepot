#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
  int &&rr1 = 42;  //正确，42是字面值
  int &&rr2 = std::move(rr1); //错误，表达式rr1是左值  

  return 0;
}
