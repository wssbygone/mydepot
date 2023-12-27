#include <iostream>
#include <variant>
#include <string>
#include <utility>

using namespace std;

using Elem = std::variant<std::monostate, int32_t, int64_t,float, double, std::string, std::pair<int64_t, int64_t>>;

int main() {
    Elem e1 = 42;
    Elem e2 = "Hello, world!";
    Elem e3 = 3.14f;
    Elem e31 = 3.14;
    Elem e4 = std::make_pair(10, 20);

    if (std::holds_alternative<int32_t>(e1)) {
        int32_t value = std::get<int32_t>(e1);
        cout << "e1 is an int32_t: " << value << endl;
    }

    if (std::holds_alternative<std::string>(e2)) {
        std::string value = std::get<std::string>(e2);
        cout << "e2 is a string: " << value << endl;
    }

    if (std::holds_alternative<float>(e3)) {
        float value = std::get<float>(e3);
        cout << "e3 is a float: " << value << endl;
    }

    if (std::holds_alternative<double>(e3)) {
        double value = std::get<double>(e3);
        cout << "e3 is a double: " << value << endl;
    }

    if (std::holds_alternative<std::pair<int64_t, int64_t>>(e4)) {
        std::pair<int64_t, int64_t> value = std::get<std::pair<int64_t, int64_t>>(e4);
        cout << "e4 is a pair: (" << value.first << ", " << value.second << ")" << endl;
    }

    return 0;
}

