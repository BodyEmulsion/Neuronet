#include "Neuronet.h"




Neuronet::Neuronet(vector<int> neuronetStructure = vector<int>()) : matrixsOfWeights(neuronetStructure.size()-1)
{
	int X = 0;
	for (MatrixOfWeights& i : matrixsOfWeights)
	{
		i = MatrixOfWeights::MatrixOfWeights(neuronetStructure.at(X), neuronetStructure.at(X+1));
		X++;
	}
}

Neuronet::Neuronet() : matrixsOfWeights()
{
}

Neuronet::~Neuronet()
{
}
vector<double> Neuronet::calculate(vector<double> input)
{
	vector<double> result;
	vector<double> temp;
	for (MatrixOfWeights i : matrixsOfWeights)
	{
		temp = i.returnWeightedValues(input);
		input = i.returnActivatedValues(temp);
	}
	return input;
}
void Neuronet::learning(vector<double> input, vector<double> trueOutput) //реярш
{
	float learningRate = 10;
	vector<vector<double>> matrixOfMistakes = returnMatrixOfMistakes(calculate(input), trueOutput);
	vector<vector<double>> matrixOfOutputs = returnMatrixOfOutputs(input);
	vector<vector<double>> matrixOfWeightedValues = returnMatrixOfWeightedValues(matrixOfOutputs);
	for (int i = 0; i < size(); i++)
	{
		for (int x = 0; x < matrixsOfWeights.at(i).getSizeX(); x++)
		{
			for (int y = 0; y < matrixsOfWeights.at(i).getSizeY(); y++)
			{
				double temp;
				temp = matrixsOfWeights.at(i).getValue(x, y) + learningRate * matrixOfMistakes.at(i).at(y) * 
					   derivativeOfTheActivationFunction(matrixOfWeightedValues.at(i).at(y)) * matrixOfOutputs.at(i).at(x);
				matrixsOfWeights.at(i).setValue(x,y,temp);
			}
		}
	}
}
void Neuronet::save(string adress)
{
	ofstream file(adress);
	int j = 1;
	file << matrixsOfWeights.size() << endl;
	for (MatrixOfWeights i : matrixsOfWeights)
	{
		i.save(to_string(j) + adress);
		file << (to_string(j) + adress) << endl;
		j++;
	}
}
void Neuronet::load(string adress)
{
	ifstream file(adress);
	string buff;
	int sizeZ;
	getline(file, buff);
	sizeZ = stoi(buff);
	vector<MatrixOfWeights> matrixs(sizeZ);
	for (MatrixOfWeights& i : matrixsOfWeights)
	{
		getline(file, buff);
		i.load(buff);
	}
	Neuronet::matrixsOfWeights = matrixs;
}

int Neuronet::outputSize()
{
	return matrixsOfWeights.back().getSizeY();
}

int Neuronet::inputSize()
{
	return matrixsOfWeights.front().getSizeX();
}

int Neuronet::size()
{
	return matrixsOfWeights.size();
}

vector<vector<double>> Neuronet::returnMatrixOfMistakes(vector<double> output, vector<double> trueOutput) //реярш
{
	int sizeOfNeuronet = size();
	vector<vector<double>> matrixOfMistakes(sizeOfNeuronet);
	for (int i = 0; i < output.size(); i++)
	{
		matrixOfMistakes.back().push_back(trueOutput.at(i) - output.at(i));
	}
	for (int x = sizeOfNeuronet - 2; x <= 0; x++)
	{
		matrixOfMistakes.at(x) = matrixsOfWeights.at(x + 1).returnLayerMistakes(matrixOfMistakes.at(x + 1)); //реярш
	}
	return matrixOfMistakes;
}

vector<vector<double>> Neuronet::returnMatrixOfOutputs(vector<double> input) //реярш
{
	int sizeOfNeuronet = size();
	vector<vector<double>> outputMatrix(sizeOfNeuronet+1);
	outputMatrix.front() = input;
	vector<double> result;
	for (int i = 1; i < sizeOfNeuronet+1; i++)
	{
		outputMatrix.at(i) = matrixsOfWeights.at(i-1).returnWeightedValues(input);
		input = matrixsOfWeights.at(i-1).returnActivatedValues(outputMatrix.at(i));
	}
	return outputMatrix;
}

vector<vector<double>> Neuronet::returnMatrixOfWeightedValues(vector<vector<double>> matrixOfOutputs) //реярш
{
	int sizeOfNeuronet = size();
	vector<vector<double>> matrixOfWeightedValues(sizeOfNeuronet);
	for (int i = 0; i < sizeOfNeuronet; i++)
	{
		matrixOfWeightedValues.at(i) = matrixsOfWeights.at(i).returnWeightedValues(matrixOfOutputs.at(i));
	}


	return matrixOfWeightedValues;
}


