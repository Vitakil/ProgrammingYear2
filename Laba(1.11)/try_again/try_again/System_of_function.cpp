#include "System_of_function.h"
#define Dvector std::vector<double>
System_of_function::System_of_function(Dvector CoefA, Dvector CoefB, Dvector CoefD, vector<Dvector> CoefC,int countC,int countN)
{
	this->CoefA = CoefA;
	this->CoefB = CoefB;
	this->CoefC = CoefC;
	this->CoefD = CoefD;
	this->countC = countC;
	this->countN = countN;
}
Dvector System_of_function::derivation_sum(Dvector X)
{
	Dvector gradient;
	for (int i(0); i < countC; i++)	gradient.push_back(CoefA[i] + 2 * CoefB[i] * X[i]);
	return gradient;
}
bool System_of_function::Check(Dvector X)
{
		for (int i = 0; i < countN; i++)
		{
			double rowSum = 0;
			for (int j = 0; j < countC; j++) 
				rowSum += CoefC[i][j] * X[j];
			if (rowSum > CoefD[i]) return false;
		}
		return true;
}
Dvector System_of_function::sys(Dvector _X)
{
	Dvector prevX;
	Dvector  X = _X;
	Dvector gradient;
	Dvector Condition;
	double lambda = lambdaConst; 
	while ((fabs(Sum(X) - Sum(prevX)) < epsConst)) {
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
	} 
	return Condition;
}
double System_of_function::Sum(Dvector X){
	double res = 0;//variable which save value of function
	//for each function argument calculate its value
	for (int i(0); i < countC; i++)
		res += CoefA[i] * X[i] + CoefB[i] * X[i] * X[i];
	return res;
}
System_of_function::~System_of_function(){};
