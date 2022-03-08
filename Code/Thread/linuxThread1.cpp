//----------------------------------------
//--------    Author: AA
//--------    DateTime: 2022-02-28
//--------    Description: Thread Function
//----------------------------------------

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;


void* working(void* arg)
{
	cout << "this pthreadID is " << pthread_self() << endl;

	for (int i = 0; i < 9; ++i)
	{
		/* code */
		cout << "child pthread:i:" << i << endl;
	}

	return NULL;
}



int main()
{
	pthread_t tid;
	//tid：会将线程ID写入到指针指向的内存中；  线程属性，默认NULL；函数指针；传给函数的参数
	pthread_create(&tid, NULL, working, NULL);

	cout << "child pthread created, id:" << tid << endl;

	cout << "parent pthread created, id:" << pthread_self() << endl;

	for(int i = 0; i < 3; i++)
	{
		cout << "i:" << i << endl;
	}

	sleep(1);
	
	return 0;
}

