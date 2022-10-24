#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

atomic<int> a(0);
atomic<int> b(0);

void valueSet() {
  int t = 1;
  a = t;
  b = 2;
}

void observer() {
  cout << "a = " << a << ","
       << "b = " << b << endl;
}

int main() {
  thread t1(valueSet);
  thread t2(observer);

  t1.join();
  t2.join();

  cout << "in main: "
       << "a = " << a << ", "
       << "b = " << b << endl;
  return 0;
}
