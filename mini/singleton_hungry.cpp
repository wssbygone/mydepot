//饿汉式单例模式
#include <iostream>

class Singleton{
    public:
    static Singleton * getInstance() {
        return single;
    }
    private:
    Singleton() {}
    static Singleton * single;
};
//类内的静态变量  在类外初始化，并且初始化加类型，但是不添加static关键字，和普通的静态变量以做区分
Singleton * Singleton::single = new Singleton();

int main() {
    Singleton * single1 = Singleton::getInstance();
    Singleton * single2 = Singleton::getInstance();
    std::cout << "single1 address:" << single1 << std::endl;
    std::cout << "single1 address:" << single2 << std::endl;
}

