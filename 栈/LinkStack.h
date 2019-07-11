#pragma once
#define Status int
#define ERROR 0
#define OK 1
#define FULL 2
#define EMPTY 3
#include <iostream>
using namespace std;
template<class T>
class LinkStack
{
private:
	template <class T>
	class Node
	{
	public:
		T data;
		Node<T> *next;
	};
	Node<T> *top;
public:
	LinkStack();
	~LinkStack();
	Status Push(T e);
	Status Pop(T &e);
	Status GetTop(T &e);
	int StackLength();
	bool IsEmpty();
	void DispStack();
};

template<class T>
LinkStack<T>::LinkStack()
{
	top = new Node<T>;
	if(!top)
		exit(OVERFLOW);
	top->next = NULL;
}

template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T> *p = top;
	Node<T> *q;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	
}

template<class T>
Status LinkStack<T>::Push(T e)
{
	Node<T> *p = new Node<T>;
	if (!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	p->next = top->next;
	top->next = p;
	return OK;
}

template<class T>
Status LinkStack<T>::Pop(T & e)
{
	if (!top->next)
		return EMPTY;
	Node<T> *p;
	p = top->next;
	e = p->data;
	top->next = p->next;
	delete p;
	return OK;
}

template<class T>
Status LinkStack<T>::GetTop(T & e)
{
	if (!top->next)
		return EMPTY;
	e=top->next->data;
	return OK;
}

template<class T>
int LinkStack<T>::StackLength()
{
	int cnt=0;
	Node<T> *p = top;
	if (top->next == NULL)
	{
		return 0;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
			cnt++;
		}
	}
	return cnt;
}

template<class T>
bool LinkStack<T>::IsEmpty()
{
	if (top->next == NULL)
		return true;
	else
		return false;
}

template<class T>
void LinkStack<T>::DispStack()
{
	if (top->next == NULL)
	{
		cout << "栈为空" << endl;
	}
	else
	{
		Node<T> *p=top;
		while (p->next != NULL)
		{
			p = p->next;
			cout << p->data << " ";
		}
		cout << endl;
	}
}
