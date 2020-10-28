#include <functional>
#include <iostream>

// 为什么C++11又引入了std::ref？
// 主要是考虑函数式编程（如std::bind）在使用时，是对参数直接拷贝，而不是引用

void f(int& n1, int& n2, const int& n3)
{
    std::cout << "    In function: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
    ++n1;   // 增加存储于函数对象的 n1 副本
    ++n2;   // 增加 main() 的 n2
    //++n3; // 编译错误
    std::cout << "In function end: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
}

int main()
{
    int n1 = 1, n2 = 1, n3 = 1;
    std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
	n1 = 10;
    n2 = 11;
    n3 = 12;	
    std::cout << "Before function: n1[" << n1 << "]    n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;	
    bound_f();
    std::cout << " After function: n1[" << n1 << "]    n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
}

// 执行std::bind后，在函数f()中n1的值仍然是1，n2和n3改成了修改的值,说明std::bind使用的是参数的拷贝而不是引用