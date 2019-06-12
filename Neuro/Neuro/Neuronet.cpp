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


