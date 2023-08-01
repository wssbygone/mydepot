#include <iostream>
#include <string>
#include <typeinfo>
#include <stdio.h>
#include <vector>

#ifdef _cplusplus
extern "C"{
#endif
void* memset(void*, int, size_t);
#ifdef _cplusplus
}
#endif



int main()
{
  char* arr= (char*)malloc(20);
  memset(arr,0,20);
  
  
  free(arr);
  return 0;
}
