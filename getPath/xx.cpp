#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(){
    const char *file_name = "xx";
    char abs_path_buff[PATH_MAX];

    if(realpath(file_name, abs_path_buff)){
        printf("%s %s\n", file_name, abs_path_buff);
    }
    else{
        printf("the file '%s' is not exist\n", file_name);    
    }

    return 0;
}
