#include<iostream>
#include<pthread.h>
using namespace std;

class MultiThreadSingleton
{
public:
    ~MultiThreadSingleton()
    {
        cout << "~MultiThreadSingleton()" << endl;
    }   
    static MultiThreadSingleton* getInstance()
    {
        // if(instance == nullptr)
        // {
        //     //初次创建时加锁
        //     pthread_mutex_lock(&mutex);

        //     instance = new MultiThreadSingleton();

        //     pthread_mutex_unlock(&mutex);
        // }
        // return instance;


        //局部变量
        static MultiThreadSingleton localInstance;

        return &localInstance;
    }

    void SingletonOP()
    {
        cout << "SingletonOP!" << endl;
    }

private:
    MultiThreadSingleton()
    {
        // pthread_mutex_init(&mutex,NULL);
        cout << "MultiThreadSingleton()" << endl;
    }
    // static pthread_mutex_t mutex;
    // static MultiThreadSingleton* instance;


};
// //饿汉模式  即初始化时就实例化对象，适合访问量较大的时候，用空间换时间
// MultiThreadSingleton*  MultiThreadSingleton::instance = new MultiThreadSingleton();

//懒汉模式  即需要的时候才去实例化对象
// MultiThreadSingleton*  MultiThreadSingleton::instance = nullptr;
// //加锁
// pthread_mutex_t MultiThreadSingleton::mutex;


int main()
{
    //--------饿汉
    // MultiThreadSingleton* sig1 = MultiThreadSingleton::getInstance();
    // MultiThreadSingleton* sig2 = MultiThreadSingleton::getInstance();
    // // sig1->SingletonOP();
    // // sig2->SingletonOP();
    // cout << sig1 << endl;
    // cout << sig2 << endl;
    // delete sig2;

    //-------懒汉
    // MultiThreadSingleton* sig3 = MultiThreadSingleton::getInstance();
    // sig3->SingletonOP();
    // delete sig3;

    //懒汉局部变量
    MultiThreadSingleton* sig4 = MultiThreadSingleton::getInstance();
    MultiThreadSingleton* sig5 = MultiThreadSingleton::getInstance();
    sig4->SingletonOP();
    if(sig4 == sig5) cout << "Test!" << endl;



    return 0;
}