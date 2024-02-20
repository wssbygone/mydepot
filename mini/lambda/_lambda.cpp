#include<iostream>

int main()
{
  int e(0), f(0), g(0);
  //auto a=[E = e, F = f, G = g] {std::cout << E << ' ' << F << ' ' << G << std::endl; };
  //a();
  //以上2行等效于一下一行:
  [E = e, F = f, G = g] {std::cout << E << ' ' << F << ' ' << G << std::endl; } (); //这里末尾的()等效于调用
  auto b=[&E = e, &F = f, &G = g] {E = 1, F = 2, G = 3; std::cout << E << ' ' << F << ' ' << G << std::endl;};
  b();
  std::cout << e << ' ' << f << ' ' << g << std::endl;
	
  return 0;
}
