#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    std::ifstream fin;

    //sprintf(tmp,"%s%s%s","\"", mInFile.c_str(), "\"");
     //fin.open(tmp);
	std::string str="tt test.txt",tempstr;
    fin.open(str.c_str()); 
    if (fin.fail())
    {
        std::cout << "open input file: [" << str << "] failed. @"<<__LINE__<< std::endl;
        return false;
    }
	fin>>tempstr;
	cout<<tempstr<<endl;
	fin.close();
	cout<<"================"<<endl;	
	
	return 0;
} 
