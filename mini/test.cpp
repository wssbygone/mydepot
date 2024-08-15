#include <iostream>
#include <thread>

struct S {
 long long a;
 long long b;
}s;

int main()
{
  std::thread th1([&] {
      for(int i=0; i<10000000; i++){
        s.a++;
        std::cout<<"a:"<<s.a<<std::endl;
      }
    }
  );

  std::thread th2([&] {
     for(int i=0; i<10000000; i++){
        s.b++;
        std::cout<<"b:"<<s.b<<std::endl;
     }
    }
  );

  th1.join();
  th2.join();
}
