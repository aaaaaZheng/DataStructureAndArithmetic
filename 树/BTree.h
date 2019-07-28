#pragma once
#include"SqStack.h"
template<class T>
struct Node
{
	T data;
	Node *lchild, *rchild;
};
template<class T>
struct PostNode
{
	Node<T> *ptr;
	int tag;
};
template<class T>
class BTree
{
public:
	BTree();
	~BTree();
	Node<T>* GetRoot();
	void CreateBTree(char *str);
	int getBTreeHeight(Node<T> *t);
	void DispBTree(Node<T> *t);
	void PreOrderDispBTree(Node<T> *t);
	void InOrderDispBTree(Node<T> *t);
	void PostOrderDispBTree(Node<T> *t);
	void PreOrderDispTree2();
	void InOrderDispBTree2();
	void PostOrderDispBTree2();
private:
	Node<T> *root;
};
template<class T>
BTree<T>::BTree()
{
}

template<class T>
BTree<T>::~BTree()
{
}
template<class T>
Node<T>* BTree<T>::GetRoot()
{
	if(root!=NULL)
		return root;
	else 
		return NULL;
}
template<class T>
void BTree<T>::CreateBTree(char * str)
{
	SqStack<Node<T> *> stack;
	Node<T> *p=NULL,*q=NULL;
	int j=0,k;
	char c;
	c = str[j];
	while (c != '\0')
	{
		switch (c)
		{
		case '(':
			k = 1;
			stack.Push(p);
			break;
		case')':
			stack.Pop(p);
			break;
		case ',':
			k = 2;
			break;
		default:
			p = new Node<T>;
			p->data = c;
			p->rchild = NULL;
			p->lchild = NULL;
			if (root == NULL)
				root = p;
			else
			{
				if (k == 1)
				{
					q = new Node<T>;
					stack.GetTop(q);
					q->lchild = p;
				}
				if (k == 2)
				{
					q = new Node<T>;
					stack.GetTop(q);
					q->rchild = p;
				}
					
			}
			break;
		}
		c = str[++j];
	}
}

template<class T>
int BTree<T>::getBTreeHeight(Node<T> *t)
{
	int lChildHeigh, rChildHeigh;
	if (t == NULL)
		return 0;
	else
	{
		lChildHeigh =getBTreeHeight(t->lchild);
		rChildHeigh = getBTreeHeight(t->rchild);
		return lChildHeigh>rChildHeigh ? lChildHeigh + 1: rChildHeigh + 1;
	}
}

template<class T>
void BTree<T>::DispBTree(Node<T> *t)
{
	if (t != NULL)
	{
		cout << t->data;
		if (t->lchild != NULL || t->rchild != NULL)
		{
			cout << "(";
			DispBTree(t->lchild);
			if (t->rchild != NULL)
				cout << ",";
			DispBTree(t->rchild);
			cout << ")";
		}
	}
}

template<class T>
void BTree<T>::PreOrderDispBTree(Node<T> *t)
{
	if (t != NULL)
	{
		cout << t->data;
		PreOrderDispBTree(t->lchild);
		PreOrderDispBTree(t->rchild);
	}
}

template<class T>
void BTree<T>::InOrderDispBTree(Node<T> *t)
{
	if (t != NULL)
	{

		InOrderDispBTree(t->lchild);
		cout << t->data;
		InOrderDispBTree(t->rchild);
	}

}

template<class T>
void BTree<T>::PostOrderDispBTree(Node<T> *t)
{
	if (t != NULL)
	{

		PostOrderDispBTree(t->lchild);
		
		PostOrderDispBTree(t->rchild);
		cout << t->data;
	}
}

template<class T>
void BTree<T>::PreOrderDispTree2()
{
	SqStack<Node<T>*> stack;
	Node<T> *p;
	p = root;
	while (p != NULL || !stack.IsEmpty())
	{
		while (p != NULL)
		{
			cout << p->data;
			stack.Push(p);
			p = p->lchild;
		}
		if (!stack.IsEmpty())
		{
			stack.Pop(p);
			p = p->rchild;
		}
	}
}

template<class T>
void BTree<T>::InOrderDispBTree2()
{
	SqStack<Node<T>*> stack;
	Node<T> *p;
	p = root;
	while (p != NULL || !stack.IsEmpty())
	{
		while (p != NULL)
		{
			
			stack.Push(p);
			p = p->lchild;
		}

		if (!stack.IsEmpty())
		{
			stack.Pop(p);
			cout << p->data;
			p = p->rchild;
		}
	}
}
template<class T>
void BTree<T>::PostOrderDispBTree2()
{
	SqStack<PostNode<T>> s;
	PostNode<T> x;
	Node<T> *p = root;
	do 
	{
		
		while (p != NULL)
		{
			x.ptr = p;
			x.tag = 0;
			s.Push(x);
			p = p->lchild;
		}
		while (!s.IsEmpty() && (s.GetTop().tag == 1))
		{
			s.Pop(x);
			p = x.ptr;
			cout << p->data;
		}
		if (!s.IsEmpty())
		{
			s.Pop(x);
			x.tag=1;
			s.Push(x);
			p = s.GetTop().ptr->rchild;
		}

	} while (!s.IsEmpty());
}

