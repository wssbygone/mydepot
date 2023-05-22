#include <iostream>
using namespace std;
#include <string>


//交换函数模板
template<class T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


//排序算法
template<typename T, std::size_t len> //声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T是一个通用数据类型
void mySort(T (&arr)[len])
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //认定最大值的下标
		for (int j = i; j < len; j++)
		{
			//认定的最大值比遍历出的数值要小，说明j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j; //更新最大值下标
			}
		}
		//交换max和i元素
		mySwap(arr[max], arr[i]);
	}
}


//提供打印数组模板
template<typename T, std::size_t len>
void printArray(T (&arr)[len])
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArr[] = "badcfe";
	//int num = sizeof(charArr) / sizeof(char);
	mySort(charArr);
	printArray(charArr);
}

	   
int main()
{
  test01();
  return 0;
}

