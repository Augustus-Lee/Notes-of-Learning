//----------------------------------------
//--------    Author: AA
//--------    DateTime: 2022-03-02
//--------    Description: condition variable
//----------------------------------------
#include <iostream>
#include <string>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;



//链表的节点
class Node
{
public:
	int number;
	Node* next;

};

pthread_mutex_t mt; //互斥锁
pthread_cond_t cond; //条件变量

Node* pHead = nullptr; //头结点指针


void* producer(void* arg)
{
	//一直生产
	while(1)
	{
		//临界区
		pthread_mutex_lock(&mt);
		Node* pNode = new Node();
		//头插法
		pNode->next = pHead;
		pNode->number = rand() % 100;
		pHead = pNode;
		cout << "----producer, number:" << pNode->number << ", 线程ID:" << pthread_self() << endl;
		pthread_mutex_unlock(&mt);

		//通知所有被阻塞的消费者消费
		pthread_cond_broadcast(&cond);
		//生产慢一点
		sleep(rand() % 3);

	}

	return nullptr;
}

void* consumer(void* arg)
{
	//一直消费
	while(1)
	{
		//临界区
		pthread_mutex_lock(&mt);

		//不能使用if 会有bug，  因为是多线程竞争资源,另一个来使用时  可能已经被使用完
		while(pHead == nullptr)
		{

			//没有资源时 一直阻塞
			pthread_cond_wait(&cond, &mt);
		}
		//从头开始删除
		Node *pNode = pHead;
		cout << "----consumer, number:" << pNode->number << ", 线程ID:" << pthread_self() << endl;
		pHead = pNode->next;
		//删除头结点
		delete(pNode);
		pthread_mutex_unlock(&mt);

		sleep(rand() % 3);

	}


	return nullptr;
}




int main()
{
	//使用条件变量实现生产者和消费者模型，生产者有 5 个，往链表头部添加节点，消费者也有 5 个，删除链表头部的节点。
	pthread_cond_init(&cond, nullptr);
	pthread_mutex_init(&mt, nullptr);
	
	pthread_t tCon[5], tPro[5];
	
	for(int i = 0; i != 5; i++)
	{
		pthread_create(&tPro[i], nullptr, producer, nullptr);
	}

	for(int i = 0; i != 5; i++)
	{
		pthread_create(&tCon[i], nullptr, consumer, nullptr);
	}

	//阻塞线程  回收子线程
	for(int i = 0; i != 5; i++)
	{
		pthread_join(tPro[i],nullptr);
	}

	for(int i = 0; i != 5; i++)
	{
		pthread_join(tCon[i],nullptr);
	}


	pthread_mutex_destroy(&mt);
	pthread_cond_destroy(&cond);
	
	return 0;
}
