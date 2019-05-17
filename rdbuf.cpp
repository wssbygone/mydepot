#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ofstream out("out.txt");
	ifstream in("in.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	string s;
	cin>>s;
	cout<<s<<endl;
	return 0;
} 