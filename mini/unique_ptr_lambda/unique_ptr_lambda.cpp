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

    //(1) pMyPrint指针使用《赋值》方式传入到lambda表达式中，会出现上述一中的错误
//    for_each(tempVector.begin(),tempVector.end(),[=](int numInt){
//        pMyPrint->myPrint(numInt);
//    });

    // (2) pMyPrint指针使用《引用》方式传入到lambda表达式中
    cout << "=======test unique_ptr======" << endl;
    for_each(tempVector.begin(),tempVector.end(),[&pMyPrint](int numInt){
        pMyPrint->myPrint(numInt);
    });

    cout << "\n=======test shared_ptr======" << endl;
    shared_ptr<MyPrint> pPrintf(new MyPrint);
    // (3) pPrintf指针使用《赋值》方式传入到lambda表达式中
    for_each(tempVector.begin(),tempVector.end(),[=](int numInt){
        pPrintf->myPrint(numInt);
    });

    // (4) pPrintf指针使用《引用》方式传入到lambda表达式中
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


