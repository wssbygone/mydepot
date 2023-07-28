#include <fstream>
#include <bitset>
#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdio>
struct SS {
  SS(int a=98):a_(a) { }
  int a_;
};

int main () {
  SS *s;
  decltype(s) pB;
  pB=nullptr;
  std::cout<<typeid(pB).name()<<std::endl;    
  decltype(s) pC=new SS(77);
  std::cout<<pC->a_<<std::endl;    

  const std::string &topicName="abcd";
  std::cout<<topicName<<std::endl;
  return 0;
}
 
