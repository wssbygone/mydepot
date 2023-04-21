#include <iostream>
#include <queue>
#include <array>
#include <functional>
using namespace std;

int main()
{
    //创建一个空的priority_queue容器适配器
    std::priority_queue<int>values;
    //使用 push() 成员函数向适配器中添加元素
    values.push(3);//{3}
    values.push(1);//{3,1}
    values.push(4);//{4,1,3}
    values.push(2);//{4,2,3,1}
    //遍历整个容器适配器
    while (!values.empty())
    {
        //输出第一个元素并移除。
        std::cout << values.top()<<" ";
        values.pop();//移除队头元素的同时，将剩余元素中优先级最大的移至队头
    }
    std::cout<<std::endl;
    return 0;
}
