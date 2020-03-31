#include <iostream>  
#include <cctype>  
#include <string>  
#include <algorithm>  
using namespace std;  
int main()  
{  
    string s = "DDddkfjslYYYUU";  
    transform(s.begin(), s.end(), s.begin(),(int (*)(int))tolower);  
    cout<<s<<endl;  
    return 0;  
} 
