#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<thread>
#include<future>
using std::thread;
using std::vector;
class Betcher_sort
{
private:
	int k;
	int size;
public:
	void merge_sort(vector<int >, int, int,int);
	void merge(vector<int> &a, int low1, int high1, int low2, int high2);
	 void heap_sort(vector<int>&,int ,int);
	void shiftDown(vector<int>&,int ,int,int);
	Betcher_sort(vector<int>&,int ,int);
	~Betcher_sort();
};

