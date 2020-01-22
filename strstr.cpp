#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char arr[]="Ambient";
    std::cout<<strstr(arr,"mxbi")<<std::endl;
	if( nullptr == strstr(arr,"mxbi"))
	{
		std::cout<<"no match"<<std::endl;
	}
    return 0;
}
