#include<string>    
#include<iostream>  
#include<string.h>  
using namespace std;

int main()
{
    string a,b,c;
    std::string str("background:,223,222,88");
    //std::string str2(schemaStr);
    int len = strlen("background:");	
    std::string tmp=str.substr(len);
    std::cout<<tmp<<"\n"<<std::endl;
	
    int p1 = tmp.find(',');
    //std::cout<<"p1:"<<p1<<std::endl;
    int p2 = tmp.rfind(',');
    a = tmp.substr(0,p1);
    b = tmp.substr(p1+1,8);
    c = tmp.substr(p2 + 1);	
	
    std::cout<<"["<<a<<"]["<<b<<"]["<<c<<"]"<<std::endl;

    return 0;
}
