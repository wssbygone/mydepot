#include <iostream>
using namespace std;

struct Normal
{
  Normal() {cout<<"ctor"<<endl;}

  Normal(const Normal &) {cout<<"copy"<<endl;}

// Normal(Normal &&) {cout<<"&&"<<endl;}
  Normal(Normal &&) = delete ;
};


int main()
{
  cout<<"1======================="<<endl;
  Normal n(Normal());
  cout<<"2======================="<<endl;
  int a = 1;
  const int x = a;  // x is a copy of a
  const int &b = x;  // b is a reference to x, not a
  a=2;
  std::cout<<b<<std::endl;
  
  return 0;
} 
