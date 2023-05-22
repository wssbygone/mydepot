#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class MyPrint
{
public:
    MyPrint(){}
    ~MyPrint(){}

    void myPrint(int num)
    {
        cout << " " << num;
    }
};

int main(int argc, char *argv[])
{
    vector<int> tempVector(6,1);
    unique_ptr<MyPrint> pMyPrint(new MyPrint);

    //(1) pMyPrintָ��ʹ�á���ֵ����ʽ���뵽lambda���ʽ�У����������һ�еĴ���
//    for_each(tempVector.begin(),tempVector.end(),[=](int numInt){
//        pMyPrint->myPrint(numInt);
//    });

    // (2) pMyPrintָ��ʹ�á����á���ʽ���뵽lambda���ʽ��
    cout << "=======test unique_ptr======" << endl;
    for_each(tempVector.begin(),tempVector.end(),[&pMyPrint](int numInt){
        pMyPrint->myPrint(numInt);
    });

    cout << "\n=======test shared_ptr======" << endl;
    shared_ptr<MyPrint> pPrintf(new MyPrint);
    // (3) pPrintfָ��ʹ�á���ֵ����ʽ���뵽lambda���ʽ��
    for_each(tempVector.begin(),tempVector.end(),[=](int numInt){
        pPrintf->myPrint(numInt);
    });

    // (4) pPrintfָ��ʹ�á����á���ʽ���뵽lambda���ʽ��
    cout << "\n==============" << endl;
    for_each(tempVector.begin(),tempVector.end(),[&](int numInt){
        pPrintf->myPrint(numInt);
    });

    cout << endl;
    cout << "Hello World!" << endl;
    return 0;
}



/* 
=======test unique_ptr======
 1 1 1 1 1 1
=======test shared_ptr======
 1 1 1 1 1 1
==============
 1 1 1 1 1 1
Hello World!
*/


