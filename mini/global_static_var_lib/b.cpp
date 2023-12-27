#include <dlfcn.h>
#include <errno.h>
 
#include <cstdio>
#include <cstdlib>

#include "a.h"


int main() {
    void (*dll_func)() = NULL;
    char* error = NULL;

    foo_class::_.m += 1000;
    printf("&foo_class::_ = %p, foo_class::_.m = %d\n", &foo_class::_, foo_class::_.m);


    void* handle = dlopen("./libtest_c.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return -1;
    }

    dlerror();

    *(void **) (&dll_func) = dlsym(handle, "dll_func");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        return -2;
    }

    (*dll_func)();

    dlclose(handle);

    return 0;
}

// gcc -g b.cpp -o test_b -fPIC -ldl -L$PWD -ltest_a -lstdc++

//output:

/*
foo_class::foo_class(), this-> 0x55b79377701c
&foo_class::_ = 0x55b79377701c, foo_class::_.m = 1010
foo_class::foo_class(), this-> 0x0x7ff7cfb5f04c
&foo_class::_ = 0x7ff7cfb5f04c, foo_class::_.m = 110
foo_class::~foo_class(), this-> 0x0x7ff7cfb5f04c
foo_class::~foo_class(), this-> 0x55b79377701c
*/
