#include<iostream>
#include<vector>
#include"CSort.h"
#include<string>
#include<algorithm>
#include<random>
#include<chrono>

using namespace std;
using namespace std::chrono;


//Fills a vector of size n with random integers in range 0-n
vector<int> RandVector(int n)
{
	vector<int> tempvector;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(-n/2, n/2);
	for (int i = 0; i < n; i++)
	{
		int number = distribution(generator);
		tempvector.push_back(number);
	}
	return tempvector;
}


void PassTestOutput(string fname, string tdn)
{
	cout << fname << " using " << tdn << " PASSED\n";
}

void FailTestOutput(string fname, string tdn)
{
	cout << fname << " using " << tdn << " FAILED\n";
}

void EqualityTestInsertion(vector<int> TestVector, string tdn)
{
	string fname = "Equality Test (Insertion Sort)";
	vector<int> tempvector = TestVector;
	sort(tempvector.begin(), tempvector.end());
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	vector<int> CustomSort = insertionSort(TestVector);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	if (tempvector == CustomSort)
	{
		PassTestOutput(fname, tdn);
		auto duration = duration_cast<microseconds>(t2 - t1).count();
		cout << "Duration: " << duration << " microseconds" << "\n";
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
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	vector<int> CustomSort = quickSort(TestVector);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	if (tempvector == CustomSort)
	{
		PassTestOutput(fname, tdn);
		auto duration = duration_cast<microseconds>(t2 - t1).count();
		cout << "Duration: " << duration << " microseconds" << "\n";
	}
	else
	{
		FailTestOutput(fname, tdn);
	}
}

//Initial Position funciton test - only works with stable sorting algorithms
void IniPosTestInsertionSort(vector<int> TestVector, string tdn)
{
	string fname = "Initial Position Test (Insertion Sort)";
	vector<int> tempvector = insertionSort(TestVector);
	vector<int> tempinpos = initialPosition(TestVector, tempvector);
	bool validsort = true;
	for (unsigned int i = 0; i < TestVector.size(); i++)
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

void IniPosInsertionBadData(vector<int> v1, vector<int> v2)
{
	string fname = "Initial Position Test (Insertion Sort) - Bad Data";
	string tdn = "Bad Data";
	vector<int> emptyvector{};
	vector<int> tempvector = initialPosition( v1, v2 );
	if (tempvector == emptyvector)
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
	vector<vector<int>> alldata;
	vector<int> TD0{ 10,9,8,7,6,5,4,3,2,1 };
	alldata.push_back(TD0);
	vector<int> TD1{ 0,1,-1,2,-2,3,-3,4,-4,5,-5 };
	alldata.push_back(TD1);
	vector<int> TD2{ 5,5,3,3,4,4,2,2,1,1,0 };
	alldata.push_back(TD2);
	vector<int> TD3{ 1,1,2 };
	alldata.push_back(TD3);
	vector<int> TD4{ 0,0,0,0,0,0,0,0,0,0 };
	alldata.push_back(TD4);
	vector<int> TD5 = RandVector(100);
	alldata.push_back(TD5);

	//Begin Testing - Insertion Sort
	for (unsigned int i = 0; i < alldata.size(); i++)
	{
		string tdn = "TD" + to_string(i);
		EqualityTestInsertion(alldata[i], tdn);
	}
	//Begin Testing - Quicksort
	for (unsigned int i = 0; i < alldata.size(); i++)
	{
		string tdn = "TD" + to_string(i);
		EqualityTestQuicksort(alldata[i], tdn);
	}

	//Begin Testing - Initial Position Insertion Sort
	for (unsigned int i = 0; i < alldata.size(); i++)
	{
		string tdn = "TD" + to_string(i);
		IniPosTestInsertionSort(alldata[i], tdn);
	}

	//Bad Data
	vector<vector<int>> BadData;
	vector<int> BD0 = { 2,4,6,5,7,8 };
	BadData.push_back(BD0);
	vector<int> BD1 = { 2,4,6,5,8 };
	BadData.push_back(BD1);

	//Bad Data Testing
	for (unsigned int i = 0; i < BadData.size()-1; i++)
	{
		IniPosInsertionBadData(BadData[i], BadData[i + 1]);
	}
	return 0;
}