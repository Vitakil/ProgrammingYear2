#include<iostream>
#include<vector>
#include"Betcher_sort.h"
using namespace std;
int main()
{
	srand(0);
	vector<int> m;
	for (int i(0); i < 100; i++)
		m.push_back(rand()%1000);																														
	Betcher_sort mas(m,100,4);
	for (int i(0); i < 100; i++)
		cout << m[i] << " ";
	system("pause");
	return 0;
}