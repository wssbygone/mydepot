/* 
题目描述
如果统计的个数相同，则按照ASII码由小到大排序输出 。如果有其他字符，则对这些字符不用进行统计。

实现以下接口： 
输入一个字符串，对字符中的各个英文字符，数字，空格进行统计（可反复调用） 
按照统计个数由多到少输出统计结果，如果统计的个数相同，则按照ASII码由小到大排序输出 
清空目前的统计结果，重新统计

调用者会保证： 
输入的字符串以‘\0’结尾。

输入描述:
输入一串字符。

输出描述:
对字符中的各个英文字符（大小写分开统计），数字，空格进行统计，并按照统计个数由多到少输出,如果统计的个数相同，则按照ASII码由小到大排序输出。如果有其他字符，则对这些字符不用进行统计。

输入例子:
aadddccddc
1
输出例子:
dca
*/
 
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<char,int> a, pair<char,int> b)  // 重载sort函数的自定义比较函数comp
{
    if(a.second > b.second)
        return true;
    else if(a.second == b.second && a.first < b.first)
        return true;
    else return false;
}

int main()
{
    string str;
    unordered_map<char, int> countMap;

    while(getline(cin,str))
    {
    for(int i=0; i <= str.length()-1; i++)
        {
             if(countMap.find(str[i]) == countMap.end())
            {
                countMap[str[i]] = 1;
            }
            else
            {
                countMap[str[i]]++;
            }        
        }

    vector<pair<char, int>> elems(countMap.begin(), countMap.end());
    sort(elems.begin(), elems.end(), comp);  // 使用sort对hash表进行排序

    for(vector<pair<char, int>>::iterator it=elems.begin(); it != elems.end(); it++)
    {
        cout<<it->first;
    }
    cout<<endl;
    countMap.clear();
    }
    return 0;
}
