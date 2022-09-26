#include<iostream>
#include<memory>

class B
{
public:
  explicit B(int b=2):b_(b)
  {
  }

  ~B() { std::cout << "~B()"<<std::endl;}
private:
  int b_;
};


int main()
{
  std::make_unique<B[]>(10);

  return 0;
}
