#include "Neuronet.h"




Neuronet::Neuronet(vector<int> neuronetStructure = vector<int>()) : matrixsOfWeights(neuronetStructure.size()-1)
{
	int X = 0;
	//for (MatrixOfWeights& i : matrixsOfWeights)
	{
		//i = MatrixOfWeights::MatrixOfWeights(neuronetStructure.at(X), neuronetStructure.at(X+1));
		X++;
	}
}

Neuronet::~Neuronet()
{
}
