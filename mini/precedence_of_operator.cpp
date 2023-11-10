#include<stdio.h>

#define MAX(a,b) a>b?a:b    //no bracket
void set_number(int n, int number)
{
  int *p = &n;
  *p = number;
}

int main()
{
  int a = 3,b = 8,c = 5;
  int A = MAX(a|b,c)+20 ;
  printf("A=%d\n",A);

  int B = 5;
  set_number(B,6);
  printf("B=%d\n",B);
  
  printf("%d\n",3|8>5?3|8:5+1);  // > first then | 
}
