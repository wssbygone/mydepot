//#include<fstream>
#include<iostream>
#include<string.h>
#include<string>

using namespace std;

int isUnicode(std::string str)
{
	std:string tmp="file "+ str + "|grep -iE \"Unicode|UTF-8\"";
	char buf[1024]={0}; 
	FILE *stream = popen( tmp.c_str(), "r" );
	if( NULL==stream )
	{
		std::cout<<"popen fail!"<<std::endl;
		return -1;
	}
	fread( buf, sizeof(char), sizeof(buf), stream);
	if(std::string(buf).length()>0)
	{
		cout<<"["<<buf<<"]"<<endl;
		return 1;
	}
	else
	{
		return 0;
	}
	pclose( stream ); 	
}

int main(int argc, char* argv[])
{ 
    if(argc!=2)
	{
		std::cout<<"para error"<<std::endl;
		return -1;
	}
	if(isUnicode(argv[1]))
	{
		std::cout<<"good !!!"<<std::endl;
	}	
    return 0;	
} 
