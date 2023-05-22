#include<memory>
#include<iostream>
using namespace std;
class X {
 public:
  ~X() { std::cout << "destructor X func"<<std::endl; }
};

template <class T> 
void printType(const T&)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

int main()
{
    // custom deleter using a state-full lambda
    double data[100]{0};
    auto lmb_sf = [&data](X* ptr){
        // do something
        std::cout<<"In custom deleter using a state-full lambda\n";
        delete ptr;
    };
    
    std::unique_ptr<X,decltype(lmb_sf)> ptr_sf(new X, lmb_sf);
    printType(ptr_sf); 
//    std::cout<<"decltype(ptr_sf): "<< decltype(ptr_sf) <<"\n";
    
    std::cout<<"Size of ptr_sf = "<<sizeof(decltype(ptr_sf))<<"\n";

    return 0;
}
