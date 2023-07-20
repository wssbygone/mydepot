// 继承2层的各继承方式的访问
// https://xiaowen.blog.csdn.net/article/details/111220281
#include<iostream>
using namespace std;

class Base
{
private:
    int priv;
protected:
    int prot;
    int get_priv( ) { return priv; }
public:
    int publ;
    Base(int a, int b, int c) : priv(a), prot(b), publ(c) { }
    int get_prot( ) { return prot; }
    int get_publ( ) { return publ; }
};

//父类1&&孙子类1
class Derived1 : private Base //私有继承
{
public:
    Derived1 (int a, int b, int c) : Base(a, b, c) { }
    int get1_priv( ) {return get_priv( );}

    int get1_prot( ) {return prot;}
    int get1_publ( ) {return publ;}
};
class Leaf1 : public Derived1
{
public:
    Leaf1(int a, int b, int c) : Derived1(a, b, c) { }
    void print( )
    {
        cout << "Leaf1 members: " << get1_priv( ) << " "
        // << get_priv( ) // 不能直接访问
        << get1_prot( ) << " "
        // << get_prot( ) // 不能直接访问
        // << publ // 不能直接访问
        << get1_publ( ) << endl;
    }
};

//父类2&&孙子类2
class Derived2 : protected Base //保护继承
{
public:
    Derived2 (int a, int b, int c) : Base(a, b, c) { }
};
class Leaf2 : public Derived2
{
public:
    Leaf2(int a, int b, int c) : Derived2(a, b, c) { }
    void print( )
    {
        cout << "Leaf2 members: " << get_priv( ) << " "
        // << priv              // 不能直接访问
        << prot << " "
        << publ << endl;
    }
};

//父类3&&孙子类3
class Derived3 : public Base //公有继承
{
public:
Derived3 (int a, int b, int c) : Base(a, b, c) { }
};
class Leaf3 : public Derived3
{
public:
    Leaf3(int a, int b, int c) : Derived3(a, b, c) { }
    void print( )
    {
        cout << "Leaf3 members: " << get_priv( ) << " "
        // << priv<< " "        // 不能直接访问
        << prot << " "
        << publ << endl;
    }
};

int main(int argc, const char * argv[])
{
    Derived1 d1(1, 2, 3);
    Derived2 d2(4, 5, 6);
    Derived3 d3(7, 8, 9);
    // cout << d1.publ;         // 不能直接访问
    // cout << d1.get_priv( );  // 不能直接访问
    // cout << d2.publ;         // 不能直接访问
    // cout << d2.get_priv( );  // 不能直接访问
    cout << d3.publ<<endl;           // OK
    cout << d3.get_prot( )<<endl;    // OK
    Leaf1 lf1(1, 2, 3);
    Leaf2 lf2(4, 5, 6);
    Leaf3 lf3(7, 8, 9);
    // cout << lf1.publ << endl; // 不能直接访问
    // cout << lf2.publ << endl; // 不能直接访问
    cout << lf3.publ << endl;        // OK
    return 0;
}

