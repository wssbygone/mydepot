#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;
int main()
{
	std::string str1 = "qwe bbb    333";
	
	std::vector<std::string> results3;
	// boost::token_compress_on 将连续多个分隔符当一个，默认没有打开，当用的时候一般是要打开的
	boost::split(results3, str1, boost::is_any_of(" "),boost::token_compress_on);

	for(auto r:results3 )
	{
		std::cout<<"["<< r <<"]"<<std::endl;
	}
	
	
	return 0;
}
