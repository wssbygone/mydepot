// 使用指针引用

#include<iostream>
using namespace std;
 
void allocate_double(double*& p, size_t& n)
{
	cout << "How many doubles should I allocate" << endl;
	cout << "Please type a positive integer answer: ";
	cin >> n;
	p = new double[n];
	p[0]= 1.11;
	p[1]= 2.22;	
	
}

int main()
{
	double* numbers;
	size_t array_size;
	allocate_double(numbers, array_size);
	cout << numbers[0]<< numbers[1]<< endl;
	
	delete [] numbers; 
}



