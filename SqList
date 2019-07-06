#pragma once
#include <iostream>
#define Status int
#define OK 1
#define Error 0
using namespace std;
template<class T>
class SqList  //顺序表
{
public:
	T * data;//
	int length;//实际存放元素的个数
	int listSize;//可以容纳最大的元素的个数
	bool ReSize(int listSize);

public:
	SqList(int listSize = 100)
	{
		this->listSize = listSize;
		data = new T[listSize];
		length = 0;
	}
	~SqList()
	{
		delete[] data;
	}
	void InputList_Sq();//输入链表
	void OutputList_Sq();//输出链表
	bool ListInsert_Sq(int i, T e);//插入
	bool ListDelete_Sq(int i, T &e);//删除
	bool GetElem_byID(int id, T &e);//已知下标返回值
	bool GetElem_byKey(T key, int &i);//已知值返回下标
	bool MergeList_Sq(SqList La, SqList Lb);//合并线性表
	bool Insert(T e);//将X插入顺序表适当的位置
	void Reverse();//将顺序表逆转
};
template<class T>
bool SqList<T>::ReSize(int listSize)//重新开辟空间
{
	this->listSize = listSize;
	T *temp = new T[listSize];
	if (!temp)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	return true;
}
template <class T>
void SqList<T>::InputList_Sq()//输入链表
{
	cout << "请输入链表元素的个数" << endl;
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "您输入的元素个数不合理";
		return;
	}
	if (num > listSize)
	{
		ReSize(num);
	}
	length = num;
	cout << "请输入数据" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> data[i];
	}
}
template <class T>
void SqList<T>::OutputList_Sq()//输出链表
{
	if (length == 0)
	{
		cout << "链表为空" << endl;
	}
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
template <class T>
bool SqList<T>::ListInsert_Sq(int i, T e)//插入
{
	if (i<0 || i>length + 1)
	{
		cout << "插入位置不合理" << endl;
		return false;
	}
	if (listSize == length)
	{
		ReSize(length + 1);
	}
	T *p = &(data[i - 1]);
	for (T *q = &(data[length - 1]); p <= q; q--)
	{
		*(q + 1) = *q;
	}
	*p = e;
	length++;
	return true;
}
template <class T>
bool SqList<T>::ListDelete_Sq(int i, T &e)//删除
{
	if (i<0 || i>length)
	{
		cout << "删除位置不合理" << endl;
		return false;
	}
	T *p = &(data[i - 1]);
	e = *p;
	T *q = &(data[length - 1]);
	for (++p; p <= q; p++)
	{
		*(p - 1) = *p;
	}
	length--;
	return true;
}
template <class T>
bool SqList<T>::GetElem_byID(int id, T &e)//已知下标返回值
{
	if (id<0 || id>length)
	{
		cout << "元素不存在" << endl;
		return false;
	}
	e = data[id - 1];
	return true;
}
template <class T>
bool SqList<T>::GetElem_byKey(T key, int &i)//已知值返回下标
{
	for (int a = 0; a < length; a++)
	{
		if (data[a] == key)
		{
			i = a;
			return true;
		}
	}
	return false;
}
template <class T>
bool SqList<T>::MergeList_Sq(SqList La, SqList Lb)//合并线性表
{
	T *pa, *pb, *pc, *paLast, *pbLast;
	pa = La.data;
	pb = Lb.data;
	length = La.length + Lb.length;
	cout << length << endl;
	if (length > listSize)
	{
		ReSize(length);
	}
	pc = data;
	if (data == NULL)
	{
		cout << "空间分配失败" << endl;
		return false;
	}
	paLast = La.data + La.length - 1;
	pbLast = Lb.data + Lb.length - 1;
	while (pa <= paLast && pb <= pbLast)
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	while (pa <= paLast)
	{
		*pc++ = *pa++;
	}
	while (pb <= pbLast)
	{
		*pc++ = *pb++;
	}
	return true;
}
/*
*插入成功返回true,失败返回false
*/
template<class T>
bool SqList<T>::Insert(T e)
{
	if (length == listSize)//如果顺序表的长度和最大长度相同，最大长度加1
	{
		if (!ReSize(length + 1))//如果扩容失败返回false
			return false;
	}
	for (int i = 0; i < length; i++)//遍历线性表
	{
		if (data[i] >= e)//找到插入的位置
		{
			T *p;
			p = &(data[i]);
			for (T *q = &(data[length - 1]); p <= q; q--)//将元素后移一位
			{
				*(q + 1) = *q;
			}
			*p = e;//将要插入的元素插入
			length++;
			return true;//结束循环返回true
		}
	}
	data[length] = e;//在顺序表末尾添加
	length++;
	return true;
}
template<class T>
void SqList<T>::Reverse()
{
	T temp;
	for (T *p = data, *q = &(data[length - 1]); p <= q; p++, q--)
	{
		temp = *p;
		*p = *q;
		*q = temp;
	}
}
