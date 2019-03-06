#include<iostream>
using namespace std;

template<typename T,int N>
void PrintValues( T (&ia)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << ia[i] << endl;
    }
}

template<typename T,int N>
void changeValues(T (&arr)[N])
{
   for(auto i=0;i<N;i++)
   {
      arr[i]=5;
   }
}

int main()
{
    int j[5] = { 0, 2,3 };
    PrintValues(j);
    cout<<"========"<<endl;
    changeValues(j);
    PrintValues(j);
    return 0;
}
