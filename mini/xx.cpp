#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

void test2();

template < class F, class T >
T useFunc(F func, T x)
{
    static int count = 0;
    cout << ++count << endl;
    cout << &count << endl;
    return func(x);
}
 
double func1(double d) {
    return d;
}
 
class func2
{
public:
    double operator()(double d) {
        return d;
    }
};
 
void test1()
{
    useFunc(func1, 10.1);
    useFunc(func2(), 10.2);
    useFunc([](double d){return d;}, 10.3);
}
 
void test2()
{
    function<double(double)> f1 = func1;
    function<double(double)> f2 = func2();
    function<double(double)> f3 = [](double d){return d;};
    useFunc(f1, 10.1);
    useFunc(f2, 10.1);
    useFunc(f3, 10.1);
}

int main()
{
  test1();
  std::cout<<"------------------"<<std::endl;
  test2();

  return 0;
}
