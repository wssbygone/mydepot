#include <fstream>
#include <iostream>
#include <string>
 
int main()
{
  std::string filename{"test.bin"};
  std::fstream s{filename, s.binary | std::ios::trunc | std::ios::in | std::ios::out};
 
  if (!s.is_open())
    std::cout << "failed to open " << filename << '\n';
  else
  {
    // write
    double d{3.14};
    s.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
    s << 123 << "abc";                              // text output

    // for fstream, this moves the file position pointer (both put and get)
    s.seekp(0);
 
    // read
    d = 2.71828;
    s.read(reinterpret_cast<char*>(&d), sizeof d); // binary input
    int n;
    std::string str;
    if (s >> n >> str )                             // text input
    { 
      std::cout << "read back from file: " << d << ' ' << n << ' ' << str << '\n';
    }

    if( s.eof() )  
    {
      std::cout<<"eof" <<std::endl;
    }
    if(s.fail()) {
      std::cout<<"fail" <<std::endl;
    }
    if (s.bad()) {
      std::cout<<"bad"<<std::endl;
    }
  }
}
