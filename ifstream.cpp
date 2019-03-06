#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	cout<<argv[0]<<"\t"<<argv[1]<<endl;
	ifstream fin(argv[1]); 
	//ofstream fout("b.txt"); 
	if(!fin)
	{
		cout<<"open file ["<<argv[1]<<"] failed!"<<endl;
		return -1;
	}
	char input;
	cout<<"================"<<endl;
	while (!fin.eof())
	{		
		//string str1,str2,str3,str4;
		double str1,str2,str3,str4;
		if( fin.bad()== false && fin.fail()== false )
		{
			fin>>str1>>str2>>str3;				
		}
		else
		{
			cout<<"read txt fail"<<endl;
			fin.close();
			return -1;
		}
	
		cout<<"["<<setprecision(4)<<str1<<"] "<<"["<<str2<<"] "<<"["<<str3<<"] "<<endl;		
        while ('\n' != input && !fin.eof())
        {
            fin.get(input);
        }
        //fin.get(input);		
		
		if(0)//' '==input)
		{
			while (input == ' ')   //ignore black space
			{
				fin.get(input);
			}                      //while循环将指针调整到第一个非空格符
			if('\n'==input) 
			{
				//fin.get(input);
				continue;
			}
			else if('\\'==input)      //第四组数换行写的
			{
				while('\n'!=input)
				{
					fin.get(input);					
				}
				//fin.get(input);
				fin>>str4;
				cout<<"["<<str1<<"] "<<"["<<str2<<"] "<<"["<<str3<<"] "<<"["<<str4<<"] "<<endl;
				fin.get(input);	
				
				while('\n'!=input)
				{
					fin.get(input);					
				}	
				//fin.get(input);
			}
			else if('0'<=input&& '9'>=input)   //4组数写到一组
			{
				fin>>str4;
				str4=input+str4;
				cout<<"["<<str1<<"] "<<"["<<str2<<"] "<<"["<<str3<<"] "<<"["<<str4<<"] "<<endl;
				fin.get(input);				
				while('\n'!=input)
				{
					fin.get(input);
				}
				//fin.get(input);		
			}
		}		
	}
	fin.close();
	cout<<"================"<<endl;	
	
	return 0;
} 
