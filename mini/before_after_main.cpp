#include<iostream>
#include<stdlib.h>
#include<stdio.h>

__attribute__((constructor))void before_main() {
  printf("app before main\n");
}

__attribute__((destructor)) void after_main() {
    printf("app after main\n");
}

int main(int argc, char * argv[]) {
    //printf("excute main\n");
    std::cout<<"excute main" <<std::endl;
    return 0;
}
