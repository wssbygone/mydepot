#include<bits/stdc++.h>

class ItCat {
public:
    ItCat()=default;
    ItCat(int, float) {}
};

int main()
{
    std::variant<ItCat, int, float, double> tmp = 1.34;
    std::cout << tmp.index() << '\n';
}

