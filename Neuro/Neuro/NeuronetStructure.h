#pragma once
#include<vector>

using namespace std;

class NeuronetStructure
{
public:
	NeuronetStructure(int n, ...);
	~NeuronetStructure();
private:
	vector<int> neuronetStructure;
};

