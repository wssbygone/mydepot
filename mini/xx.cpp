#include <fstream>
#include <bitset>
#include <iostream>
#include <string>

#include <cstdio>
class SS {
//  char* bufferp;
//  size_t length;
  union {
    char local_buffer[16];
    size_t capacity;
  };
};

int main () {

  std::cout<<sizeof(SS)<<std::endl;    
  return 0;
}
 
