#include <cstdio>

#include "a.h"


extern "C" {

void dll_func() {
    foo_class::_.m += 100;
    printf("&foo_class::_ = %p, foo_class::_.m = %d\n", &foo_class::_, foo_class::_.m);
}

}

// gcc -g c.cpp -o libtest_c.so -shared -fPIC -L$PWD -ltest_a
