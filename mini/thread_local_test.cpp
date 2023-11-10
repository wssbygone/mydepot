#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

thread_local int i = 0;
std::mutex mtx_;
int func(int val)
{
      std::unique_lock<std::mutex> lk(mtx_);  
        i = val;
        i = i + 2;
        std::cout<<i<<"["<<val<<"]"<<std::endl;
}

int func2()
{
	std::unique_lock<std::mutex> lk(mtx_);
        std::cout<<i<<"*"<<std::endl;
}

int main()
{
        i = 9;
        std::thread t1(func, 1);
        std::thread t2(func, 2);
        std::thread t3(func, 3);
        std::thread t4(func2);

        t1.join();
        t2.join();
        t3.join();
        t4.join();

        std::cout<<i<<std::endl;
        return 0;
}

