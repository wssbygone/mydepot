#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <vector>
#include <typeinfo>
using namespace std;
const char* version = "3.2.2";
#define version "3.2.2"

std::vector<std::string> split(std::string s,char token)
{
    stringstream iss(s);
    std::string word;
    std::vector<std::string> vs;
    while(getline(iss,word,token)){
        vs.push_back(word);
		cout<<"["<<word<<"] ";
    }
	cout<<endl;
    return std::move(vs);
}

int main (int argc, char* argv[])
{
	if (argc <= 1)	{
		printf("No command specified\n");
		return 0;
	}	
	
	if ( ( 2 == argc )
		  && ( !strcmp(argv[1], "version") 
		  || !strcmp(argv[1], "-v")
	      || !strcmp(argv[1], "--version") )
	    )		 
	{
		cout<<"objParser version: v"<<version<<endl;
	}		

#if 0		
	//split("it,is,a,world",'.');
	string str = "he is@ a@ good boy";
	cout<<str<<endl;
	auto it=str.find(str);
	if( it ==std::string::npos)
	{
		cout<< "no find"<<std::endl;
		return 0;
	}
	str=str.replace(it,std::string("he is@ a@ good boy").size(),"");
	if(str.empty())
		cout<<"["<<str<<"]"<<endl; 

    string a="abcdefghigklmn";
    string b="abc";
    string c="123";
    string::size_type idx;
     
    idx=a.find(b); //在a中查找b.


    if(idx == string::npos )   
        cout << "not found\n";
    else 
        cout <<"found at"<<idx<< endl;

    idx=a.find(c);//在a中查找c。
    if(idx == string::npos )//不存在。
        cout << "not found\n";
    else//存在。
        cout <<"found\n";

	map<string,string> myMap;
	const char* s1="xx";
	const char* s2="this is a test";
	myMap[s1]=s2;
	myMap["hh"]="miaowu";
	for(auto it=myMap.begin();it!=myMap.end();it++)
	{
	   
	  cout<<it->first<<" "<<it->second<<endl;
	}
#endif

    return 0;
}