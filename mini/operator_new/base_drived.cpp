#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <new>

using namespace std;

class Parent
{
public:
    static void* operator new(size_t n)
    {
        printf("Parent::operator new, size = %lu\n", n);
        return ::operator new(n);
    }
    static void operator delete(void* p)
    {
        printf("Parent::operator delete, p = %p\n", p);
        return ::operator delete(p);
    }
public:
    int m_value=2;
};

class Child : public Parent
{
public:
    int getC(){return m_childValue;}
    int m_childValue=8;
};

int main()
{
    Parent* p = new Parent();
    Child* c = new Child();
    cout<<sizeof(*p)<<" "<<sizeof(*c) << endl;
    cout<< c->m_value << " "<< c->getC() <<endl;
    delete p;
    delete c;
    return 0;
}
