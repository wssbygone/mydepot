#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

atomic_flag lock = ATOMIC_FLAG_INIT;

void appendnum(int x) {
  while (lock.test_and_set()) {
    cout << "[s " << x << "]" << endl;
  }
  cout << "thread #" << x << endl;
  lock.clear();
}

int main() {
  vector<thread> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(thread(appendnum, i + 1));
  }
  for (auto& th : v) {
    th.join();
  }
  return 0;
}
