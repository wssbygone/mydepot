#include <iostream>
using namespace std;

template<int...> struct IndexSeq{};
 

template<int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};
 

template<int... Indexes>
struct MakeIndexes<0, Indexes...>
{
    typedef IndexSeq<Indexes...> type;
};
 
int main()
{
    using T = MakeIndexes<3>::type;
    cout <<typeid(T).name() << endl;
    return 0;
}
