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
//    A* pA= new A; 
//    shared_ptr<A> p1(pA);
//    shared_ptr<A> p2(pA);   //shared_ptr<A> p2=p1->get_self();

    char str1[] = "helloworld";
    char str[sizeof(str1)]="helloworl";
    char (&str2)[sizeof(str1)] = str1;
    std::cout<< str2 <<std::endl;
    return 0;
}
