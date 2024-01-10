#include <mutex>
#include <deque>
#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
void print_id (int id) {
  std::unique_lock<std::mutex> lck(mtx);// 首先执行到这一句的第一个线程会lck.lock(), 其他线程则会卡在这一句；
  cv.wait(lck);   
  //这个函数比较有意思，当执行到这一行的时候，他会lck.unlock(), 然后条件变量接替开始阻塞，这样第二个线程就会
  //执行上一句lck初始化，然后所有线程都会走一遍lck.lock()->lck.unlock()->阻塞，然后所有线程都停留在这个位置，
  //等待通知，最先得到通知的线程会调用lck.lock()(至于谁先得到通知线程去竞争了)，这样就保证下面这句命令操作的原子性
  std::cout << "thread " << id << '\n';
}//类似于只能指针，lck自动unlock
 
void go() {
//  std::unique_lock<std::mutex> lck(mtx);
  cv.notify_all();
}
 
int main() {
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i) threads[i] = std::thread(print_id,i);
  std::cout << "10 threads ready to race...\n";
  go();       //主线程lck.lock()->通知所有wait->      
  for (auto& th : threads) {
     th.join();
  }
  return 0;
}
