//----------------------------------------------------------------------
//--------    Author: AA                                                
//--------    DateTime: 2022-02-23
//--------    Description: Thread3.cpp                               
//----------------------------------------------------------------------

#include <iostream>
#include <thread>
using namespace std;

void func(int num, string str)
{
    for(int i = 0; i != 10; i++)
    {
        cout << "num:" << num + i << "," << str << endl;
    }
}

void func1()
{
    for(int i = 10; i != 20; i++)
    {
        cout << "num:" << i << endl;
    }
}

int main()
{
    cout << "主线程ID：" << this_thread::get_id() << endl;

    thread t1(func, 100, "helloworld!");
    thread t2(func1);
    //加入式  回收线程所使用资源
    //阻塞线程 函数在哪个线程中被执行，那么函数就阻塞哪个线程  
    //如果需要阻塞主线程  就在主线程中通过子线程对象调用join方法
    t1.join();
    t2.join();
   
   return 0;
}
