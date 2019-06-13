#include "Interface.h"



Interface::Interface()
{
}


Interface::~Interface()
{
}

void Interface::menu()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout 
			<< "1 - save" << endl
			<< "2 - load" << endl
			<< "3 - create" << endl
			<< "4 - work" << endl
			<< "5 - learning" << endl
			<< "5 - learning wp" << endl
			<< "6 - exit" << endl;
		int temp;
		Options option;
		try
		{
			cin >> temp;
			option = static_cast<Options>(temp);
		}
		catch (const std::exception&)
		{
			cout << "Некорректный ввод!" << endl;
		}
		switch (option)
		{
		case SAVE:
			save();
			break;
		case LOAD:
			load();
			break;
		case CREATE:
			create();
			break;
		case WORK:
			work();
			break;
		case LEARNING:
			learning();
			break;
		case LEARNINGWP:
			learningWithPack();
			break;
		case EXIT:
			return;
		default:
			break;
		}
		cin.ignore();
	}
}

void Interface::save()
{
	cout << "Введите название: ";
	string adress;
	cin.ignore();
	getline(cin, adress);
	neuronet.save(adress);
}

void Interface::load()
{
	cout << "Введите название: ";
	string adress;
	cin.ignore();
	getline(cin, adress);
	neuronet.load(adress);
}

void Interface::create()
{
	int size;
	cin >> size;
	vector<int> structure(size);
	for (int &i : structure)
	{
		cin >> i;
	}
	neuronet = Neuronet(structure);
}

void Interface::work()
{
	int in;
	in = neuronet.inputSize();
	vector<double> input(in);
	for (double &i : input)
	{
		cin >> i;
	}
	vector<double> output = neuronet.calculate(input);
	cout << endl;
	for (double i : output)
	{
		cout << i << endl;
	}
}

void Interface::learning()
{
	int in, out;
	in = neuronet.inputSize();
	out = neuronet.outputSize();
	vector<double> input(in);
	vector<double> output(out);
	for (double& i : input)
	{
		cin >> i;
	}
	for (double &i : output)
	{
		cin >> i;
	}
	neuronet.learning(input, output);
	cout << "Готово!" << endl;
}

void Interface::learningWithPack()
{
	int iteration = 1000;
	int in, out, size;
	in = neuronet.inputSize();
	out = neuronet.outputSize();
	cout << "Количество пакетов" << endl;
	cin.ignore();
	cin >> size;
	vector<vector<double>> input(size, vector<double>(in));
	vector<vector<double>> output(size, vector<double>(out));
	cout << "Вводы" << endl;
	cin.ignore();
	for (vector<double>& i : input)
	{
		for (double& x : i)
		{
			cin >> x;
		}
	}
	cout << "Выводы" << endl;
	cin.ignore();
	for (vector<double>& o : output)
	{
		for (double& x : o)
		{
			cin >> x;
		}
	}
	for (int i = 0; i < iteration; i++)
	{
		for (int i = 0; i < size; i++)
		{
			neuronet.learning(input.at(i), output.at(i));
		}
	}
	//neuronet.learning(input, output);
	cout << "Готово!" << endl;
}
