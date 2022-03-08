//----------------------------------------------------------------------
//--------    Author: AA                                                
//--------    DateTime: 2022-02-23
//--------    Description: Thread3.cpp                               
//----------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void download1()
{
    //让线程休眠500ms
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "子线程1 ID：" << this_thread::get_id() << ", start." << endl;

}

void download2()
{
    //让线程休眠300ms
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "子线程2 ID：" << this_thread::get_id() << ", start." << endl;
}

void doSome()
{
    cout << "子线程已完成！"   << endl;
    cout << "主线程逻辑开始！" << endl;
}

int main()
{
    thread t1(download1);
    thread t2(download2);
    t1.join();
    t2.join();

    doSome();
   
   return 0;
}
