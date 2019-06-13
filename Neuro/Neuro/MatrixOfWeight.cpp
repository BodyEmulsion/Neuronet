#include "MatrixOfWeight.h"



MatrixOfWeights::MatrixOfWeights(int X = 0, int Y = 0) : Matrix()
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

MatrixOfWeights::MatrixOfWeights() : Matrix()
{
}


MatrixOfWeights::~MatrixOfWeights()
{
}

vector<double> MatrixOfWeights::returnWeightedValues(vector<double> input)
{
	const int xSize = getSizeX(), ySize = getSizeY();
	vector<double> result(ySize,0);
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			result.at(y) += getValue(x,y) * input.at(x);
		}
	}
	return result;
}

vector<double> MatrixOfWeights::returnActivatedValues(vector<double> input)
{
	int size = input.size();
	vector<double> result(size);
	for (int i = 0; i < size; i++)
	{
		result.at(i) = activationFunction(input.at(i));
	}
	return result;
}

vector<double> MatrixOfWeights::returnLayerMistakes(vector<double> input)
{
	const int xSize = getSizeX(), ySize = getSizeY();
	vector<double> result(xSize,0);
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			result.at(x) += getValue(x, y) * input.at(y);
		}
	}
	return result;
}

void MatrixOfWeights::save(string adress)
{
	ofstream file(adress);
	file << matrix.size() << endl;
	file << matrix.at(0).size() << endl;
	for (vector<double> x : matrix)
	{
		for (double y : x)
		{
			file << y << " ";
		}
		file << endl;
	}
	file << endl;
}

void MatrixOfWeights::load(string adress)
{
	ifstream file(adress);
	string buff;
	int sizeX, sizeY;
	getline(file, buff);
	sizeX = stoi(buff);
	getline(file, buff);
	sizeY = stoi(buff);
	vector<vector<double>> matrix(sizeX, vector<double>(sizeY));
	for (vector<double>& x : matrix)
	{
		for (double& y : x)
		{
			file >> y;
		}
	}
	Matrix::matrix = matrix;
}

//vector<float> activationFunction(vector<float> sum)
//{
//	vector<float> newValues(sum);
//	for (float& x : newValues)
//	{
//		x = activationFunction(x);
//	}
//	return newValues;
//}
//
//vector<float> sumFunction(Matrix wightMatrix, vector<float> values)
//{
//	vector<float> sum(wightMatrix.getOutputSize(), 0);
//	for (int i = 0; i < wightMatrix.getInputSize(); i++)
//	{
//		for (int j = 0; j < wightMatrix.getOutputSize(); j++)
//		{
//			sum.at(j) += wightMatrix.matrix.at(i).at(j) * values.at(i);
//		}
//	}
//	return sum;
//}
//
//
//float dOfActivationFunction(float x)
//{
//	float resultActF = activationFunction(x);
//	return (resultActF * (1 - resultActF));
//}
//
//float activationFunction(float x)
//{
//	return (1 / (1 + exp(-(x))));
//}

double activationFunction(double x )
{
	return (1 / (1 + exp(-(x))));
}
