#include <unistd.h>

#include <atomic>
#include <cassert>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

std::atomic<int> foo(0);
std::atomic_flag lock = ATOMIC_FLAG_INIT;

void add_foo() {
  int i = 10000;
  while (i-- > 0) {
    foo++;
    while (lock.test_and_set())
      ;
    std::cout << "add: " << foo << std::endl;
    lock.clear();
    // usleep(10);
  }
}

void sub_foo() {
  int i = 10000;
  while (i-- > 0) {
    foo--;
    while (lock.test_and_set())
      ;
    std::cout << "sub: " << foo << std::endl;
    lock.clear();
    // usleep(10);
  }
}
int main() {
  std::thread th2 = std::thread(add_foo);
  std::thread th1 = std::thread(sub_foo);
  th1.join();
  th2.join();
  std::cout << foo << std::endl;
  return 0;
}