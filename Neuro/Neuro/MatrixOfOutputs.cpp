#include "MatrixOfOutputs.h"



MatrixOfOutputs::MatrixOfOutputs(vector<int> neuronetStructure = vector<int>())
{
	matrix = vector<vector<double>>(neuronetStructure.size());
	int k = 0;
	for (vector<double> &X : matrix)
	{
		X = vector<double>(neuronetStructure.at(k));
		k++;
	}
}


MatrixOfOutputs::~MatrixOfOutputs()
{
}
