#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

int main()
{
	int numberOfSellers = 0;
	int numberOfCustomers = 0;
	int parsValue = 0;
	int maxCountOfSales = 0;
	int numberOfPrice = 0;
	int sellerCounter = 0;
	int customerCounter = 0;
	int tempParam = 0;

	std::vector<int> PricesToSell;
	std::vector<int> PricesToBuy;
	std::vector<int> ResultArray;
	std::vector<std::vector<int>> Data;

	ifstream file;
	file.open("Task1.txt");

	if (!file.is_open())
	{
		cout << "File is not opened!";
		system("pause > nul");
		return 1;
	}

	vector<string> lines;
	string line;

	ifstream ifs("Task1.txt");
	if (ifs.is_open())
	{
		while (std::getline(ifs, line))
			lines.push_back(line);
		ifs.close();
	}
	else
	{
		std::cerr << "[error]: can't open file \"INPUT.txt\"" << std::endl;
		return 1;
	}
	
	for (int i = 0; i < 3; i++)
	{
		std::istringstream iss(lines[i]);
		std::vector<std::string> args((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
		std::vector<int> Split;
		for (int i = 0; i < args.size(); i++)
		{
			Split.push_back(stoi(args[i]));
		}
		Data.push_back(Split);
	}

	numberOfSellers = Data[0][0];
	numberOfCustomers = Data[0][1];
	PricesToSell = Data[1];
	PricesToBuy = Data[2];

	for (int i = 0; i < PricesToBuy.size(); i++)
	{
		for (int j = 0; j < PricesToSell.size(); j++)
			if (PricesToSell[j] <= PricesToBuy[i]) sellerCounter++;

		for (int j = 0; j < PricesToBuy.size(); j++)
			if (PricesToBuy[i] <= PricesToBuy[j]) customerCounter++;

		if (sellerCounter >= customerCounter)
			maxCountOfSales = PricesToBuy[i] * customerCounter;
		else if (customerCounter > sellerCounter)
			maxCountOfSales = PricesToBuy[i] * sellerCounter;

		if (maxCountOfSales > tempParam)
		{
			tempParam = maxCountOfSales;
			numberOfPrice = PricesToBuy[i];
		}

		sellerCounter = 0;
		customerCounter = 0;
	}

	ResultArray.push_back(tempParam);
	ResultArray.push_back(numberOfPrice);

	cout << ResultArray[1] << ' ' << ResultArray[0] << endl;
	cout << numberOfCustomers;
	system("pause > nul");
	return 0;
}