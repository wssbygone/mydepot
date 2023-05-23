#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

// 类的成员函数
class F
{
public:
    static int mul(int x, int y) {
        return x * y;
    }
    int divi(int x, int y) {
        return x / y;
    }
    double divd(double x, double y) {
        return x / y;
    }
    int Mul(int x, int y, int rate)
    {
        return x * y * rate;
    }
};
void mytest1()
{
    // bind
    using namespace placeholders;
    function<int(F, int, int)> func1 = bind(&F::divi, _1, _2, _3);
    function<int(int, int)> func2 = bind(&F::divi, F(), _1, _2);
 
    func1(F(), 10, 2);
    func2(10,2);
 
    function<int(F, int, int, int)> func3 = bind(&F::Mul, _1, _2, _3, _4);
    function<int(int, int, int)> func4 = bind(&F::Mul, F(), _1, _2, _3);
    function<int(int, int)> func5 = bind(&F::Mul, F(), _1, _2, 10);
 
    func3(F(), 2,5,10);
    func4(2,5,10);
    func5(2,5);
}

int main()
{
  mytest1();
  return 0;
}
