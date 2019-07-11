#pragma once
#define Status int
#define ERROR 0
#define OK 1
#define FULL 2
#define EMPTY 3
#define STACK_INIT_SIZE 20
#include <iostream>
using namespace std;
template<class T>
class SqStack
{
	T *base;
	T *top;
	int stacksize;
public:
	SqStack();
	~SqStack();
	Status Push(T e);
	Status Pop(T &e);
	Status GetTop(T &e);
	int StackLength();
	bool IsEmpty();
	void DispStack();

};

template<class T>
SqStack<T>::SqStack()
{
	base = new T[STACK_INIT_SIZE];
	if(!base)
		exit(OVERFLOW);
	top = base;
	stacksize = STACK_INIT_SIZE;
}

template<class T>
SqStack<T>::~SqStack()
{
	delete[] base;
}

template<class T>
Status SqStack<T>::Push(T e)
{
	if (base-top == stacksize)
		return FULL;
	*top++ = e;
	return OK;
}

template<class T>
Status SqStack<T>::Pop(T & e)
{
	if (top == base)
		return EMPTY;
	e = *--top;
	return OK;
}

template<class T>
Status SqStack<T>::GetTop(T & e)
{
	if (top == base)
		return ERROR;
	e = *(top - 1);
	return OK;
}

template<class T>
int SqStack<T>::StackLength()
{
	return top-base;
}

template<class T>
bool SqStack<T>::IsEmpty()
{
	if (top == base)
		return true;
	else
		return false;
}

template<class T>
void SqStack<T>::DispStack()
{
	if (IsEmpty())
	{
		cout << "栈为空" << endl;
	}
	else 
	{
		for (T *p=base; p < top; p++)
		{
			cout << *p << " " ;
		}
		cout << endl;
	}
}
