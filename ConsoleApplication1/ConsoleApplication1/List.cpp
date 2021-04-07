#include "List.h"
#include <iostream>

List::List() 
{
}

List::~List() 
{
	this->clear();//�ڴ��ͷ�
}

//β�ڵ㿪ʼ
void List::addEnd(const int& val) 
{
	Node* node			= new Node(val);
	this->tag++;

	node->index			= this->tag;
	if (!this->endNode) {
		this->endNode	= node;
		this->headNode	= node;
		//this->size++;
	}
	else
	{
		/*Node* node = this->find(val); //�����ų��ظ�������
		if (!node) {*/
		//Node* node = new Node(val);
		this->endNode->next = node;
		this->endNode		= node;
		//this->size++;
		//}
	}
	this->size++;
}
//ͷ��㿪ʼ
void List::addHead(const int& val) 
{
	Node* node			= new Node(val);
	this->tag++;

	node->index			= this->tag;
	if (!this->headNode) {
		this->headNode	= node;
		this->endNode	= node; //β�ڵ㱣�ֲ�Ҫ�ƶ�
	}
	else
	{
		node->next		= this->headNode;
		this->headNode	= node;
	}
	this->size++;
}

//ֵ�������ظ���ʱ���ҵ���һ����ͬ��ֵ��ֱ�ӷ��أ�
Node *List::findByValue(const int& val) 
{
	Node * resultNode = nullptr;
	for (Node * node = this->headNode; node != nullptr; node = node->next)
	{
		if (node->value == val) {
			resultNode = node;
			break;
		}
	}
	return resultNode;
}
//�±��ǲ���Ψһ׼ȷ
Node *List::findByIndex(const int& index) 
{
	Node * resultNode = nullptr;
	for (Node * node = this->headNode; node != nullptr; node = node->next)
	{
		if (node->index == index) {
			resultNode = node;
			break;
		}
	}
	return resultNode;
}

void List::insert(const int &index, const int &val) 
{
	Node* lastNode = nullptr;
	for (Node* node = this->headNode; node; node = node->next)
	{
		if (node->index == index) {
			if (lastNode) {
				Node* insertNode	= new Node(val);
				this->tag++;
				insertNode->index	= this->tag;

				lastNode->next		= insertNode;
				insertNode->next	= node;
				this->size++;
				break;
			}
			else {
				this->addHead(val);
				break;
			}
		}
		lastNode = node;
	}
}

void List::del(const int &index)
{
	Node* lastNode = nullptr;
	for (Node* node = this->headNode; node; node = node->next)
	{
		if (node->index == index) {
			if (lastNode) {
				Node* delNode	= node;
				lastNode->next	= delNode->next;
				this->size--;
				delete delNode;
				break;
			}else
			{
				this->resetList();
				delete node;
				break;
			}
		}
		lastNode = node;
	}
}

void List::clear() {
	Node* node = this->headNode;
	while (node) {
		Node* delNode = node;
		node = node->next;
		delete delNode;
	}
	this->resetList();
}

void List::resetList() {
	this->size		= 0;
	this->tag		= -1;
	this->headNode	= nullptr;
	this->endNode	= nullptr;
}


void List::printList() {
	for (Node* node = this->headNode; node; node = node->next)
	{
		std::cout << "value" << node->value << " index:" << node->index << std::endl;
	}
}