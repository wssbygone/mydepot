//成员函数跟着&& 或者 const& 哪些对象能调用。
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Foo {
public:
    //此函数只可以用于右值
    Foo sorted() && {
        //std::sort(data.begin(), data.end());
        cout<<"sorted() &&" << endl;
        return *this;
    }
    //此函数可以用于左值或const类型的右值（因为其带有const，见下面的重载介绍）
    Foo sorted()const & {
        Foo ret(*this); //拷贝一个副本
        //std::sort(ret.data.begin(), ret.data.end()); //排序副本
        cout<<"sorted()const &" << endl;
        return ret; //返回结果
    }
private:
    std::vector<int> data;
};
 
Foo& retFoo(Foo& ff)
{
    //一个函数，返回Foo类，返回左值(引用)
  return ff;
}
 
Foo retVal()
{
    //一个函数，返回Foo类，返回右值
  return Foo();
}
 
const Foo retVal2()
{
  //一个函数，返回Foo类，返回右值，且为const
  return Foo();
}
 
int main()
{
    Foo ss;
    retFoo(ss).sorted(); //调用sorted()const&
    retVal().sorted(); //调用sorted() &&
    retVal2().sorted();//调用sorted()const&
    return 0;
}
