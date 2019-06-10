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

void MatrixOfWeights::save(string)
{
	//	ofstream file(adress);
//	file << matrix.size() << endl;
//	file << matrix.at(0).size() << endl;
//	for (vector<float> x : matrix)
//	{
//		for (float y : x)
//		{
//			file << y << " ";
//		}
//		file << endl;
//	}
//	file << endl;
}

void MatrixOfWeights::load(string)
{
	//	ifstream file(adress);
//	string buff;
//	int sizeX, sizeY;
//	getline(file, buff);
//	sizeX = stoi(buff);
//	getline(file, buff);
//	sizeY = stoi(buff);
//	vector<vector<float>> matrix(sizeX, vector<float>(sizeY));
//	for (vector<float>& x : matrix)
//	{
//		for (float& y : x)
//		{
//			file >> y;
//		}
//	}
//	Matrix::matrix = matrix;
}

//Matrix::Matrix(string adress)
//{
//	ifstream file(adress);
//	string buff;
//	int sizeX, sizeY;
//	getline(file, buff);
//	sizeX = stoi(buff);
//	getline(file, buff);
//	sizeY = stoi(buff);
//	vector<vector<float>> matrix(sizeX, vector<float>(sizeY));
//	for (vector<float>& x : matrix)
//	{
//		for (float& y : x)
//		{
//			file >> y;
//		}
//	}
//	Matrix::matrix = matrix;
//}

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
