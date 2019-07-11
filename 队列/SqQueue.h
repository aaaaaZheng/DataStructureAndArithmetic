#pragma once
#define Status int
#define ERROR 0
#define OK 1
#define FULL 2
#define EMPTY 3
#define QUEUE_INIT_SIZE 20
#include <iostream>
template<class T>
class SqQueue
{
private:
	T *base;
	T *front;
	T *rear;
	int queuesize;
public:
	SqQueue();
	~SqQueue();
	Status EnQueue(T e);
	Status DeQueue(T &e);
	int QueueLength();
	bool IsEmpty();
	void DispQueue();
};

template<class T>
SqQueue<T>::SqQueue()
{
	base = new T[QUEUE_INIT_SIZE];
	if (!base)
		exit(OVERFLOW);
	front = rear = base;
	queuesize = QUEUE_INIT_SIZE;
}

template<class T>
SqQueue<T>::~SqQueue()
{
	if (base)
		delete[] base;
}

template<class T>
Status SqQueue<T>::EnQueue(T e)
{
	if (rear - front >= queuesize)
		return FULL;
	*rear++ = e;
	return OK;
}

template<class T>
Status SqQueue<T>::DeQueue(T & e)
{
	if (front == rear)
		return EMPTY;
	e = *front++;
	return OK;
}

template<class T>
int SqQueue<T>::QueueLength()
{
	if (IsEmpty())
		return 0;
	T *p;
	int cnt;
	p = front;
	while (p != rear)
	{
		cnt++;
	}
	return cnt;
}

template<class T>
bool SqQueue<T>::IsEmpty()
{
	if (rear == front)
		return true;
	else
		return false;
}

template<class T>
void SqQueue<T>::DispQueue()
{
	if (IsEmpty())
	{
		cout << "队列为空" << endl;
		return;
	}
	T *p;
	p = front;
	while (p != rear)
	{
		cout << *p++ << " ";
	}
	cout << endl;
}
