#include <fstream>
#include <bitset>
#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdio>
#include <type_traits>
#include <utility>

int main () {
// 构造函数
std::any a1(1);
std::any a2(std::string("Hello"));
 
// assign函数
std::any a3;
a3=2;
std::any a4;
a4=std::string("World");

// 取值
auto a1_val = std::any_cast<int>(a1);
std::string a2_val = std::any_cast<std::string>(a2);
// 判断类型
if(a1.type() == typeid(int))
{
    std::cout << "a1存储的值是int类型" << std::endl;
}
else if(a2.type() == typeid(std::string))
{
    std::cout << "a2存储的值是std::string类型" << std::endl;
}


  return 0;
}
 
