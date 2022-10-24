#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<bool> ready(false);
std::atomic<bool> winner(false);

void count1m(int n) {
  while (!ready) {
  }  // wait for ready

  for (int i = 0; i < 1000000; i++) {
  }  // count to 1M

  if (!winner.exchange(
          true)) {  //只有第一个执行exchange的线程会返false,并输出下面的语句,其余线程都返回true无法进入if
    std::cout << "thread #" << n << " won!\n";
  }
}

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 10; i++) {
    threads.push_back(std::thread(count1m, i + 1));  //创建10个线程
  }
  ready.store(true);  //开始
  for (auto& th : threads) th.join();
  return 0;
}

// https://blog.csdn.net/princeteng/article/details/103934620