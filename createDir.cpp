#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

bool CreateDirectory(const char *szDirectoryPath, int iDirPermission = 0766)
{
    if (NULL == szDirectoryPath)
    {
        return false;
    }
    int iPathLength = static_cast<int>(strlen(szDirectoryPath));

    if (iPathLength > 1024)
    {
        return false;
    }

    char szPathBuffer[1024] = { 0 };

    memcpy(szPathBuffer, szDirectoryPath, iPathLength);
	if(szDirectoryPath[iPathLength-1]!='/')
	{
        // force trailing / so we can handle everything in loop
        szPathBuffer[iPathLength]='/';
		iPathLength++;
    }

    for (int i = 0; i < iPathLength; ++i)
    {
        char &refChar = szPathBuffer[i];
        //目录分隔符
        if (('/' == refChar) && (0 != i))
        {
            refChar = '\0';
            //判断当前目录是否存在
            int iStatus = access(szPathBuffer, F_OK);
            if (0 != iStatus)
            {
                if ((ENOTDIR == errno) || (ENOENT == errno))
                {
                    //以指定权限创建目录
                    iStatus = mkdir(szPathBuffer, iDirPermission);
                    if (0 != iStatus)
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            refChar = '/';
        }
    }
    return true;
}

int main()
{
	int ret=CreateDirectory("./materials/xx/yy",0766);
	std::cout<<"["<<ret<<"]"<<std::endl;
	return 0;
}