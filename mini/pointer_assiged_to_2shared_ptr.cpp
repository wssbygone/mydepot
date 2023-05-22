#include<memory>
#include<iostream>
using namespace std;

class A
{
public:
    shared_ptr<A> get_self()  { return shared_ptr<A>(this); } 
    ~A() { cout << ("destructor") << endl; }
};
 
int main()
{
    A* pA= new A; 
    shared_ptr<A> p1(pA);
    shared_ptr<A> p2(pA);   //shared_ptr<A> p2=p1->get_self();

    return 0;
}
