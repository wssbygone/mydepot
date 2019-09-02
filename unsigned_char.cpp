#include <stdio.h>
 
static void func(unsigned char uc)
{
    char c;
    int i, j;
    unsigned int ui, uj;
 
    c = uc;
    i = (int)c;
    j = (int)uc;
    ui = (unsigned int)c;
    uj =(unsigned int)uc;
    printf("%%c: %c, %c\n", c, uc);
    printf("%%x: %x, %x\n", c, uc);
    printf("%%u: %u, %u\n", ui, uj);
    printf("%%d: %d, %d\n", i, j);
}
 
int main(int argc, char *argv[])
{
    func(0x80);
    func(0x7f);
 
    return 0;
}