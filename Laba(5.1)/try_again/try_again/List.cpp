#include "List.h"


List::List()
{
	head = nullptr;
	tail = nullptr;
}

void  List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else if (head == tail) {
		tail = new Node(data);
		head->next = tail;
	}
	else {
		Node* ptr = new Node(data);
		tail->next = ptr;
		tail = ptr;
	}
}
int List::pop(){
	if (head == nullptr) {
		std::cout << "Error!!List is empty!!!\n";
		return 0;
	}
	else if (head == tail)
	{
		int ptr = head->data;
		delete head;
		head = tail = nullptr;
		return ptr;
	}
	else
	{
		Node* ptr = head;
		while (ptr->next != tail)
			ptr = ptr->next;
		ptr->next = nullptr;
		int res = tail->data;
		delete tail;
		tail = ptr;
		return res;
	}
}
Node* List::find(int data)
{
	if (head == nullptr){
		std::cout << "List is empty!!Element not found!\n";
		return nullptr;
	}
	else
	{
		Node* ptr = head;
		while (ptr != nullptr || ptr->data != data)
			ptr = ptr->next; 
		if (ptr == nullptr) {
			std::cout << "Element not found!!\n";
			return nullptr;
		}
		else return ptr;
	}
}
List::~List()
{
	while (head != nullptr)
		std::cout<<this->pop()<<" ";
}
