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



std::string getFreeMemory()
{
	std::string cmd = "awk \'/MemFree/{print $2/1024}\' /proc/meminfo";
	std::cout<<"cmd:"<<cmd <<std::endl;
	char buf[1024] = { 0 };
	FILE *stream = popen(cmd.c_str(), "r");
	if (NULL == stream) return "";

	fread(buf, sizeof(char), sizeof(buf), stream);
	return std::string(buf);
}

 

int main (int argc, char* argv[])
{
	
 	std::cout<< getFreeMemory() <<std::endl;

    return 0;
}