#include <iostream>
#include <set>
using namespace std;
struct song
{
  int id;
  int hot;
  song(int id, int hot)
   : id{id}
   , hot{hot}
   {}
  bool operator<(const song& right) const;
};

 bool song::operator<(const song& right) const
 {
   if (id == right.id)     //根据id去重
      return false;
   else
   {
     if (hot != right.hot)
     {
        return hot > right.hot;      //降序
     }
     else
     {
        return id > right.id;
     }
   }
 }

int main()
{
  std::set<song> mySet;
  song s1(20, 100);
  song s2(20, 200);
  song s3(10, 300);
  song s4(30, 400);
 
  mySet.insert(s1);    //插入s1
  mySet.insert(s2);    //插入s2
  mySet.insert(s3);    //s3和s2的id相同，不插入
  mySet.insert(s4);    //插入s4
 
  for (auto it : mySet)
  {
    std::cout << "id:" << it.id << ",hot:" << it.hot << std::endl;
  }
 	
  return 0;
}
