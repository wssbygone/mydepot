#include <functional>
#include <iostream>
using namespace std;

class A {
 public:
  A() : m_a(0) {}
  ~A() {}

  virtual void SetA(const int& a) {
    cout << "A:" << this << endl;
    m_a = a;
  }
  int GetA() const { return m_a; }

 protected:
  int m_a;
};
class B : public A {
 public:
  B() : A() { ; }
  ~B() { ; }
  virtual void SetA(const int& a) {
    cout << "B:" << this << endl;
    m_a = a;
  }

 private:
};

int main(void) {
  A a;
  cout << "A:" << &a << endl;  // 0
  function<void(const int&)> func1 =
      std::bind(&A::SetA, a, std::placeholders::_1);
  func1(1);
  cout << a.GetA() << endl;  // 0
  function<void(const int&)> func2 =
      std::bind(&A::SetA, &a, std::placeholders::_1);
  func2(2);
  cout << a.GetA() << endl;  // 2

  cout << "---------" << endl;
  A* pa = new B();
  cout << "B:" << pa << endl;  // 0
  function<void(const int&)> func3 =
      std::bind(&A::SetA, pa, std::placeholders::_1);
  func3(3);
  cout << pa->GetA() << endl;  // 3
  function<void(const int&)> func4 =
      std::bind(&A::SetA, *pa, std::placeholders::_1);
  func4(4);
  cout << pa->GetA() << endl;  // 3
  delete pa;
  system("pause");
  return 0;
}