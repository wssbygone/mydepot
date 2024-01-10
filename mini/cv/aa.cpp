//https://zhuanlan.zhihu.com/p/448027598
// thread safe queue
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

template <class T>
class MTQueue{
    std::condition_variable m_cv;
    std::mutex m_mtx;
    std::vector<T> m_arr;
public:
    T pop(){
        std::unique_lock lck(m_mtx);//为互斥量申请加锁
        m_cv.wait(lck, [this]{return !m_arr.empty();});
        //wait()第二个参数-lambda表达式为true时，wait()直接返回，该线程继续持有锁，程序继续往下运行。
        //wait()第二个参数-lambda表达式为false时，wait()将释放锁，并阻塞到本行，线程进入等待阻塞状态。
        //wait()只有锁这一个参数时，和wait()的第二个参数-lambda表达式为false时一样，释放锁并等待阻塞。
        //等待阻塞线程需要notify()方法唤醒，wait()为true时，该线程会再次获得锁。
        T ret = std::move(m_arr.back());
        m_arr.pop_back();
        return ret;
    }
    auto pop_hold(){
        std::unique_lock lck(m_mtx);
        m_cv.wait(lck, [this]{return !m_arr.empty();});
        T ret = std::move(m_arr.back());
        m_arr.pop_back();
        return std::pair(std::move(ret), std::move(lck)); 
    }
    void push(T val){
        std::unique_lock lck(m_mtx);
        m_arr.push_back(std::move(val));
        m_cv.notify_one();
    }//执行结束，离开unique_lock作用域，锁自动释放

    void push_many(std::initializer_list<T> vals){
        std::unique_lock lck(m_mtx);
        std::copy(
            std::move_iterator(vals.begin()),
            std::move_iterator(vals.end()),
            std::back_insert_iterator(m_arr)
        );
        m_cv.notify_all();
    }
};

int main(){
    MTQueue<int> foods;

    std::thread t1([&]{
        for(int i=0 ;i<2; ++i){
            auto food = foods.pop();
            std::cout<<"t1 got food: "<<food<<std::endl;
        }
    });//线程创建时就会立即执行

    std::thread t2([&]{
        for(int i=0 ;i<2; ++i){
            auto food = foods.pop();
            std::cout<<"t2 got food: "<<food<<std::endl;
        }
    });

    foods.push(42);
    foods.push(233);

    foods.push_many({666, 6767});

    t1.join();//join()保证主线程在子线程结束之后继续运行后面的代码
    t2.join();//detach()分离，保证主线程和子线程可以各自运行（要保证子线程资源释放在主线程之前）

    return 0;
}
