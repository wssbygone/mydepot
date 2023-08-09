#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main()
{
    // 创建一个空的json对象
    json j;

    j["num"] = 999999;

    // 创建数组data，并加入元素0, true, null
    json data = json::array();
    data.push_back(0);
    data.push_back(true);
    data.push_back(nullptr);

    // 创建数组nestedArray，并加入元素1, object, string2, nestedArray2, string6
    json nestedArray = { 1 };
    json object;
    object["msg"] = "Hello World";
    object["time"] = "2021-10-01";
    nestedArray.push_back(object);
    nestedArray.push_back("2");
    json nestedArray2 = { 3, 4, 5 };
    nestedArray.push_back(nestedArray2);
    nestedArray.push_back("6");

    // 把嵌套后的数组放到data中
    data.push_back(nestedArray);

    // 创建包含键值对的对象
    json obj = {
        {"qwer", {"ewasd", 7, {{"nums", {8, true, {}}}}}},
        {"json", "YarBor is awesome!"}
    };

    // 把对象放到data中
    data.push_back(obj);

    // 把data数组放到根级别的对象中
    j["data"] = data;

    // 将JSON打印出来
    std::cout << j.dump(2) << std::endl;

    return 0;
}

