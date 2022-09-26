#include <iostream>
#include <tuple>
//#include <utility>
 
int main(int argc, char **argv) {
    std::tuple<std::string, int, std::string, int> tp;
    tp = std::make_tuple("Sven", 25, "Shanghai", 21);
 
    // 定义接收变量
    std::string name;
    std::string addr;
    int ages;
    int areaCode;
 
    std::tie(name, ages, addr, areaCode) = tp;
    std::cout << "Output: " << '\n';
    std::cout << "name: " << name <<", ";
    std::cout << "addr: " << addr << ", ";
    std::cout << "ages: " << ages << ", ";
    std::cout << "areaCode: " << areaCode << '\n';
 
    return 0;
}
