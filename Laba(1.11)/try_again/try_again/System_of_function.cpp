#include "System_of_function.h"


System_of_function::System_of_function(std::ifstream &fin)
{
	double data;
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
		std::vector<double> ptr;
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
}
double System_of_function::Sum(std::vector<double> X){
	double res = 0;//variable which save value of function
	//for each function argument calculate its value
	for (int i(0); i < countC; i++)
		res += CoefA[i] * X[i] + CoefB[i] * X[i] * X[i];
	return res;
}
std::vector<double> System_of_function::derivation_sum(std::vector<double> X){
	std::vector<double > gradient;
	for (int i(0); i < countC; i++)
		gradient.push_back(CoefA[i] + 2 * CoefB[i] * X[i]);
		return gradient;
}
bool System_of_function::Check(std::vector<double> X){
		if (countN < 1)  return 1;
		for (int i = 0; i < countN; i++)
		{
			double rowSum = 0;
			for (int j = 0; j < countC; j++) 
				rowSum += CoefC[i][j] * X[j];
			if (rowSum > CoefD[i]) return false;
		}
		return 1;
}
std::vector<double> System_of_function::sys(std::vector<double> _X)
{
	std::vector<double> prevX;
	std::vector<double>  X = _X;
	std::vector<double> gradient;
	std::vector<double> Condition;
	double lambda = lambdaConst; 
	do {
		prevX = X;	
		gradient = derivation_sum(X);
		for (int j = 0; j < X.size(); j++) 
			X[j] = X[j] - lambda*gradient[j];
		double normGradSqr = 0;
		for (int j = 0; j < X.size(); j++) 
			normGradSqr += gradient[j] * gradient[j];
		while (Sum(X) > Sum(prevX) - epsConst*lambda*normGradSqr) {
			lambda = lambda*deltaConst;
			X = prevX;
			for (int j = 0; j < X.size(); j++)
				X[j] = X[j] - lambda*gradient[j];
		}
	} while ( (fabs(Sum(X) - Sum(prevX)) > epsConst));
	return Condition;
}
System_of_function::~System_of_function(){};
