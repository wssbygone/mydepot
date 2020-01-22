#include<iostream>
#include<string.h>
#include<algorithm>
#include <typeinfo>
using namespace std;

struct MyStruct
{
	int i;
	int k;
	long j;
	char* l;	
};

bool IsOdd (int i) { return ((i%2)==1); }

int main()
{
	std::string strMsg="android jaaabshe";
	cout<<"处理前： "<<strMsg<<endl;
    std::string xx;
    // for (auto it = strMsg.begin(); it != strMsg.end(); it++)
    // {
        // if (*it == 'a')  *it = '';
        // cout<<"["<<typeid(*it).name()<<"]"<<endl;
    // }	
	strMsg.erase(std::remove(strMsg.begin(), strMsg.end(), 'a'), strMsg.end());
	cout<<"处理后： "<<strMsg<<endl;

	cout<<"pointer size "<<sizeof(MyStruct)<<endl;

	//unsigned int b = 241;	
	//char a=b;

    //std::cout<<static_cast< int>(a)<<std::endl;
	//uint64_t size = std::filesystem::file_size("a.out");
	//std::cout<<size<<std::endl;	
		
	int myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

	int* pbegin = myints;                          // ^
	int* pend = myints+sizeof(myints)/sizeof(int); // ^                 ^

	pend = std::remove_if (pbegin, pend, IsOdd);   // 2 4 6 8 ? ? ? ? ? 
												   // ^       ^
	std::cout << "the range contains:";
	for (int* p=pbegin; p!=pend; ++p)
		std::cout << ' ' << *p;
	
	//std::cout<< "sizeof(myints)/sizeof(int): "<< sizeof(myints)/sizeof(int) << std::endl ;
	//for(int i=0;i< sizeof(myints)/sizeof(int);i++)
	//	std::cout<<" "<< myints[i];
	// 打印出 2 4 6 8 0 397194040 32674 0 24346664 说明后面的值是不确定的，并不是
	//std::cout<<std::endl;
		
	std::cout << '\n';	
	
    return 0;
}
