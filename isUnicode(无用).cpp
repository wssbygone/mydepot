#include <fstream>
#include <iostream>
using namespace std;
 
int main(int argc, char * argv[])
{
	int xx= 131;
	cout<<hex<<xx<<endl;
    ifstream fin(argv[1],ios::binary);
    unsigned char  s2;
    fin.read((char*)&s2, sizeof(s2));//读取第一个字节，然后左移8位
	cout<<hex<<s2<<"]s2 size:"<<sizeof(s2)<<endl;	
    unsigned int p = s2;
	p=p<<8;
	s2=0;
    fin.read((char*)&s2, sizeof(s2));//读取第二个字节
	cout<< hex<<s2<<"]s2 size:"<<sizeof(s2)<<endl;		
    p +=s2;
	cout<<"p:"<< hex<< p <<endl;			
 
    string code;
 
    switch(p)//判断文本前两个字节
    {
    case 0xfffe:  //65534
        code = "Unicode";    
        break;
    case 0xfeff: //65279
        code = "Unicode big endian";
        break;
    case 0xefbb: //61371
        code = "UTF-8";     
        break;
 default: 
        code = "ANSI"; 
     }
     fin.close(); 
	 
	 cout<<"code:"<< code <<endl;
     return 0;
}
