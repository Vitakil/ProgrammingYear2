#pragma once
#include"List.h"
#include<vector>
class Double_List:public List
{
private :
	std::vector<List> head;//vector of head on List
	int size;
public:
	Double_List(int );
	void push_back(int,int);
	int pop(int);
	Node* find(int );
	~Double_List();
};

