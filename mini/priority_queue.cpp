#include <iostream>
#include <queue>
#include <array>
#include <functional>
using namespace std;

int main()
{
    //����һ���յ�priority_queue����������
    std::priority_queue<int>values;
    //ʹ�� push() ��Ա�����������������Ԫ��
    values.push(3);//{3}
    values.push(1);//{3,1}
    values.push(4);//{4,1,3}
    values.push(2);//{4,2,3,1}
    //������������������
    while (!values.empty())
    {
        //�����һ��Ԫ�ز��Ƴ���
        std::cout << values.top()<<" ";
        values.pop();//�Ƴ���ͷԪ�ص�ͬʱ����ʣ��Ԫ�������ȼ�����������ͷ
    }
    std::cout<<std::endl;
    return 0;
}
