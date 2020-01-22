#include "staticlib.h"
#include "dlfcn.h"
#include "stdio.h"
int doSomethingDynamicish()
{
  void* handle = dlopen("./libdynlib.so",RTLD_NOW);
  if(!handle)
  {
    printf("could not dlopen: %s\n",dlerror());
    return 0;
  }

  typedef int(*dynamicfnc)();
  dynamicfnc func = (dynamicfnc)dlsym(handle,"GetMeANumber");
  const char* err = dlerror();
  if(err)
  {
    printf("could not dlsym: %s\n",err);
    return 0;
  }
  return func();
}