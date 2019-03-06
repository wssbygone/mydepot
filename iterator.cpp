#include<iostream>
#include<set>
 
using namespace std;
int main()
{
	typedef set<int,less<int> > IntSet;
	IntSet coll;
	coll.insert(1);
	coll.insert(0);
	coll.insert(-1);
	coll.insert(4);
	coll.insert(7);
 
 
	IntSet::iterator pos;
	for(pos=coll.begin() ; pos != coll.end() ; ++pos)
	{
		cout << *pos << " ";
	}
	cout << endl;
 
	pair<IntSet::iterator,bool> status=coll.insert(4);
 
	if(status.second){
		cout<< "4 inserted as elem"
			<< distance(coll.begin(),status.first)+1
			<< endl;
	}
	else
	{
		cout << "4 aready exists" << endl;
	}
	coll.erase(coll.find(4));
 
	for(pos=coll.begin() ; pos != coll.end() ; ++pos)
	{
		cout << *pos << " ";
	}
	return 0;
}