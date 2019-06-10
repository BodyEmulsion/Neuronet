#pragma once
#include"MatrixOfWeight.h"
class Neuronet
{
public:
	Neuronet(vector<int>);
	~Neuronet();
	vector<double> calculate(vector<double> input);
	void learning(vector<double> input, vector<double> trueOutput);
	void save(string);
	void load(string);
private:
	vector<MatrixOfWeights> matrixsOfWeights;
};

