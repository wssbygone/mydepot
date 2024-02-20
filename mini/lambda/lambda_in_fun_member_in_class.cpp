
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <typeinfo>
#include <functional>

class MyCounter {
public:
    MyCounter() : count_(1) {}

    void increment(int value) {
        auto incrementFunc = [this, value]() {
            count_ += value; // 访问类的成员变量
	    displayCount();
        };

        incrementFunc(); // 调用lambda表达式

        // 输出增加后的值
        std::cout << "Count after increment: " << count_ << std::endl;
    }

private:
    void displayCount() {
        std::cout << "Current count: " << count_ << std::endl;
    }
    int count_;
};

int main() {
    MyCounter counter;
    counter.increment(5);

    return 0;
}

