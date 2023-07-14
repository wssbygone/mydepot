#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  std::vector<std::ofstream> files;
  files.push_back(std::ofstream("f1.txt"));
  std::ofstream file("f2.txt");
  files.push_back(std::move(file));
   
  files[0]<<"12345"<<std::endl;
  files[1]<<"23456"<<std::endl;

  return 0;
} 
