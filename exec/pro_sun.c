#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    printf("我是儿子，我的名字叫%d,我爹叫%d.我现在成为了一个科学家！\n",getpid(),getppid());

    return 0;
}
