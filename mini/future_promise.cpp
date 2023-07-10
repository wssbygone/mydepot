#include <atomic>
#include <chrono>
#include <future>  //std::future std::promise
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>  //std::ref模板传参的时候使用

void func2(int x, int y, std::promise<int> &promiseObj) {
  promiseObj.set_value(x + y);
}

int main() {
  auto c1 = std::chrono::high_resolution_clock::now();
  int a, b, x, y;
  a = 10, b = 8, x = 2, y = 4;

  int sum1, sum2;
  //声明一个类
  std::promise<int> promiseObj;
  //将future和promise关联
  std::future<int> futureObj = promiseObj.get_future();
  //模板传参的时候使用ref，否则传参失败
  std::thread t1(func2, a, b, ref(promiseObj));

  //不能直接复用上面的future和promise
  std::promise<int> promiseObj2;
  std::future<int> futureObj2 = promiseObj2.get_future();

  std::thread t2(func2, x, y, ref(promiseObj2));

  t1.join();
  t2.join();

  //获取值
  sum1 = futureObj.get();
  sum2 = futureObj2.get();
  std::cout << "sum1=" << sum1 << " sum2=" << sum2 << std::endl;

  std::cout << "sum1/sum2=" << sum1 / sum2 << std::endl;

  auto c2 = std::chrono::high_resolution_clock::now();
  float time_cv =
      std::chrono::duration_cast<std::chrono::nanoseconds>(c2 - c1).count() *
      1e-6;
  std::cout << "using time " << time_cv << " ms" << std::endl;

  return 0;
}
