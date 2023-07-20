#include<iostream>
using namespace std;

class Base
{
public:
    Base(int i):b_number(i){}
//    int get_number(){return b_number;}
    void print(){cout<<b_number<<endl;}
protected:
    int get_number(){return b_number;}
    int b_number;
};

class Derived:public Base
{
public:
//子类中有两个成员变量：
//一个自己的，一个继承的，两个都要初始化
    Derived(int i,int j):Base(i),d_number(j){}
    void print()
    {
//在子类中可以直接访问继承自父类的protected类型成员
        cout<<b_number<<" ";
        cout<<d_number<<endl;
    }
private:
    int d_number;
};

int main()
{
    Base a(2);
    Derived b(3,4);
    a.print();//print()in Base

    //a.b_number=10; 错误！
    //b.b_number=100;错误！
    //不可以在外界访问protected类型的成员
    cout<<"b is ";
    b.print();//print()in Derived

    return 0;
}
