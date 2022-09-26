#include<iostream>

struct A
{
  int a;
  std::string s;
};

class B
{
public:
  explicit B(const A& a)
  {
    std::cout << "a,hh"<< std::endl;
    a_=a;
  }

  ~B() {}
private:
  A a_;
};


class C : public B
{
public:
  C():B( A({2,"HH"}) )
  {
     std::cout << "init C" << std::endl;
  }
};

int main()
{
  C c; 
  const int &b = 2 ;
  std::cout<<"0x" <<std::hex<<22222435252  << std::endl;
  return 0;
}
