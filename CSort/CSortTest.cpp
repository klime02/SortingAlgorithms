#include<iostream>
#include<vector>
#include"CSort.h"
#include<string>

using namespace std;

int main()
{
	vector<int> TestVector;
	bool endInput = true;
	cout << "Enter the test vector: \n";
	while (endInput)
	{
		string a;
		cin >> a;
		if (a == "/")
		{
			cout << "End of vector\n";
			endInput = false;
		}
		else
		{
			int toint = stoi(a);
			TestVector.push_back(toint);
		}

	}
	cout << "Test Vector is: ";

	for (int i = 0; i < TestVector.size(); i++)
	{
		cout << TestVector[i] << " ";
	}
	cout << "\n";
	vector<int> SortedTest = insertionSort(TestVector);
	cout << "Sorted vector is: ";
	for (int i = 0; i < SortedTest.size(); i++)
	{
		cout << SortedTest[i] << " ";
	}
	cout << "\n";
	cout << "Checking initial position...\n";
	vector<int> InitialPosition = initialPosition(TestVector, SortedTest);
	cout << "Initial Position of TestVector is: ";
	for (int i = 0; i < InitialPosition.size(); i++)
	{
		cout << InitialPosition[i] << " ";
	}
	cout << "\n";
}

