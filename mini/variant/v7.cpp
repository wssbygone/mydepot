#include <iostream>
#include <string>
#include<typeinfo>
#include <variant>
#include <map>

using namespace std;

class Item {
public:

  template<typename S, typename T>
  Item &set(S key, T value) {
    printf("xxx---------->%s(), line = %d, key = %s, vlaue = %d\n",__FUNCTION__,__LINE__,key,value);
    //findOrAllocateProp函数返回Prop对象然后,然后调用员函数set(),最终key值设置到mName, value设置到mElem中.
    findOrAllocateProp(key).set(value);

    //Or
    // Prop m_prop = findOrAllocateProp(key);
    // printf("xxx---------->%s(), line = %d, key = %s, value = %d\n",__FUNCTION__,__LINE__,m_prop.mName.c_str(),std::get<int32_t>(m_prop.mElem));
    return *this;
  }

  Item &setInt32(const char *key, int32_t value) {
    printf("xxx---------->%s(), line = %d, key = %s, vlaue = %d\n",__FUNCTION__,__LINE__,key,value);
    return set(key, value);
  }

  //key: mName; value:mElem.
  class Prop {
  public:
    using Elem = std::variant<std::monostate, int32_t, int64_t, double, std::string, std::pair<int64_t, int64_t>>;

    //1.设置key值给mName
    void setName(const char *name) {
      printf("xxx---------->%s(), line = %d, name = %s\n",__FUNCTION__,__LINE__,name);
      mName = name;
    }

    //2.将valuec传给mElem.
    template <typename T> void set(const T& value) {
      mElem = value;
      //获取mElem中的value值.
      int32_t val = std::get<int32_t>(mElem);
      printf("xxx---------->%s(), line = %d,val = %d\n",__FUNCTION__,__LINE__,val);
    }

  public:
    std::string mName;//key
    Elem mElem;//value
  };

  //findOrAllocateProp函数返回Prop对象然后,然后调用员函数set()
  Prop &findOrAllocateProp(const char *key) {
    auto it = mProps.find(key);//开始key对应的value为空.

    if (it != mProps.end()){//不走此分支.
      return it->second;
    }

    Prop &prop = mProps[key];
    prop.setName(key);    
    return prop;
  }

  std::map<std::string, Prop> mProps;
};

int main(){
  Item it;
  it.setInt32("Tom", 18);
}


