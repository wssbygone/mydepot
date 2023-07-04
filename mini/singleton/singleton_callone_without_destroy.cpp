#include<memory>
#include<mutex>
#include<iostream>
#include <thread>

#define SINGLETON_CTOR(x) \
     private:\
            x() = default;\
            x(const x&)=delete;\
            x& operator=(const x&)=delete;

class SingletonUsePtr2
{
    SINGLETON_CTOR(SingletonUsePtr2);
public:
    ~SingletonUsePtr2() {std::cout << "~SingletonUsePtr2" << std::endl;}
    static SingletonUsePtr2& Instance()
    {
        static std::once_flag s_flag;
        std::call_once(s_flag, []() {
            _ptr.reset(new SingletonUsePtr2);
        });

        return *_ptr;
    }
private:
    static std::unique_ptr<SingletonUsePtr2> _ptr;
};

  std::unique_ptr<SingletonUsePtr2> SingletonUsePtr2::_ptr;

int main()
{
  auto& ss=SingletonUsePtr2::Instance();

//  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return 0;
}
