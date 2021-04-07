#include "List.h"
#include <iostream>

List::List() 
{
}

List::~List() 
{
	this->clear();//内存释放
}

//尾节点开始
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
		/*Node* node = this->find(val); //不做排除重复的数据
		if (!node) {*/
		//Node* node = new Node(val);
		this->endNode->next = node;
		this->endNode		= node;
		//this->size++;
		//}
	}
	this->size++;
}
//头结点开始
void List::addHead(const int& val) 
{
	Node* node			= new Node(val);
	this->tag++;

	node->index			= this->tag;
	if (!this->headNode) {
		this->headNode	= node;
		this->endNode	= node; //尾节点保持不要移动
	}
	else
	{
		node->next		= this->headNode;
		this->headNode	= node;
	}
	this->size++;
}

//值出现又重复的时候，找到第一个相同的值就直接返回，
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
//下标标记查找唯一准确
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