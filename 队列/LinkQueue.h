#pragma once
#define Status int
#define ERROR 0
#define OK 1
#define FULL 2
#define EMPTY 3
#define QUEUE_INIT_SIZE 20
#include <iostream>
template<class T>
struct Node
{
	T data;
	Node<T> * next;
};
template<class T>
class LinkQueue
{
private:
	Node<T> *front;
	Node<T> *rear;
public:
	LinkQueue();
	~LinkQueue();
	Status EnQueue(T e);
	Status DeQueue(T &e);
	int QueueLength();
	bool IsEmpty();
	void DispQueue();
};

template<class T>
LinkQueue<T>::LinkQueue()
{
	front = new Node<T>;
	if (!front)
		exit(OVERFLOW);
	front->next = NULL;
	rear = front;
}

template<class T>
LinkQueue<T>::~LinkQueue()
{
	Node<T> *p;
	p = front;
	while (front->next)
	{
		if (front)
			delete front;
		front = front->next;
	}
}

template<class T>
Status LinkQueue<T>::EnQueue(T e)
{
	Node<T> *p = new Node<T>;
	if (!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	rear->next = p;
	rear = p;
	return OK;
}

template<class T>
Status LinkQueue<T>::DeQueue(T & e)
{
	Node<T> *p;
	if (front == rear)
		return EMPTY;
	p = front->next;
	e = p->data;
	front->next = p->next;
	if (rear == p)
		rear = front;
	delete p;
	return OK;
}

template<class T>
int LinkQueue<T>::QueueLength()
{
	int cnt=0;
	Node<T> *p = front->next;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

template<class T>
bool LinkQueue<T>::IsEmpty()
{
	if (front == NULL)
		return true;
	else
		return false;
}

template<class T>
void LinkQueue<T>::DispQueue()
{
	if (front == rear)
	{
		cout << "队列为空" << endl;
	}
	else 
	{
		Node<T> *p;
		p = front->next;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
