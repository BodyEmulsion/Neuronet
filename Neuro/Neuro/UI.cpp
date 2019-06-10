#include "UI.h"

void UI::russianLang()
{
	SetConsoleOutputCP(1251);
}

void UI::mainMenu()
{
	UI::russianLang();
	vector<double> input;
	vector<double> trueOutput;
	string path;
	int option;
	while (cin >> option)
	{
		UI::mainMenuText();
		switch (option)
		{
		case 1:
			UI::consoleInput(input, trueOutput);
			break;
		case 2:
			UI::getFilePath(path);
			break;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}

void UI::consoleInput(vector<double>& input, vector<double>& trueOutput)
{
	int inputStr;
	cout << "Введите массив ввода: ";
	while (cin >> inputStr)
		input.push_back(inputStr);
	cin.clear();
	cout << "Введите массив правильного вывода: ";
	while (cin >> inputStr)
		trueOutput.push_back(inputStr);
	cin.clear();
}

void UI::getFilePath(string& path)
{
	cout << "Введите путь файла: ";
	cin >> path;
	ifstream file(path);
	if (file.is_open())
		cout << "Файл найден." << endl;
	else
		cout << "Ошибка." << endl;
}



void UI::mainMenuText()
{
	cout << "1. Ввод значений с консоли." << endl <<
			"2. Выбрать файл." << endl <<
			"Выберите опцию: ";
}
