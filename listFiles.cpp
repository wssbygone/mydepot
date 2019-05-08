#include <iostream>
#include <string>
#include <cstring>
#include <dirent.h>

int readfiledir(const std::string mdir,const char* extName,std::string& tgtFile)
{
    struct dirent *ptr;
	DIR *dirp = opendir(mdir.c_str());
	if (dirp == NULL) 
	{
		std::cout<<"open dir failed!"<<std::endl;
		return -1;
	}
    while( ( ptr = readdir(dirp) )!= NULL )
    {
        //跳过'.'和'..'两个目录
        if( !strcmp(ptr->d_name,".") || !strcmp(ptr->d_name,"..") ||ptr->d_type == DT_DIR)
		{
            continue;			
		}
		if(strstr(ptr->d_name,extName))
		{
			std::cout << ptr->d_name << std::endl;
			tgtFile = ptr->d_name;
			break;			
		}
    }
    closedir(dirp);
    return 0;
}

int main()
{
	std::string tgtFile;
	readfiledir("./",".xml",tgtFile);
	return 0;
}