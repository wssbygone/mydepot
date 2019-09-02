#include<iostream>
#include<string>
#include<list>
#include <memory>
using namespace std;

int main()
{

	list<shared_ptr<string> > pstrList;
	pstrList.push_back(make_shared<string>("1111"));
	pstrList.push_back(make_shared<string>("2222"));
	pstrList.push_back(make_shared<string>("3333"));
	pstrList.push_back(make_shared<string>("4444"));

	for(auto &p:pstrList)
	{
		if(*p == "3333");
		{
			/*do some thing!*/
		}
		cout<<*p<<endl;
	}

	
	/*包含"3333"的数据我们已经使用完了！*/
	auto itr = pstrList.begin();
	for(; itr!=pstrList.end(); )
	{
		if( **itr == "3333" )
		{
			cout<<"remove " <<**itr<<endl;
			itr = pstrList.erase(itr);
		}
		else
		{
			itr++;
		}
	}

	for(auto p:pstrList)
	{
		cout<<*p<<endl;
	}

	while(1)
	{
		/*do somthing other works!*/
		/*遍历 pstrList*/    // 这样不仅节约了大量内存，也为容器的使用增加了效率　
		break;
	}
}