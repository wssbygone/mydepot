#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(void)
{
    pid_t pid;

    pid = fork();
    if(pid < 0)
    {
        printf("媳妇难缠，儿子死了，死亡代码%d.\n",errno);
    }
    else if(pid == 0)
    {
      printf("儿子出生了！\n");
      execle("pro_sun",NULL,NULL,NULL);
    }
    else
    {
        printf("我是爹，我的名字叫%d,我的儿子叫%d.\n",getpid(),pid);
    }
    wait(NULL);
    return 0;
}
