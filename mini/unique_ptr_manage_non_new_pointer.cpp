#include<memory>
#include<iostream>
using namespace std;
class A {
 public:
  ~A() { std::cout << "destructor A func"<<std::endl; }
};

int main(int argc, char* argv[]) {
  std::shared_ptr<A[]> a_ptr(new A[5]);
  int x = 5;
  auto del = [](int * p) { std::cout << "Deleting x, value is: "<<*p<<std::endl; };
  std::unique_ptr<int, decltype(del)> px(&x, del); //unique_ptr manager a normal pointer 
  int* p=nullptr;
  std::cout<<sizeof(p) << "\t" << sizeof(int*) <<std::endl;
//  double i=2.5;
//  const int& rr=i+2;
//  std::cout<<rr <<std::endl;
  return 0;
}
