#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char* argv[])
{
	
    const char *savePath = "z1.txt";
    std::string savePath=arv[];
    if(remove(savePath)==0)
    {
        cout<<"删除成功"<<endl;        
    }
    else
    {
        cout<<"删除失败"<<endl;        
    }
    return 0;
}