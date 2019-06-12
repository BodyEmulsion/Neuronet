#pragma once
#include "Matrix.h"
#include <random>
#include<ctime>
#include<fstream>
#include<string>

class MatrixOfWeights :
	public Matrix
{
public:
	MatrixOfWeights(int,int);
	MatrixOfWeights();
	~MatrixOfWeights();
	vector<double> returnWeightedValues(vector<double>);
	vector<double> returnActivatedValues(vector<double>);
	void save(string);
	void load(string);

private:

};
 
double activationFunction(double);
