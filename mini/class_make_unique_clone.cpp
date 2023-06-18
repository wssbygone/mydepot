// https://stackoverflow.com/questions/50570066/usage-of-this-in-make-unique/76501494#76501494

#include<iostream>
#include<memory>
#include<string>
using namespace std;

class Base {
    public:
        virtual ~Base() {}
        virtual std::unique_ptr<Base> clone() = 0;
        virtual void print() = 0;
};

class A: public Base {
        std::string name_;
    public:
       A(std::string name ){name_ = name; cout<<"A ctor"<<endl;};
        
       // A(const A& other ) {this->name_ = other.name_; cout<<"A copy ctor"<<endl;}
        std::unique_ptr<Base> clone() override{
            return std::make_unique<A>(*this);
        };
        void print( ) override{
            std::cout << "Class A: " << name_<< std::endl;    
        };
        virtual ~A(){ cout<<"A dtor" << endl;};
};

class Factory{
        std::unique_ptr<A> type = std::make_unique<A>("MyName");  
    public:
        std::unique_ptr<Base> createInstance(){
            return type->clone();
    }
};

int main(){
    Factory factory;
    auto instance = factory.createInstance();
    instance->print();
}
