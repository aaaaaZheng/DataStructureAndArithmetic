#pragma once
#define Status int
#define ERROR 0
#define OK 1
#define FULL 2
#define EMPTY 3
#define QUEUE_INIT_SIZE 20
#include <iostream>
template<class T>
class CircularQueue
{
private:
	T *base;
	int front;
	int rear;
	int queuesize;
public:
	CircularQueue();
	~CircularQueue();
	Status EnQueue(T e);
	Status DeQueue(T &e);
	int QueueLength();
	bool IsEmpty();
	void DispQueue();
};

template<class T>
CircularQueue<T>::CircularQueue()
{
	base = new T[QUEUE_INIT_SIZE];
	if (!base)
		exit(OVERFLOW);
	front = rear = 0;
	queuesize = QUEUE_INIT_SIZE;
}

template<class T>
CircularQueue<T>::~CircularQueue()
{
	if (base)
		delete[] base;
}

template<class T>
Status CircularQueue<T>::EnQueue(T e)
{
	if ((rear + 1) % queuesize == front)
		return FULL;
	base[rear] = e;
	rear = (rear + 1)%queuesize;
	return OK;
}

template<class T>
Status CircularQueue<T>::DeQueue(T & e)
{
	if (rear == front)
		return EMPTY;
	e = base[front];
	front = (front + 1) % queuesize;
	return OK;
}

template<class T>
int CircularQueue<T>::QueueLength()
{
	if (IsEmpty())
		return 0;
	int p = front;
	int cnt=0;
	while (p != rear)
	{
		cnt++;
		p = (p + 1) % queuesize;
	}
	return cnt;
}

template<class T>
bool CircularQueue<T>::IsEmpty()
{
	if (rear == front)
		return true;
	else
		return false;
}

template<class T>
void CircularQueue<T>::DispQueue()
{
	if (IsEmpty())
	{
		cout << "队列为空" << endl;
		return;
	}
	int p = front;
	int cnt = 0;
	int a = QueueLength();
	while (cnt<a)
	{
		cout << base[p] << " ";
		p = (p + 1) % queuesize;
		cnt++;
	}
	cout << endl;
}
