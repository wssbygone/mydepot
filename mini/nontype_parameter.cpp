#include <string>
#include <iostream>
#include <cstring>

//这里是写了一个模板
template<unsigned M,unsigned N>
int compare(char (&leftStr)[M], char (&rightStr)[N])
{  
    std::cout<<"M:"<< M << "\tN:" << N <<std::endl;
    return strcmp(leftStr, rightStr);
}

int main()
{
    char str1[] = "abcde";
    char str2[] = "abcdefg";
    
   if( compare(str1, str2) )
     std::cout<<"!="<<std::endl;
   else
     std::cout<<"=="<<std::endl;
   return 0;
}

