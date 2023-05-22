#include<memory>
#include<iostream>
using namespace std;
class Egg;
class Chicken {
 public:
  std::weak_ptr<Egg> p_egg_;
  ~Chicken() { std::cout << "destructor Chicken func"; }
};
class Egg {
 public:
  std::shared_ptr<Chicken> p_Chicken_;
  ~Egg() { std::cout << "destructor egg func"; }
};

int main(int argc, char* argv[]) {
  shared_ptr<Chicken> _Chicken(new Chicken());
  shared_ptr<Egg> _egg(new Egg());

  if (_Chicken && _egg) {
    _Chicken->p_egg_ = _egg;
    _egg->p_Chicken_ = _Chicken;
  }
  
  std::cout << "_checken use count:" << _Chicken.use_count()<< std::endl;
  std::cout << "_egg use count:" << _egg.use_count() << std::endl;   
  
  _egg->p_Chicken_.reset();

  std::cout << "====================" <<std::endl;
  std::cout << "_checken use count:" << _Chicken.use_count()<< std::endl;
  std::cout << "_egg use count:" << _egg.use_count() << std::endl;
}
