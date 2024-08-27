#include <stdio.h>
#include "b.h"
#include "a.h"
 
int addB(int a, int b)
{
    printf("addB\n");
    return addA(a, b);
}
