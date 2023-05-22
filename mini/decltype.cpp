#include<vector>
#include<iostream>
template <typename T,typename I>
auto show(T&& a, I i) -> decltype(a[i]) {
   std::cout << "cool" << std::endl;
   return std::forward<T>(a[i]);
}
int main() {
   std::vector<int> s = { 1,2,3,4 };
   decltype(show("123", 1)) a = 2;  //不会执行std::cout,因为并不会执行,在编译阶段确定了类型而已
   //decltype(s[1]) a;      //进行索引返回的是引用，引用类型必须初始化，所以报错   
   return 0;
}

