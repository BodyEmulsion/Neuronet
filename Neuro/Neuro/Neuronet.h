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
	int outputSize();
	int inputSize();
	int size();

private:
	vector<MatrixOfWeights> matrixsOfWeights;

	vector<vector<double>> returnMatrixOfMistakes(vector<double>, vector<double>);
	vector<vector<double>> returnMatrixOfOutputs(vector<double>);
	vector<vector<double>> returnMatrixOfWeightedValues(vector<vector<double>>);
};

