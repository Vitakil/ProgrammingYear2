#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#define Dvector std::vector<double>
class System_of_function
{
private:
	vector<double > CoefA;//save all A-coefficient
	vector<double > CoefB;//all B-coefficient
	vector<double > CoefD;//save D-value
	vector<Dvector> CoefC;//for each equation of the system maintain its Ñ-coefficients
	int countC;//number of coefficients
	int countN;//numbers of system
	const double deltaConst=0.95;
	const double epsConst=0.001;
	const double lambdaConst=1;
public:
	System_of_function(Dvector, Dvector, Dvector, vector<Dvector>,int,int);//start
	double Sum(Dvector X);//calculation of the function 
	Dvector derivation_sum(Dvector X);//calculation of the derivation function
	bool Check(Dvector X);//test condition
	Dvector sys(Dvector X);//finding result
	~System_of_function();
};

