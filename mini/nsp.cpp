#include <iostream>
namespace _nmsp3 {
using namespace std;
// 三：重载类中的operator new[]和operator delete[]操作符
class A {
 public:
  // static void *operator new(size_t size);  //《c++对象模型探索》
  // static void operator delete(void *phead);
  // int m_i = 0;

  static void *operator new[](size_t size);  // 《c++对象模型探索》
  static void operator delete[](void *phead);

  A() { cout << "A()" << endl; }
  ~A() { cout << "~A()" << endl; }
};

void* A::operator new[](size_t size) {
  //.....
  cout << "new "<<size << endl;
  A *ppoint = (A *)malloc(size);
  return ppoint;
}

void A::operator delete[](void *phead) {
  //...
  cout << "free " << endl;  
  free(phead);
}

void func() {
  /*A *pa = new A();
  delete pa;*/
  A* pa = new A[3]();  // 构造和析构函数被调用3次，但是operator new[]
                       // 和operatordelete[]仅仅被调用一次；
  delete[] pa;
}

}  // namespace _nmsp3

int main() {
  //_nmsp1::func();
  //_nmsp2::func();
  _nmsp3::func();

  return 0;
}
