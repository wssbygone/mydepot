// 仿函数的使用 functor

#include <bits/stdc++.h>
 
using namespace std;
 
map<int,int> MMP;
 
struct CmpByValue {  
  bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)const {  
    return lhs.second < rhs.second;  
  }  
};
 
int main(){
	
	MMP.insert(make_pair(1,4));
	MMP.insert(make_pair(2,3));
	MMP.insert(make_pair(3,2));
	MMP.insert(make_pair(4,1));
	
	vector< pair<int,int> > V(MMP.begin(),MMP.end());
	
	sort(V.begin(),V.end(),CmpByValue());
	
	for(int i=0 ; i<V.size() ; ++i){
		printf("%d\n",V[i].second);
	}
	
	return 0;
}