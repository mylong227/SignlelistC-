#pragma once

/*
	create time : 2021-04-07 / pm 15:25
	dec:自定义实现一个简单的单链表，具体实现功能：增加数据、查询数据、
	删除数据，具体亮点就是从头插入数据，或者尾部插入数据都是做到单位时
	间完成，避免了遍历链表操作
	author：long long(龙隆)
*/

struct Node
{
	int value; //值
	int index; //唯一标记 从0开始
	Node *next;//节点指针
	Node(const int& val) :value(val),index(0), next(nullptr) {}
};
//自定义实现一个单链表
class List
{

private:
	void clear();
	int tag = -1;
	void resetList();
	~List();

public:
	List();

	Node *headNode	= nullptr;
	Node *endNode	= nullptr;
	int size		= 0;

	void addEnd(const int& val);
	void addHead(const int& val);
	void insert(const int &index, const int &Val);
	void del(const int &index);

	Node *findByValue(const int& val);
	Node *findByIndex(const int& val);

	void printList();
};

