#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    // define cmp function
    //注意匿名函数的类型只能是auto.
    auto cmp = [](const int x, const int y) { return x > y;};
    vector<int> nums2 = {40, 50, 10, 30, 20};
 
    // generate heap in the range of numsector
    make_heap(nums2.begin(), nums2.end(), cmp);
    //或者使用
    //make_heap(nums2.begin(), nums2.end(), greater<int>());
    cout << "initial max value : " << nums2.front() << endl;
 
    // pop max value
    pop_heap(nums2.begin(), nums2.end(), cmp);
    nums2.pop_back();
    cout << "after pop, the max vsalue : " << nums2.front() << endl;
 
    // push a new value
    nums2.push_back(0);
    push_heap(nums2.begin(), nums2.end(), cmp);
    cout << "after push, the max value : " << nums2.front() << endl;
 
    //initial max value : 10
    //after pop, the max vsalue : 20
    //after push, the max value : 0
 
    return 0;
}
