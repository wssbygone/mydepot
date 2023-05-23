#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

void show(int i1, int i2)
{
    cout << i1 << endl;
    cout << i2 << endl;
}
 
void mytest2()
{
    int a = 10;
    int b = 20;
    show(a,b);
    function<void(int,int)> func1 = bind(show, placeholders::_2, placeholders::_1);
    func1(a,b);
 
    auto func2 = [](const string& s1, const string& s2)->void{cout << s1 << endl; cout << s2 << endl;};
    func2("haha", "hehe");
    function<void(string,string)> func3 = bind(func2, placeholders::_2, placeholders::_1);
    func3("haha", "hehe");
}
int main()
{
    mytest2();
    return 0;
}
