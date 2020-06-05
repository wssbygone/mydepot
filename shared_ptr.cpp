// 考虑对象 b 中的 m_spa 是我们能最后一个看到 a 对象的共享智能指针, 其 use_count 为2, 因为对象 b 中持有 a
// 的指针,所以当 m_spa 说再见时, m_spa 只是把 a 对象的 use_count 改成1; 对象 a 同理; 然后就失去了 a,b 对象的联系.
// 解决此方法是使用 weak_ptr 替换 shared_ptr . 以下为错误用法, 导致相互引用, 最后无法释放对象 
#include<iostream>
#include<string>
#include <memory>
#include <vector>
using namespace std;

class CB;
class CA
{
public:
	CA(){}
	~CA(){std::cout<<"~CA()"<<std::endl;}

	void Register(const std::shared_ptr<CB>& sp)
	{
		m_sp = sp;
	}

private:
	std::shared_ptr<CB> m_sp;
};

class CB
{
public:
	CB(){} 
	~CB(){std::cout<<"~CB()"<<std::endl;}

	void Register(const std::weak_ptr<CA>& sp)
	{
		m_sp = sp;
	}

private:
	std::weak_ptr<CA> m_sp;
};

class AA
{
public:
	AA(){}
	~AA() {std::cout<<"destruct data:"<< data <<std::endl;}

//private:
	int data = 1;
};


class A
{
public:
    A(){cout << "constructor" << endl;};
    ~A(){cout << "destructor"  << endl;};
};


void fun(AA* pdata)
{
	pdata->data = 2;
}

int main(int argc, char* argv[])
{	
/*  导致内存泄露的用法   
	std::shared_ptr<CA> spa(new CA);
	std::shared_ptr<CB> spb(new CB);

	spb->Register(spa);
	spa->Register(spb);
	printf("%d\n", spb.use_count()); // 2
	printf("%d\n", spa.use_count()); // 2	
	
	// 测试用get()取出sp指针托管的普通指针
	std::shared_ptr<AA> spAA = std::make_shared<AA>();
	std::cout<<"\n\n\ndata="<< spAA->data <<std::endl;
	fun(spAA.get());	
	std::cout<<"data="<< spAA->data <<std::endl;  */
	
    shared_ptr<A> sharedptr (new A);
    std::vector<shared_ptr<A> > test;
    test.push_back(sharedptr);
	
	cout<< "before: "<<sharedptr.use_count()<<endl;
    test.clear();
	cout<<"after: " <<sharedptr.use_count()<<endl;	
	
    cout << "I am here" << endl;
	
	return 0;
} 
