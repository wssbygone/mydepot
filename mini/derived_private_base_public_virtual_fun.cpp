//子类用private权限的函数重写父类的public权限函数,用指向子类对象的父类指针可以调用子类的private重写函数

#include <iostream>
using namespace std;

class Bird {
 public:
  virtual void fly() { cout << "Bird fly" << endl; };
};

class Ostrich : public Bird {
 public:
//  void ff() {fly();}
 private:
  void fly() { cout << "Ostrich cannot fly" << endl; };
};

int main(int argc, char* argv[]) {
  Ostrich ost;
//  ost.ff();
  Bird* b_ptr = &ost;
  b_ptr->fly();  // 通过基类指针调用，实际调用的是Ostrich的私有函数fly，输出Ostrich
  return 0;
}
