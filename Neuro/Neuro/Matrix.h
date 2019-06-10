#pragma once
//#include<iostream>
#include<vector>

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int,int);
	~Matrix();


	int getSizeX();
	int getSizeY();
	double getValue(int, int);

	void setValue(int, int, double);
	
protected:
	vector<vector<double>> matrix;
private:
};

