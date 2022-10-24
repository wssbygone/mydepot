#include <atomic>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int i) {
  while (!ready.load())
    ;
  for (int i = 0; i < 1000000; i++)
    ;

  if (!winner.test_and_set())
    std::cout << "winner: " << i << std::endl;
  else
    std::cout << "non-winner: " << i << std::endl;
}

int main() {
  std::vector<std::thread> ths;
  for (int i = 0; i < 10; i++) ths.emplace_back(count1m, i);
  ready.store(true);
  for (int i = 0; i < 10; i++) ths[i].join();
  std::cout << "exit" << std::endl;
  return 0;
}