#include <thread>
#include <chrono>
#include <iostream>
#include <atomic>

using namespace std::chrono_literals;

std::atomic<int> counter1{};

struct Global {
    ~Global() {
        std::cout << "~global: counter1 = " << counter1 << std::endl;
    }
};
Global global;

int main(int argc, char** argv) {
    std::thread dt1{[]() {
            while (true) {
                ++counter1;
                std::this_thread::sleep_for(500ns);
                std::cout<<counter1<<std::endl;
            }
        }};
    dt1.detach();

    std::this_thread::sleep_for(2s);
    std::cout << "counter1 = " << counter1 << std::endl;
}
