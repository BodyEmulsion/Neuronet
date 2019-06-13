#pragma once
#include "Matrix.h"
#include"Neuronet.h"
class MatrixOfMistakes :
	protected Matrix
{
public:
	MatrixOfMistakes(Neuronet,vector<double>, vector<double>);
	MatrixOfMistakes();
	~MatrixOfMistakes();
};

