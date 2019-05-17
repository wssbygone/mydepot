#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,temp,d=1,carry;//temp为阶乘元素与临时结果的乘积，carry是进位 ，d是位数 
	int a[3000];//确保数组足够大 
	scanf("%d",&n);//n的阶乘 
	a[0]=1;//先初始化为1，方便后面运算 
	for(i=2;i<=n;i++)//从2开始阶乘 ,每次循环计算i阶乘的结果 
	{
		for(j=1,carry=0;j<=d;j++)// 每次循环初始化进位的值 
		{
			temp=a[j-1]*i+carry;//相应阶乘中的一项与当前所得临时结果的某位相乘加上进位 
			a[j-1]=temp%10;//更新临时结果的位上信息 
			carry=temp/10;//如果有进位就进入下面的循环 
		}
		while(carry)     //如果有进位 
		{   ++d;        //增加进位，位数加一
	                a[d-1]=carry%10;   //给新的进位赋值 
			carry=carry/10;    //看还可不可以再进位 
		}
	}
	printf("n!=");
	for(j=d-1;j>=0;j--)       //从高位向低位依次输出 
	printf("%d",a[j]);
	printf("\n");
 } 
