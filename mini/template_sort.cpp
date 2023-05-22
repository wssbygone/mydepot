#include <iostream>
using namespace std;
#include <string>


//��������ģ��
template<class T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


//�����㷨
template<typename T, std::size_t len> //����һ��ģ�壬���߱�������������н�����T��Ҫ����T��һ��ͨ����������
void mySort(T (&arr)[len])
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //�϶����ֵ���±�
		for (int j = i; j < len; j++)
		{
			//�϶������ֵ�ȱ���������ֵҪС��˵��j�±��Ԫ�ز������������ֵ
			if (arr[max] < arr[j])
			{
				max = j; //�������ֵ�±�
			}
		}
		//����max��iԪ��
		mySwap(arr[max], arr[i]);
	}
}


//�ṩ��ӡ����ģ��
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
	//����char����
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

