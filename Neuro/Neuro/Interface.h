#pragma once
#include"Neuronet.h"
#include<iostream>
using namespace std;


enum Options
{
	SAVE = 1,
	LOAD,
	CREATE,
	WORK,
	LEARNING,
	LEARNINGWP,
	EXIT
};

class Interface
{
public:
	Interface();
	~Interface();
	void menu();
	void save();
	void load();
	void create();
	void work();
	void learning();
	void learningWithPack();
private:
	Neuronet neuronet;
};

