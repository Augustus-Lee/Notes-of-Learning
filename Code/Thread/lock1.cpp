//----------------------------------------
//--------    Author: AA
//--------    DateTime: 2022-02-28
//--------    Description: mutex_lock
//----------------------------------------

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

const int MAX = 50;

//global var
int num = 0;
pthread_mutex_t mt;

void* funcA(void* arg)
{
	for(int i = 0; i < MAX; i++)
	{
		pthread_mutex_lock(&mt);
		int cur = num;
		cur++;
		usleep(10);
		num = cur;
		cout <<"Thread A, id:" << pthread_self() << ",num:" << num << endl;
		pthread_mutex_unlock(&mt);
		// cout <<"Thread A, id:" << pthread_self() << ",num:" << num << endl;
	}

	return NULL;
}

void* funcB(void* arg)
{
	for(int i = 0; i < MAX; i++)
	{		
		pthread_mutex_lock(&mt);
		int cur = num;
		cur++;
		num = cur;
		pthread_mutex_unlock(&mt);
		cout <<"Thread B, id:" << pthread_self() << ",num:" << num << endl;
		usleep(5);
	}

	return NULL;
}


int main()
{
	pthread_t p1, p2;

	//初始化互斥锁
	pthread_mutex_init(&mt, NULL);

	//创建两个子线程
	pthread_create(&p1, NULL, funcA, NULL);
	pthread_create(&p2, NULL, funcB, NULL);

	//阻塞 资源回收
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	pthread_mutex_destroy(&mt);


	
	return 0;
}