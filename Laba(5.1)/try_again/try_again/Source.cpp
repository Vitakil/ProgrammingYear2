#include<iostream>
#include"List.h"
#include"Double_List.h"
using  namespace std;
int main()
{
	Double_List  First(10);
	srand(0);
	for (int i(0); i < 10;i++)
	for (int j(0); j < 5; j++)
		First.push_back(i, rand() % 100);
	First.~Double_List();
	system("pause");
	return 0;
}
