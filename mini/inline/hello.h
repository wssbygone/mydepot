#ifndef HELLO_H_
#define HELLO_H_

#include<string>
#include<iostream>

class HELLO
{
 public:
  HELLO();
  explicit HELLO(std::string str);
  void print();
        //{
        //  std::cout << _str  << std::endl;
        //} 
        
 private:
  std::string     _str;
};
#endif
