#include<algorithm>
#include<vector>
#include<iostream>
#include<string.h>
#include<unistd.h>
using namespace std;

bool judge(const pair<double,char> a, const pair<double ,char> b) {
    return a.first<b.first;
}
int main()
{
    vector<pair<double ,char>> p;
    p.push_back(make_pair(10.1,'a'));
    p.push_back(make_pair(9.2,'c'));
    p.push_back(make_pair(10.01,'t'));
    p.push_back(make_pair(17.0,'y'));
    p.push_back(make_pair(10.1,'b'));
    sort(p.begin(),p.end(),judge);
    for(auto i=0;i<p.size();i++)
        cout<<p[i].first<<"    "<<p[i].second<<endl;
    //getchar();
    //sleep(5);
}
