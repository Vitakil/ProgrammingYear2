#include<iostream>
#include<fstream>
#include"System_of_function.h"
using namespace std;
int main()
{
	ifstream fin("input.txt");
	vector<Dvector> CoefC;
	Dvector CoefA, CoefB, CoefD;
	double data;
	int countC, countN;
	fin >> countC >> countN;
	for (int i(0); i < countC; i++){
		fin >> data;
		CoefA.push_back(data);
	}
	for (int i(0); i < countC; i++){
		fin >> data;
		CoefB.push_back(data);
	}
	for (int i(0); i < countN; i++){
		Dvector ptr;
		for (int j(0); j < countC; j++){
			fin >> data;
			ptr.push_back(data);
		}
		CoefC.push_back(ptr);
	}
	for (int i(0); i < countC; i++){
		fin >> data;
		CoefD.push_back(data);
	}
	System_of_function func(CoefA,CoefB,CoefD,CoefC,countC,countN);
	Dvector X = { 2, 4 };
	//push random points
	Dvector ans = func.sys(X);
	cout << -func.Check(ans) << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	system("pause");
	return 0;
}
