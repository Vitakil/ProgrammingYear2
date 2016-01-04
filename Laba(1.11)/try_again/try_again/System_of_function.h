#pragma once
#include<iostream>
#include<fstream>
#include<vector>
class System_of_function
{
private:
	std::vector<double > CoefA;//save all A-coefficient
	std::vector<double > CoefB;//all B-coefficient
	std::vector<double > CoefD;//save D-value
	std::vector<std::vector<double>> CoefC;//for each equation of the system maintain its Ñ-coefficients
	int countC;//number of coefficients
	int countN;//numbers of system
	const double deltaConst=0.95;
	const double epsConst=0.001;
	const double lambdaConst=1;
public:
	System_of_function(std::ifstream &fin);//reading 
	double Sum(std::vector<double> X);//calculation of the function 
	std::vector<double> derivation_sum(std::vector<double> X);//calculation of the derivation function
	bool Check(std::vector<double> X);//test condition
	std::vector<double> sys(std::vector<double> X);//finding result
	~System_of_function();
};

