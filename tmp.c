#include<stdlib.h>
#include<stdio.h>


void fun(const char* url)
{
	char buf1[64] = {0};
	char buf2[64] = { 0 };
	sscanf(url,"%*[^|]|%[^|]|%s",buf1,buf2);
	//printf("【%s %s】\n",buf1,buf2);
	
}
int main(int argc, char* argv[])
{
	/*
    const char *savePath = "z1.txt";
    std::string savePath=arv[];
    if(remove(savePath)==0)
    {
        cout<<"删除成功"<<endl;        
    }
    else
    {
        cout<<"删除失败"<<endl;        
    } */
	fun("xx|gg|hh");

    return 0;
}