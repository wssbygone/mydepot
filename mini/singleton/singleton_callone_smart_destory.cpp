// 在static成员函数里使用lambada表达式，没办法捕获类的this指针,也不需要通过捕获this而是直接
// 访问来的静态成员变量,甚至直接call静态成员函数.
#include <memory>
#include <mutex>
#include <thread>
#include <iostream>

// Disable the copy and assignment operator for a class.
#define DISABLE_COPY_AND_ASSIGN(classname) \
 private: \
  classname(const classname&); \
  classname& operator=(const classname&)

class Caffe {
 public:
  ~Caffe() { std::cout<<"~Caffe" <<std::endl;}
 
  static Caffe& Get() {//
    std::call_once(once_flag_, []() { singleton_.reset(new Caffe()); std::cout<< "Get" <<std::endl; });
    return *singleton_;
  }

 private:
  static std::once_flag once_flag_;
  static std::shared_ptr<Caffe> singleton_; // it's OK to use std::unique_ptr,more fast
  // The private constructor to avoid duplicate instantiation.
  Caffe() {}

  DISABLE_COPY_AND_ASSIGN(Caffe);
};

std::shared_ptr<Caffe> Caffe::singleton_;
std::once_flag Caffe::once_flag_;

void do_onceflag(int flag) {
  Caffe& s = Caffe::Get();
 
  std::cout << "address "<<flag<<" :" << &s << std::endl;
}

int main() {
  std::thread t1(do_onceflag, 0);
  std::thread t2(do_onceflag, 1);

  t1.join();
  t2.join();
 
  return 0;
}
