#include "Matrix.h"

Matrix::Matrix() : matrix()
{
}

Matrix::Matrix(int X = 0, int Y = 0) : matrix(X, vector<double>(Y))
{
}

Matrix::~Matrix()
{
}

int Matrix::getSizeX()
{
	return matrix.size();
}

int Matrix::getSizeY()
{
	if (matrix.size() > 0)
		return matrix.at(0).size();
	else
		return 0;
}

double Matrix::getValue(int X, int Y)
{
	if(matrix.size()>X)
		if(matrix.at(X).size()>0)
			return matrix.at(X).at(Y);
}

void Matrix::setValue(int X, int Y, double value)
{
	if (matrix.size() > X)
		if (matrix.at(X).size() > 0)
			matrix.at(X).at(Y) = value;
}
