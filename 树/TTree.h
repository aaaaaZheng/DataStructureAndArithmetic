#pragma once
#include<iostream>
struct Tnode
{
	char data;
	int ltag, rtag;
	Tnode *lchild, *rchild;
};
class TTree
{
public:
	Tnode *root;
	Tnode *pre = NULL;
public:
	TTree();
	~TTree();
	void CreateBTree(char *str);
	void DispTTree(Tnode *t);
	void InThread(Tnode *p);
	void InThread2(Tnode *p);
	void InOrderTh(Tnode *p);
	Tnode* InPreNode(Tnode *p);
	Tnode* InPostNode(Tnode *p);
};

