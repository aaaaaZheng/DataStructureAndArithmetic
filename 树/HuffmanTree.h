#pragma once
#define N 5 //叶子数
#define MAXW 2147483647
struct HTNode
{
	int weight;
	int parent, lchild, rchild;
};
class HuffmanTree
{
public :
	HTNode* HT;
	char ** HC;//哈夫曼编码HuffmanCode
	int *Weight;
	char *NodeName;
public:
	HuffmanTree();
	~HuffmanTree();
	char* Input();
	void PrintWeight();
	void PrintHC();
	void PrintHT();
	char* Encoding(char *str);
	char* Decoding(char *str);
private:
	int min(int i);//找个i个结点中，权值最小的点
	void select(int i, int &s1, int &s2);
	void HuffmanCoding();//构造HuffmanTree
	int GetIndex(char c);//返回c在NodeName数组中的下标
	void SetWeight(char *input);
};

