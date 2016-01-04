#include<iostream>
#include<fstream>
#include"System_of_function.h"
using namespace std;
int main()
{
	ifstream fin("input.txt");	
	System_of_function func(fin);
	vector<double> X;
	X.push_back(4);
	X.push_back(10);
	//push random points
	vector<double> ans = func.sys(X);
	cout << -func.Check(ans) << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	system("pause");
	return 0;
}
