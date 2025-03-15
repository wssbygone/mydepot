#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>  // 添加必需头文件

class Foo {
private:
    std::condition_variable cv;
    std::mutex mtx;
    int k = 0;

public:
    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);  // 加锁保证修改 k 的原子性
        printFirst();
        k = 1;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return k >= 1; });  // 防止虚假唤醒
        printSecond();
        k = 2;
        cv.notify_one();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return k >= 2; });
        printThird();
    }
};

int main() {
    Foo foo;

    // 使用 lambda 直接绑定输出逻辑（避免冗余函数）
    std::thread t1([&foo] { 
        foo.first([] { std::cout << "first\n"; });
    });
    std::thread t2([&foo] { 
        foo.second([] { std::cout << "second\n"; });
    });
    std::thread t3([&foo] { 
        foo.third([] { std::cout << "third\n"; });
    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

