#include<stdio.h>
#include<iostream>
using namespace std;

class Student
{
public:
    Student() = default;
    Student(const Student & s)
    {
        std::cout << "I am copy constructor" << std::endl;
    }
    Student& operator=(const Student & s)
    {
        std::cout << "I am operator= function" << std::endl;
        return *this;
    }

    Student(Student&& rref) noexcept
    {
        std::cout << "I am move copy constructor" << std::endl;
    }

    Student& operator=(Student&& rref) noexcept
    {
        std::cout << "I am move operator= function" << std::endl;
        return *this;
    }
};

int main()
{
    Student s1;
    Student s2;

    // 如果编译器提供默认移动拷贝构造函数，
    // 那就不会调用拷贝构造函数而输出"I am copy constructor",
    // 同意吗？
    Student s3 {static_cast<Student&&>(s1)};


    // 如果编译器提供默认移动拷贝赋值函数，
    // 那就不会调用拷贝赋值函数而输出"I am operator= function",
    // 同意吗？
    s2 = static_cast<Student&&>(s3);
    return 0;
}
