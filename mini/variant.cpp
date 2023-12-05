#include<bits/stdc++.h>

struct PrintVisitor  {  //visitor
    void operator()(int i) {std::cout << "int: " << i << '\n';}
    void operator()(double i) {std::cout << "double: " << i << '\n';}
    void operator()(std::string i) {std::cout << "string: " << i << '\n';}
};

int main()
{
    std::variant<int, double, std::string> tmp;
    static_assert(std::variant_size_v<decltype(tmp)> == 3);

    // default initialized to the first alternative, should be 0
    std::visit(PrintVisitor {}, tmp);
    std::cout << "可变体的活动类型返回的index：" << tmp.index() << std::endl;

    tmp = 100.00;
    std::cout << "可变体的活动类型返回的index：" << tmp.index() << std::endl;
    std::visit(PrintVisitor {}, tmp);
    tmp = "hello super world";
    std::cout << "可变体的活动类型返回的index：" << tmp.index() << std::endl;
    std::visit(PrintVisitor {}, tmp);

}

