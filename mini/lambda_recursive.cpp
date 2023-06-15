#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x;
    auto func = [](auto & self,int x)->int {
        if (x == 1||x==0) 
            return 1;
        else
            return x*self(self, x - 1);
    };

    while(cout<<"input a number [1,15):"<<endl,cin >> x,(x<=15) && cin.good())
        cout << func(func, x) << endl;
    return 0;
}
