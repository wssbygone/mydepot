#include <map>
#include <string>
#include <iostream>
#include <typeinfo>
 
using namespace std;
 
void deleteOperator()
{
    //1.clear清除内容
    map<int, string> map1;
    map1[1] = "hello1";
    map1[2] = "hello2";
    map1[3] = "hello3";
    cout << "1 size = " << map1.size() << " empty = " << map1.empty() << endl;
    map1.clear();
    cout << "2 size = " << map1.size() << " empty = " << map1.empty() << endl;
    //2.erase擦除元素
    map1.insert({11, "hello11"});
    map1.emplace(12, "hello12");
    map1.insert({13, "hello13"});
    map1.insert({14, "hello14"});
    auto mapIter = map1.begin();
    while(mapIter != map1.end())
    {
        cout << mapIter->first << ": " << mapIter->second << endl;
        ++mapIter;
    }
    map1.erase(13);//参数key
    cout << endl;
    auto mapIter2 = map1.begin();
    while(mapIter2 != map1.end())
    {
        cout << mapIter2->first << ": " << mapIter2->second << endl;
        ++mapIter2;
    }
    cout << endl;
    //3.swap交换内容
    map<int, string> map2;
    map2[21] = "camel21";
    map2[22] = "camel22";
    map2[23] = "camel23";
    auto map2Iter = map2.begin();
    while(map2Iter != map2.end())
    {
        cout << map2Iter->first << ": " << map2Iter->second << endl;
        ++map2Iter;
    }
    map2.swap(map1);
    cout << "map1: " << endl;
    for(auto map1iter = map1.begin(); map1iter != map1.end(); ++map1iter)
    {
        cout << map1iter->first << ": " << map1iter->second << endl;
    }
    cout << endl;
    cout << "map2: " << endl;
    for(auto map2iter = map2.begin(); map2iter != map2.end(); ++map2iter)
    {
        cout << map2iter->first << ": " << map2iter->second << endl;
    }
    cout << endl;
    //4.extract从另一容器释出结点   C++17 提取
    cout << "map3: ===========" << endl;
    map<int, string> map3{{1,"apple"}, {5,"pear"}, {3,"peach"}, {4,"grape"}};
    auto nh = map3.extract(5);//参数key
	
	cout<<"typeid(nh).nampe:"<<typeid(nh).name()<<endl;
	
    nh.key() = 2;
    map3.insert(move(nh));
    for(auto map3iter = map3.begin(); map3iter != map3.end(); ++map3iter)
    {
        cout << map3iter->first << ": " << map3iter->second << endl;
    }
    cout << "map3.size = " << map3.size() << endl;
    //5.merge从另一容器接合结点   C++17
    map<int, string> map4{{2, "durian"}, {5, "mango"}, {10, "guava"}};;
    map<int, string> map5{{1, "strawberry"}, {4, "melon"}, {5, "banana"}, {8, "orange"}};
    map5.merge(map4);//如果有相同的关键字不会合并，例如5
    cout << "map4: " << endl;
    for(auto const &value: map4)
    {
        cout << value.first << ": " << value.second << endl;
    }
    cout << endl;
    cout << "map5: " << endl;
    for(auto const &value: map5)
    {
        cout << value.first << ": " << value.second << endl;
    }
    cout << endl;
}
 
int main()
{
    deleteOperator();
    cout << "Hello, world!" << endl;
    return 0;
}
