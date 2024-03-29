#include <iostream>
using namespace std;

class Base1 {
 public:
  virtual void f() { cout << "Base1::f |"  ; }
  virtual void g() { cout << "Base1::g |"  ; }
  virtual void h() { cout << "Base1::h |"  ; }
};

class Base2 {
 public:
  virtual void f() { cout << "Base2::f |" ; }
  virtual void g() { cout << "Base2::g |"  ; }
  virtual void h() { cout << "Base2::h |"; }
};

class Base3 {
 public:
  virtual void f() { cout << "Base3::f |"; }
  virtual void g() { cout << "Base3::g |"; }
  virtual void h() { cout << "Base3::h |"; }
};

class Derive : public Base1, public Base2, public Base3 {
 public:
  virtual void f() { cout << "Derive::f |" ; }
  virtual void g1() { cout << "Derive::g1 |"; }
};

typedef void (*Fun)(void);
typedef unsigned long long ull;  // 32bit system using int

int main() {
  Fun pFun = nullptr;

  Derive d;
  ull** pVtab = (ull**)&d;

  // Base1's vtable
  // pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);

  pFun = (Fun)pVtab[0][0];
  pFun();

  // pFun = (Fun)*((int*)*(int*)((int*)&d+0)+1);

  pFun = (Fun)pVtab[0][1];
  pFun();

  // pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);

  pFun = (Fun)pVtab[0][2];
  pFun();

  // Derive's vtable
  // pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);

  pFun = (Fun)pVtab[0][3];
  pFun();

  // The tail of the vtable

  pFun = (Fun)pVtab[0][4];
  cout << pFun << endl;

  // Base2's vtable
  // pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);

  pFun = (Fun)pVtab[1][0];
  pFun();

  // pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

  pFun = (Fun)pVtab[1][1];

  pFun();

  pFun = (Fun)pVtab[1][2];
  pFun();

  // The tail of the vtable

  pFun = (Fun)pVtab[1][3];
  cout << pFun << endl;

  // Base3's vtable
  // pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);

  pFun = (Fun)pVtab[2][0];
  pFun();

  // pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

  pFun = (Fun)pVtab[2][1];
  pFun();

  pFun = (Fun)pVtab[2][2];
  pFun();

  // The tail of the vtable
  pFun = (Fun)pVtab[2][3];
  cout << pFun << endl;

  return 0;
}
