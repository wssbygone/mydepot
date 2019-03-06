#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
   int xx{9};
   vector<int> v {189,22,38};
   v.reserve(4);
   v.push_back(1);
   v.push_back(34);
   v.push_back(33);
   for_each(v.begin(), v.end(),
   [](int i) { cout << i << endl; } );
   return 0;
}

