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
    //detach 分离式
    t1.detach();
    t2.detach();

   //主线程休眠一秒  等待子线程完成
   this_thread::sleep_for(chrono::seconds(1));
   return 0;
}
