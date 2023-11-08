//virtual member function can be used in a class template. It is easy for compiler to construct vtable
//It is impossible to define a class template member function as virtual, as you can see, it hard to determine function signature and allocate vtable entries.
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class A{
public:
    virtual void func1(const T& p)
    {
        cout<<"A:"<<p<<endl;
    }
};

template <typename T>
class B
: public A<T>
{
public:
    virtual void func1(const T& p)
    {
        cout<<"A<--B:"<<p<<endl;
    }
};

class X
{
public:
    template <typename T>   //类中的模板成员，在定义类对象时候并没有给类型
    virtual void func2(const T& p)
    {
        cout<<"C:"<<p<<endl;
    }
};

int main(int argc, char** argv)
{
  A<string> a;
  B<int> b;
  B<string> c;

  A<string>* p = &a;
  p->func1("A<string> a");
  p = dynamic_cast<A<string>*>(&c);
  p->func1("B<string> c");
  B<int>* q = &b;
  q->func1(3);
  
  X x;    //此处并不需要给类型
  x.func2<string>("X x");

  return 0;
}
