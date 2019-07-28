#include "pch.h"
#include "TTree.h"
#include"SqStack.h"

TTree::TTree()
{
}


TTree::~TTree()
{
}

void TTree::CreateBTree(char * str)
{
	SqStack<Tnode*> stack;
	Tnode *p = NULL, *q = NULL;
	int j = 0, k;
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
			p = new Tnode;
			p->data = c;
			p->rchild = NULL;
			p->lchild = NULL;
			p->ltag = 0;
			p->rtag = 0;
			if (root == NULL)
				root = p;
			else
			{
				if (k == 1)
				{
					q = new Tnode;
					stack.GetTop(q);
					q->lchild = p;
				}
				if (k == 2)
				{
					q = new Tnode;
					stack.GetTop(q);
					q->rchild = p;
				}

			}
			break;
		}
		c = str[++j];
	}
}

void TTree::DispTTree(Tnode * t)
{

	if (t != NULL)
	{
		cout << t->data;
		if (t->lchild != NULL || t->rchild != NULL)
		{
			cout << "(";
			DispTTree(t->lchild);
			if (t->rchild != NULL)
				cout << ",";
			DispTTree(t->rchild);
			cout << ")";
		}
	}
}

void TTree::InThread(Tnode * p)
{
}

void TTree::InThread2(Tnode * p)
{
	SqStack<Tnode *> s;
	Tnode *t = p;
	pre = NULL;
	while (t != NULL || !s.IsEmpty())
	{
		while (t != NULL)
		{
			s.Push(t);
			t = t->lchild;
		}
		if (!s.IsEmpty())
		{

			s.Pop(t);
			if (t->lchild == NULL)
			{
				t->ltag = 1;
				t->lchild = pre;
			}
			if (t->rchild == NULL)
			{
				t->rtag = 1;
			}
			if (pre && pre->rtag == 1)
			{
				pre->rchild = t;
			}
			pre = t;
			t = t->rchild;
		}
	}

}

void TTree::InOrderTh(Tnode * p)
{
	if (p)
	{
		while (p->ltag == 0)
			p = p->lchild;
		do
		{
			cout << p->data;
			p = InPostNode(p);
		} while (p);
	}
}

Tnode * TTree::InPreNode(Tnode * p)
{
	Tnode *q;
	if (p->ltag == 1)
		return p->lchild;
	else
	{
		q = p->lchild;
		while (q->rtag == 0)
			q = q->rchild;
		return q;
	}
}

Tnode * TTree::InPostNode(Tnode * p)
{
	Tnode *q;
	if (p->rtag == 1)
		return p->rchild;
	else
	{
		q = p->rchild;
		while (q->ltag == 0)
			q = q->lchild;
		return q;
	}
}
