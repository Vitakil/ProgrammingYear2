#include "Double_List.h"


Double_List::Double_List(int  size)
{
	head.resize(size);
	this->size = size;
}
void Double_List::push_back(int row, int data)
{
	if (row >= size) std::cout << "Error!!\n";
	else head[row ].push_back(data);
}
int Double_List::pop(int row){
	if (row >= size)std::cout << "Error!!\n";
	else return head[row ].pop();
}
Node* Double_List::find(int data){
	for (int i(0); i < size; i++)
		return head[i].find(data);
}
Double_List::~Double_List()
{
	for (int i(0); i < size; i++)
	{
		head[i].~List();
		std::cout << std::endl;
	}
}
