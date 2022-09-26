#include<iostream>
#include<map>
using namespace std;

int main()
{
  map<int, string> c = {{1,"a"}};

  if(auto res = c.insert(make_pair(2, "b")); !res.second ) {
     cout << "key 1 exist" << endl;
  } else {
      cout << "insert success, value:" << res.first->second << endl;
  }
}
