#pragma once
#include"MatrixOfWeight.h"
class Neuronet
{
public:
	Neuronet(vector<int>);
	~Neuronet();
private:
	vector<MatrixOfWeights> matrixsOfWeights;
};

