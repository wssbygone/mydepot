#include <iostream>
#include <string>
#include<memory> 
 
struct boot 
{ 
    boot() { printf("Boot\n"); } 
    ~boot() { printf("Unboot\n"); } 
}; 
 
boot instance = {}; 
 
int main() 
{
  int i=2;
  std::shared_ptr<int> p(new int(2));
  return 0;
} 
