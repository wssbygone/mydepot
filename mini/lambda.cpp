#include<iostream>

int main()
{
   int e(0), f(0), g(0);
   [E = e, F = f, G = g] {std::cout << E << ' ' << F << ' ' << G << std::endl; }();
   [&E = e, &F = f, &G = g] {E = 1, F = 2, G = 3; std::cout << E << ' ' << F << ' ' << G << std::endl; }();
   std::cout << e << ' ' << f << ' ' << g << std::endl;
	
   //另外，不省略()然后->指定类型啥的其实都行，如果是引用捕获的时候()mutable的话也合法，虽然没啥区别，先这样，语法糖而已
   return 0;
}
