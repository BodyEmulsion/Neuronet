#pragma once
#include "Matrix.h"
#include <random>
#include<ctime>
#include<fstream>
#include<string>

class MatrixOfWeights :
	protected Matrix
{
public:
	//MatrixOfWeights(int,int);
	~MatrixOfWeights();
	void save(string);
	void load(string);

private:

};

