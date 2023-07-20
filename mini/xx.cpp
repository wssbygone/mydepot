#include <fstream>
#include <bitset>
#include <iostream>
#include <string>


int main () {
  char buffer [80];
  std::fstream myfile;

  myfile.open ("zz.txt",std::fstream::in|std::fstream::out);

  // 读文件
  std::string strLine;
  while( getline(myfile, strLine) )
  {
     std::cout<<strLine<<std::endl; 
  }

  //写不进去，因为上一步的读触发了end of file 即eof错误标记。需要读之后写一句“myfile.clear()”;
  myfile.clear();
  myfile << "========="<<std::endl;
	
  myfile.close();

  std::bitset<8> s("10011011");
  std::string str= s.to_string();
  std::cout<<str<<std::endl;
  return 0;
}
 
