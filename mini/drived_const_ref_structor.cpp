#include <iostream>
#include <string>
class Base {
public:
    virtual void Display(const std::string& text = "Base!")
    {
        std::cout << "Base:" << text << std::endl;
    }
 
    virtual ~Base(){}
};
 
class Sub : public Base {
public:
    virtual void Display(const std::string& text  = "Sub!")
    {
        std::cout << "Sub:" << text << std::endl;
    }
 
    virtual ~Sub(){}
};
int main()
{
    Base* sub = new Sub();
    sub->Display();  
 
    delete sub;
    return 0;
};
