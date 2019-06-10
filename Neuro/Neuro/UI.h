#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class UI
{
public:
	static void russianLang();
	static void mainMenu();
	static void consoleInput(vector<double>& input, vector<double>& trueOutput);
	static void getFilePath(string& path);
	static void mainMenuText();
};

