#include<iostream>

int main()
{
   int e(0), f(0), g(0);
   [E = e, F = f, G = g] {std::cout << E << ' ' << F << ' ' << G << std::endl; }();
   [&E = e, &F = f, &G = g] {E = 1, F = 2, G = 3; std::cout << E << ' ' << F << ' ' << G << std::endl; }();
   std::cout << e << ' ' << f << ' ' << g << std::endl;
	
   //���⣬��ʡ��()Ȼ��->ָ������ɶ����ʵ���У���������ò����ʱ��()mutable�Ļ�Ҳ�Ϸ�����Ȼûɶ�������������﷨�Ƕ���
   return 0;
}
