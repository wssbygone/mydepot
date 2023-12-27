// https://owent.net/2014/962.html
#include "a.h"
#include <cstdio>
#include <iostream>

foo_class foo_class::_;


foo_class::foo_class() {
    m = 10;
    printf("foo_class::foo_class(), this-> %p\n", this);
//    std::cout<<"xxx"<<std::endl;
}

foo_class::~foo_class() {
    printf("foo_class::~foo_class(), this-> %p\n", this);
//    std::cout<<"~xxx"<<std::endl;
}

// gcc -g a.cpp -o libtest_a.a -c -fPIC
