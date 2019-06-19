#include<iostream>
#include<string>
#include <memory>
using namespace std;

int main(int argc, char* argv[])
{
	std::shared_ptr<int> sp0(new int(2));
	std::shared_ptr<int> sp1(new int(11));
	std::shared_ptr<int> sp2 = sp1;
	printf("%d\n", *sp0);               // 2
	printf("%d\n", *sp1);               // 11
	printf("%d\n", *sp2);               // 11
	sp1.swap(sp0);
	printf("%d\n", *sp0);               // 11
	printf("%d\n", *sp1);               // 2
	printf("%d\n", *sp2);               // 11
    std::cout<<"==============="<<std::endl;
	
	std::shared_ptr<int> sp3(new int(22));
	std::shared_ptr<int> sp4 = sp3;
	printf("%d\n", *sp3);               // 22
	printf("%d\n", *sp4);               // 22
	printf("%d\n", sp3.use_count());    // 2
	printf("%d\n", sp4.use_count());    // 2	
	sp3.reset();                        
	printf("%d\n", sp3.use_count());    // 0
	printf("%d\n", sp4.use_count());    // 1
	printf("%d\n", &*sp3);              // 0
	printf("%d\n", &*sp4);              // 指向所拥有对象的地址	
    std::cout<<"`````````````"<<std::endl;
	
	std::shared_ptr<int> sp5(new int(22));
	std::shared_ptr<int> sp6 = sp5;
	std::shared_ptr<int> sp7 = sp5;
	printf("%d\n", *sp5);               // 22
	printf("%d\n", *sp6);               // 22
	printf("%d\n", *sp7);               // 22
	printf("%d\n", sp5.use_count());    // 3
	printf("%d\n", sp6.use_count());    // 3
	printf("%d\n", sp7.use_count());    // 3
	sp5.reset(new int(33));      
	std::cout<<"#############"<<std::endl;
	
	printf("%d\n", sp5.use_count());    // 1
	printf("%d\n", sp6.use_count());    // 2
	printf("%d\n", sp7.use_count());    // 2
	printf("%d\n", *sp5);               // 33
	printf("%d\n", *sp6);               // 22
	printf("%d\n", *sp7);               // 22
	
	return 0;
} 
