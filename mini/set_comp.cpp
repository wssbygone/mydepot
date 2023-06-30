// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <set>     

bool myfunction(int i,int j){ return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

auto bigger = [](const int &left, const int &right) {
  return left > right;
};


int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> my_vector (myints, myints+8);           
  // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (my_vector.begin(), my_vector.begin()+4);   
  //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (my_vector.begin()+4, my_vector.end(), myfunction); 
  // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (my_vector.begin(), my_vector.end(), myclass());     
  //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "my_vector contains:";
  for (std::vector<int>::iterator it=my_vector.begin(); it!=my_vector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<<"====================="<<std::endl;
  
  std::set<int, decltype(bigger)> my_set(bigger);
 // std::multiset<int, std::less<int>> my_set;
  my_set.insert(20);
  my_set.insert(10);
  my_set.insert(30);
  my_set.insert(8);
  my_set.insert(20);
  
  for (auto &item : my_set)
    std::cout<< item <<" ";
  std::cout<<std::endl;

  return 0;
}
