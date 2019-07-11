#pragma once
template<class T>
class LinkedList //链表
{
private:
	template<class T>
	class Node {
	public:
		T data;
		Node *next;
	};
	Node<T> *head;//头结点
public:
	LinkedList()
	{
		head = new Node<T>;
		head->next = NULL;
	}
	~LinkedList()
	{
		Node<T> *p, *q;
		p = head;
		q = p->next;
		while (q)
		{
			delete[] p;
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
	bool MergeList(LinkedList La, LinkedList Lb);//合并线性表
	void Reverse();//逆置单链表
};
template<class T>
bool LinkedList<T>::CreateList(int n)//逆序建表
{
	Node<T> *p;
	cout << "请输入数据" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new Node<T>;
		if (p == NULL)
		{
			cout << "创建失败" << endl;
			return false;
		}
		cin >> p->data;
		p->next = head->next;
		head->next = p;
	}
	return true;
}
template<class T>
bool LinkedList<T>::InputList(int n)//正序建表
{
	Node<T> *p, *q;
	q = head;
	cout << "请输入" << n << "个数据" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new Node<T>;
		if (p == NULL)
		{
			cout << "创建失败" << endl;
			return false;
		}
		cin >> p->data;
		q->next = p;
		p->next = NULL;
		q = p;
	}
	return true;
}
template<class T>
void LinkedList<T>::OutputList()
{
	Node<T> *p = head;
	if (p->next == NULL)
	{
		cout << "链表为空" << endl;
	}
	else {
		p = p->next;
		while (p->next != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		if (p)
		{
			cout << p->data <<endl;
		}

	}
}
template<class T>
bool LinkedList<T>::ListInsert(int i, T e)
{
	if (i <= 0)
	{
		cout << "请重新输入插入位置" << endl;
		return false;
	}
	Node<T> *p, *q;
	p = head;
	int cnt = 0;
	while (p != NULL && cnt < i - 1)
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
	p->next = q;
	return true;
}
template<class T>
bool LinkedList<T>::ListDelete(int i, T &e)
{
	Node<T> *p, *q;
	p = head;
	int cnt = 0;
	while (p != NULL)
	{
		cnt++;
		if (cnt == i)
		{
			q = p->next;
			p->next = q->next;
			e = q->data;
			delete[] q;
			return true;
		}
		if (p->next != NULL) {
			p = p->next;
		}
		else {
			break;
		}
	}

	return true;
}
template<class T>
bool LinkedList<T>::GetElem_byID(int id, T &e)
{
	Node<T> *p;
	p = head;
	int cnt = 0;
	if (p != NULL)
		p = p->next;
	while (p != NULL)
	{
		cnt++;
		if (cnt == id)
		{
			e = p->data;
			return true;
		}
		if (p->next != NULL) {
			p = p->next;
		}
		else {
			break;
		}
	}
	return false;
}
template<class T>
bool LinkedList<T>::GetElem_byKey(T key, int &i)
{
	Node<T> *p;
	p = head;
	int cnt = 0;
	if (p != NULL)
		p = p->next;
	while (p != NULL)
	{
		cnt++;
		if (key == p->data)
		{
			i = cnt;
			return true;
		}
		if (p->next != NULL) {
			p = p->next;
		}
		else {
			break;
		}
	}
	return false;
}
template<class T>
bool LinkedList<T>::MergeList(LinkedList La, LinkedList Lb)
{
	Node<T> *pa, *pb, *pc, *p;
	pa = La.head;
	pb = Lb.head;
	pc = head;
	pa = pa->next;
	pb = pb->next;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			
			p = new Node<T>();
			p->data = pa->data;
			pc->next = p;
			pc = pc->next;
			pa = pa->next;
		}
		else
		{
			p = new Node<T>();
			p->data = pb->data;
			pc->next = p;
			pc = pc->next;
			pb = pb->next;
		}
	}
	while (pa)
	{
		
		p = new Node<T>();
		p->data = pa->data;
		pc->next = p;
		pc = pc->next;
		pa = pa->next;
	}
	while (pb)
	{
		
		p = new Node<T>();
		p->data = pb->data;
		pc->next = p;
		pc = pc->next;
		pb = pb->next;
	}
	return true;
}
template<class T>
void LinkedList<T>::Reverse()
{
	Node<T> *p, *q;
	//q指向头指针，p指向旧链表第一个元素,让头指针的next为空初始化链表
	q = head;
	p = head->next;
	head->next = NULL;
	while (p)
	{
		q = p;//用q指向需要移动的元素
		p = p->next;//用p指向下一个需要移动的元素
		//将q插入头指针
		q->next = head->next;
		head->next =q;
	}
}
