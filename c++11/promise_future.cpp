#include<iostream>
#include<utility>
#include<future>
#include<vector>
#include<thread>
 
int func(int x){
    return x*x;
}
 
int main()
{
    std::packaged_task<int(int)> tsk(func);
    std::future<int> fut = tsk.get_future();
 
    std::thread(std::move(tsk), 2).detach();
     
    int value = fut.get();
    std::cout << "The result is " << value << ".\n";
 
    //std::future不可复制，无法放到容器中，需要用shared_future
    std::vector<std::shared_future<int>> v;
    std::shared_future<int> f = std::async(std::launch::async, [](int a, int b){ return a + b; }, 2, 3);
    v.push_back(f);
 
    std::cout << "The shared future result is " << v[0].get() << "\n";
    return 0;
}
