#pragma once
#include<iostream>
#include<thread>
template<int size>
class Parallel_sort
{
public:
	int mas[size];
	int k;
	void shift_down(int ,int);//recover heap
	void dhsort(int ,int);// heapsort 
	void Parallel_hsort();//k-parallel heapsort and merge
	void merge();
	Parallel_sort(int);//constructor
};

