#include "pch.h"
#include "HuffmanTree.h"
#include<iostream>
using namespace std;
HuffmanTree::HuffmanTree()
{
}


HuffmanTree::~HuffmanTree()
{
}

char * HuffmanTree::Input()
{

	return nullptr;
}

void HuffmanTree::PrintWeight()
{
}

void HuffmanTree::PrintHC()
{
}

void HuffmanTree::PrintHT()
{
}

char * HuffmanTree::Encoding(char * str)
{
	int i = 0;
	int pos;
	char* posts;
	char *poststr = new char[MAXW];
	poststr[0] = '\0';
	posts = new char[N];
	while (str[i])
	{
		pos = GetIndex(str[i]);
		if (pos < N)
		{
			posts = HC[pos];
			strcat_s(poststr, MAXW, posts);
		}
		else
		{
			cout << "出现未知字符，编码工作失败！" << endl;
			break;
		}
		i++;
	}
	return poststr;
}

char * HuffmanTree::Decoding(char * str)
{
	char ch;
	int j = 0,i, root;
	char * poststr = new char[MAXW];
	root = 2 * N - 2;
	for (i = 0; *(str + i - 1) != '\0'; i++)
	{
		ch = *(str + i);
		if (HT[root].lchild == -1)
		{
			*(poststr + j) = *(NodeName + root);
			j++;
			root = 2 * N - 2;
			i--;
		}
		else if (ch == '0')
			root = HT[root].lchild;
		else if (ch == '1')
			root = HT[root].rchild;
	}
	*(poststr + j) = '\0';
	return poststr;
}

int HuffmanTree::min(int i)
{
	return 0;
}

void HuffmanTree::select(int i, int & s1, int & s2)
{
	int min1=_CRT_INT_MAX, min2= _CRT_INT_MAX;
	int cnt1=0, cnt2=0;
	for (int k = 0; k < i; k++)
	{
		if (Weight[k] < min1)
		{
			min1 = Weight[k];
			cnt1 = k;
		}	
	}
	for (int k = 0; k < i; k++)
	{
		if (k != min1 && Weight[k] < min2)
		{
			min2 = Weight[k];
			cnt2 = k;
		}
			
	}
}

//HTNode* HT;
//char ** HC;//哈夫曼编码HuffmanCode
//int *Weight;
//char *NodeName;
void HuffmanTree::HuffmanCoding()
{
	int i, s1, s2, start;
	char *cd;
	unsigned int c, f;
	//初始化
	for (int i = 0; i < N; i++)
	{
		HT[i].weight = Weight[i];
		HT[i].lchild = 0;
		HT[i].rchild = -1;
		HT[i].parent = -1;
	}
	for (int i = N; i < N * 2 - 1; i++)
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
	}
	//建立HUFFMANTREE
	for (int i = N; i < N * 2 - 1; i++)
	{
		select(i, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//编码
	cd = new char[N];
	cd[N - 1] = '\0';
	for (int i = 0; i < N; i++)
	{
		start = N - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c)
				cd[--start] = 0;
			else
				cd[--start] = 1;
		}
		HC[i] = new char[N - start];
		strcpy_s(HC[i], N , &cd[start]);
	}
	delete cd;
}

int HuffmanTree::GetIndex(char c)
{
	for (int i = 0; i < N; i++)
	{
		if (NodeName[i] == c)
			return i;
	}
	return N + 1;
}

void HuffmanTree::SetWeight(char * input)
{
}
