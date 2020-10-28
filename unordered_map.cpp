#include <unordered_map>
#include <iostream>
using namespace std;

typedef unordered_map<string, double>::iterator MyIte;
void test_unordered_map( )
{ 
	unordered_map<string, double> umap;
	umap.insert(make_pair("苹果", 2.5));
	umap.insert(make_pair("香蕉", 3.0));
	umap.insert(make_pair("香蕉", 3.0));
	umap.insert(make_pair("西瓜", 1.5));
	umap.insert(make_pair("哈密瓜", 3.0));
	umap["榴莲"] = 4.0;
	umap["羊角蜜"] = 5.5; 
	umap["菠萝蜜"] = 10.5; 
	umap["荔枝"] = 8.5; 
	umap["龙眼"] = 8.5; 

	umap["番茄"] = 8.5;   
	umap["黄瓜"] = 8.5; 
	umap["土豆"] = 8.5; 
	auto n = umap.bucket_count();

	for (unsigned i=0; i<n; ++i) 
	{
		std::cout << "bucket #" << i << " contains: ";
		for (auto it = umap.begin(i); it!=umap.end(i); ++it)
		  std::cout << "[" << it->first << ":" << it->second << "] ";
		std::cout << "\n";
	}
  
	// while( it != umap.end( ))
	// { 
	 // cout<<it->first<<" :"<<it->second<<endl;
	 // ++it;
	// }   
	cout<<"桶数量："<<umap.bucket_count( )<<endl;
	cout<<"负载因子："<<umap.load_factor( )<<endl;
	cout<<"最大平均元素的因子："<<umap.max_load_factor( )<<endl;
  
//结果：
/*
土豆 :8.5
黄瓜 :8.5
苹果 :2.5
香蕉 :3
西瓜 :1.5
哈密瓜 :3
番茄 :8.5
榴莲 :4
荔枝 :8.5
羊角蜜 :5.5
龙眼 :8.5
菠萝蜜 :10.5
桶数量：23
负载因子：0.521739
最大平均元素的因子：1 
*/
}


struct Store
 {
     string name;
     string addr;
     Store(const string& na="", const string& ad= "")
         :name(na),addr( ad){ }
 
     bool operator==(const Store& s) const     //重载==支持等于比较
     {   
         return name == s.name && addr == s.addr; 
     }
 };
 struct hash_key    //定制返回哈希值的仿函数
 {
     //BKDRHash
     size_t operator()(const Store& s) const
     {
         size_t seed = 131; /* 31 131 1313 13131 131313 etc.. */
         size_t hash = 0;
         size_t i = 0;
         for( i = 0; i < s.name.size(); ++i)
         {
             hash = ( hash * seed)  + s.name[i];
         }
         return hash;
     }
 };
 
 typedef unordered_map<Store, int, hash_key>::iterator MyIte1;
 void test_unordered_map1( )
 {
     unordered_map<Store, int, hash_key> umap;
     Store s1("火锅店", "重庆");
     Store s2("凉皮店", "西安");
     Store s3("烤鸭店", "北京");
 
     umap.insert(make_pair(s1, 1));
     umap.insert(make_pair(s2, 1));
     umap[s3] = 1;
 
     MyIte1 it = umap.begin( );
     while( it != umap.end( ))
     {
         cout<<it->first.name<<"："<<it->second<<endl;
         ++it;
     }
 }
 
int main()
{
	test_unordered_map();
	return 0;
}