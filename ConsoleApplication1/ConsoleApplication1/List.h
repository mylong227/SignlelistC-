#pragma once

/*
	create time : 2021-04-07 / pm 15:25
	dec:�Զ���ʵ��һ���򵥵ĵ���������ʵ�ֹ��ܣ��������ݡ���ѯ���ݡ�
	ɾ�����ݣ�����������Ǵ�ͷ�������ݣ�����β���������ݶ���������λʱ
	����ɣ������˱����������
	author��long long(��¡)
*/

struct Node
{
	int value; //ֵ
	int index; //Ψһ��� ��0��ʼ
	Node *next;//�ڵ�ָ��
	Node(const int& val) :value(val),index(0), next(nullptr) {}
};
//�Զ���ʵ��һ��������
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

