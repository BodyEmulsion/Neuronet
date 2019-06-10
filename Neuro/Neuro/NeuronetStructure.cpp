#include "NeuronetStructure.h"



NeuronetStructure::NeuronetStructure(int n, ...) : neuronetStructure()
{
	int* numberOfNeurons = &n;
	while (*numberOfNeurons)
	{
		int numberOutputsInLayer = *numberOfNeurons;
		numberOfNeurons++;
		vector<int> thisLayer(numberOutputsInLayer);
		neuronetStructure.push_back(thisLayer);
	}
}

NeuronetStructure::~NeuronetStructure()
{
}
