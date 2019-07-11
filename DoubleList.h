
#pragma once
#include<iostream>
using namespace std;
template<class T>
class DoubleList //双向链表
{
private:
	template<class T>
	class Node {
	public:
		T data;
		Node *prior;
		Node *next;
	};
	Node<T> *head;//头结点
public:
	DoubleList()
	{
		head = new Node<T>;
		head->prior = NULL;
		head->next = NULL;
	}
	~DoubleList()
	{
		Node<T> *p, *q;
		p = head;
		q = p->next;
		while (q)
		{
			if (p != NULL)
			{
				delete[] p;
			}
			p = q;
			q = p->next;
		}
		if (p != NULL)
		{
			delete[] p;
		}
	}
	bool CreateList(int n);//逆序建表
	bool InputList(int n);//正序建表
	void OutputList();//输出链表
	bool ListInsert(int i, T e);//插入
	bool ListDelete(int i, T &e);//删除
	bool GetElem_byID(int id, T &e);//已知下标返回值
	bool GetElem_byKey(T key, int &i);//已知值返回下标
	bool MergeList(DoubleList La, DoubleList Lb);//合并线性表
};
template <class T>
bool DoubleList<T>::CreateList(int n)
{
	Node<T> *p;
	cout << "请输入" << n << "个数据:" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new Node<T>;
		if (!p)//申请内存失败，返回false
		{
			return false;
		}
		cin >> p->data;
		if (!head->next)
		{
			head->next = p;
			p->next = NULL;
			p->prior = head;
		}
		else
		{
			p->next = head->next;
			p->prior = head;
			p->next->prior = p;
			head->next = p;
		}
	}
	return true;
}
template <class T>
bool DoubleList<T>::InputList(int n)
{
	Node<T> *p, *q;
	q = head;
	cout << "请输入" << n << "个数据:" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new Node<T>;
		if (!p)//申请内存失败，返回false
		{
			return false;
		}
		cin >> p->data;
		p->next = NULL;
		p->prior = q;
		q->next = p;
		q = p;
	}
	return true;
}

template<class T>
void DoubleList<T>::OutputList()
{
	Node<T> *p;
	p = head->next;
	if (!p)
	{
		cout << "双向链表为空" << endl;
	}
	else
	{
		while (p->next != NULL)
		{
			cout << p->data << " ";
			p=p->next;
		}
		if (p)
		{
			cout << p->data << endl;
		}
	}
}

template<class T>
bool DoubleList<T>::ListInsert(int i, T e)
{
	Node<T> *p, *q;
	int cnt = 0;
	p = head;
	while (p && cnt < i - 1)//寻找第i个节点
	{
		p = p->next;
		cnt++;
	}
	if (!p || cnt > i - 1)
	{
		return false;
	}
	q = new Node<T>;
	q->data = e;
	q->next = p->next;
	q->prior = p;
	p->next = q;
	q->next->prior = q;
	return true;
}

template<class T>
bool DoubleList<T>::ListDelete(int i, T & e)
{
	Node<T> *p;
	p = head;
	int cnt = 0;
	while (p && cnt < i)//寻找第i个节点
	{
		p = p->next;
		cnt++;
	}
	if (!p || cnt > i)
	{
		return false;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	e = p->data;
	delete p;
	return true;
}

template<class T>
bool DoubleList<T>::GetElem_byID(int id, T & e)
{
	Node<T> *p;
	p = head;
	int cnt = 0;
	while (p && cnt < id)
	{
		p = p->next;
		cnt++;
	}
	if (!p || cnt > id)
	{
		return false;
	}
	e = p->data;
	return true;
}

template<class T>
bool DoubleList<T>::GetElem_byKey(T key, int & i)
{
	Node<T> *p;
	p = head;
	int cnt = 0;
	while (p->next)
	{
		if (p->data == key)
		{
			i = cnt;
			return true;
		}
		cnt++;

		p = p->next;


	}
	if (p->data == key)
	{
		i = ++cnt;
		return true;
	}
	return false;
}

template<class T>
bool DoubleList<T>::MergeList(DoubleList La, DoubleList Lb)
{
	Node<T> *pa, *pb, *pc,*p;
	pa = La.head->next;
	pb = Lb.head->next;
	pc = head;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			p = new Node<T>;
			if (!p)
			{
				return false;
			}
			p->data = pa->data;
			p->prior = pc;
			p->next = NULL;
			pc->next = p;
			pc = pc->next;
			pa = pa->next;
		}
		else
		{
			p = new Node<T>;
			if (!p)
			{
				return false;
			}
			p->data = pb->data;
			p->prior = pc;
			p->next = NULL;
			pc->next = p;
			pc = pc->next;
			pb = pb->next;
		}
	}
	while (pa)
	{
		p = new Node<T>;
		if (!p)
		{
			return false;
		}
		p->data = pa->data;
		p->prior = pc;
		p->next = NULL;
		pc->next = p;
		pc = pc->next;
		pa = pa->next;
	}
	while (pb)
	{
		p = new Node<T>;
		if (!p)
		{
			return false;
		}
		p->data = pb->data;
		p->prior = pc;
		p->next = NULL;
		pc->next = p;
		pc = pc->next;
		pb = pb->next;
	}
	return true;
}
