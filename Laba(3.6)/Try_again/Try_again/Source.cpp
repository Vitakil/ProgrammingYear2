#include<iostream>
#include"Parallel_sort.h"
using namespace std;
int main()
{
	Parallel_sort<8> p(2);
	p.Parallel_hsort();


	return 0;
}