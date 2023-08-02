#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#if 0
#ifdef _cplusplus
extern "C"{
#endif
void* memset(void*, int, size_t);
void *malloc(size_t);
void fun(int);
#ifdef _cplusplus
}
#endif
#endif

void fun(int i)
{
  printf("%d\n",i);
}

int main()
{
  char* arr= (char*)malloc(20);
  memset(arr,0,20);
  
  fun(2);

  free(arr);
  return 0;
}
