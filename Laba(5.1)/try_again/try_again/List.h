#pragma once
#include<iostream>
class Node{
	friend class List;
	int data;
	Node* next;
	Node(int  _data){
		data = _data;
		next = nullptr;
	}
};
class List
{
private:
	Node* head;//head of List
	Node* tail;//tail of List
public:
	List();
	virtual void  push_back(int);
	virtual int pop();
	virtual Node* find(int );
	virtual ~List();
};

