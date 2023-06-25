#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include <time.h>
using namespace std;

char buf[4100];
std::size_t cnt=0;

class CTestClass{
  char m_chBuf[4096];

public:
  void *operator new(size_t size){
    if(0==(++cnt)%100000)
      cout<<"op new:"<<size<<endl;
    return (void *)buf;
  }

  void operator delete(void *p) 
  {
    // if(0==(cnt)%100000)
    // cout<<"op del"<<endl;
  }
};

int main(){
  clock_t count = clock();
 
  for(unsigned int i=0; i< 1000000; i++){
    CTestClass *p = new CTestClass;
      delete p;
  }

  std::cout << "Interval = " << clock() - count  << " ticks" << std::endl;

  return 0;
}
