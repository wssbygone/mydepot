#include <iostream>
 

int main()
{
    int i = 100;//局部变量
    //将i拷贝到lambda表达式f的可调用对象，也就是把i是100这个值传到了f中，f中用的i一直就是100，不会改变。
    auto f = [i] { return i; };
    i = 0;
    int j = f(); //j=100,因为i是f创建时拷贝的，而不是运行时，所以即使后面i=0也不起作用。
    printf("j = %d\n",j);
    return 0;
}
