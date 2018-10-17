#include<iostream>
#include<vector>
#include"CSort.h"
#include<string>
#include<algorithm>
#include<random>

using namespace std;



vector<int> RandVector(int n)
{
	vector<int> tempvector;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, n);
	for (int i = 0; i < n; i++)
	{
		int number = distribution(generator);
		tempvector.push_back(number);
	}
	return tempvector;
}

void PassTestOutput(string fname, string tdn)
{
	cout << "Test " << fname << " using " << tdn << " PASSED\n";
}

void FailTestOutput(string fname, string tdn)
{
	cout << "Test " << fname << " using " << tdn << " FAILED\n";
}

void EqualityTestInsertion(vector<int> TestVector, string tdn)
{
	string fname = "Equality Test (Insertion Sort)";
	vector<int> tempvector = TestVector;
	sort(tempvector.begin(), tempvector.end());
	vector<int> CustomSort = insertionSort(TestVector);
	if (tempvector == CustomSort)
	{
		PassTestOutput(fname, tdn);
	}
	else
	{
		FailTestOutput(fname, tdn);
	}
}

void EqualityTestQuicksort(vector<int> TestVector, string tdn)
{
	string fname = "Equality Test (Quicksort)";
	vector<int> tempvector = TestVector;
	sort(tempvector.begin(), tempvector.end());
	vector<int> CustomSort = quickSort(TestVector);
	if (tempvector == CustomSort)
	{
		PassTestOutput(fname, tdn);
	}
	else
	{
		FailTestOutput(fname, tdn);
	}
}

void IniPosTestInsertionSort(vector<int> TestVector, string tdn)
{
	string fname = "Initial Position Test (Insertion Sort)";
	vector<int> tempvector = insertionSort(TestVector);
	vector<int> tempinpos = initialPosition(TestVector, tempvector);
	bool validsort = true;
	for (int i = 0; i < TestVector.size(); i++)
	{
		if (TestVector[tempinpos[i]] != tempvector[i])
		{
			validsort = false;
			break;
		}
	}
	if (validsort)
	{
		PassTestOutput(fname, tdn);
	}
	else
	{
		FailTestOutput(fname, tdn);
	}

}


int main()
{
	// Test vector data
	vector<int> TD0{ 10,9,8,7,6,5,4,3,2,1 };
	vector<int> TD1{ 0,1,-1,2,-2,3,-3,4,-4,5,-5 };
	vector<int> TD2{ 5,5,3,3,4,4,2,2,1,1,0 };
	vector<int> TD3{};
	vector<int> TD4{ 0,0,0,0,0,0,0,0,0,0 };
	vector<int> TD5 = RandVector(50000);

	//Begin Testing
	EqualityTestInsertion(TD0, "TD0");
	EqualityTestInsertion(TD1, "TD1");
	EqualityTestInsertion(TD2, "TD2");
	//EqualityTestInsertion(TD3, "TD3");
	EqualityTestInsertion(TD4, "TD4");
	EqualityTestInsertion(TD5, "TD5");
	return 0;
}