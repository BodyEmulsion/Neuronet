#include "MatrixOfWeight.h"



MatrixOfWeights::MatrixOfWeights(int X = 0, int Y = 0) : Matrix(X, Y)
{
	int randomizedNumber1 = 10;
	int randomizedNumber2 = 1000;
	srand(time(0));
	for (vector<double>& x : matrix)
		for (double& y : x)
			y = static_cast<float>(rand() % randomizedNumber1 /
				static_cast<float>(randomizedNumber1)) + 
			    static_cast<float>(rand() % randomizedNumber2 /
				static_cast<float>(randomizedNumber2)) - 1;

}


MatrixOfWeights::~MatrixOfWeights()
{
}
