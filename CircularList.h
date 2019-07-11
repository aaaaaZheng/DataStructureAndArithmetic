#pragma once
#pragma once
template<class T>
class CircularList //链表
{
private:
	template<class T>
	class Node {
	public:
		T data;
		Node *next;
	};
public:
	Node<T> *head;//头结点
public:
	CircularList()
	{
		head = NULL;
	}
	~CircularList()
	{
		Node<T> *p, *q;
		p = head;
		q = p;
		while (q !=head)
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
	bool InputList(int n);//正序建表
	void OutputList();//输出链表
	void DeleteNode(Node<T> *e);
};
template<class T>
bool CircularList<T>::InputList(int n)//正序建表
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
		if (head == NULL)
		{
			head = p;
			p->next = head;
			q = head;
			continue;
		}
		
		q->next = p;
		p->next = head;
		q = p;
	}
	return true;
}
template<class T>
void CircularList<T>::OutputList()
{
	Node<T> *p = head;
	if (p == NULL)
	{
		cout << "链表为空" << endl;
	}
	else {
		while (p->next != head)
		{
			cout << p->data << " ";
			p = p->next;
		}
		if (p)
		{
			cout << p->data << endl;
		}
	}
}
template<class T>
void CircularList<T>::DeleteNode(Node<T> *e)
{
	Node<T> *p, *q;
	q = e;//指向需要删除的元素
	p = q;
	while (p)//遍历链表
	{
		if (p->next == q)//当下一个是要删掉的元素
		{
			p->next = q->next;
			delete q;
			return;
		}
		p = p->next;
	}
}
