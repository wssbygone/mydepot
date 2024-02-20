// 类的成员函数里条件变量的lambda表达式可以直接access类似成员变量
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class MyClass {
public:
    void someFunction() {
        std::unique_lock<std::mutex> lk(mutex_);
        
        // 使用lambda表达式作为等待条件
        matempty_.wait(lk, [&]() {
            return !dataReady_; // 访问类的成员变量!!
        });

        std::cout << "Data is ready!" << std::endl;
    }

    void setDataReady(bool ready) {
        std::lock_guard<std::mutex> lk(mutex_);
        dataReady_ = ready;
        matempty_.notify_one();
    }

private:
    std::mutex mutex_;
    std::condition_variable matempty_;
    bool dataReady_ = false;
};

int main() {
  MyClass obj;
  
  std::thread t1([&obj](){
      std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep 2s run  main thread firstly
      obj.setDataReady(true);
  });

  obj.someFunction();

  t1.join();
  return 0;
}

