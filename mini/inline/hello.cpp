#include "hello.h"
HELLO::HELLO()
{
    _str = "WORLD";
}
HELLO::HELLO(std::string str)
{
    _str = str;
}

void HELLO::print()
{
    std::cout << _str  << std::endl;
}


