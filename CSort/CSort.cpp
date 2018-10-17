#include <iostream>
#include <vector>
using namespace std;

bool sizes = true;
bool sorted = true;
bool values = true;

vector<int> insertionSort(vector<int> a) {
	int x;
	for (int i=0; i <= a.size()-1; i++) {
		x = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > x) {
			a[j] = a[j - 1];
			j--;
		}
		a[j]=x;
	}
	return a;
}

vector<int> initialPosition(vector<int> a, vector<int> sorteda) {
	//test
	equalSizes(a, sorteda, sizes);
	isItSorted(sorteda, sorted);
	equalValues(a, sorteda, values);
	
	//initialPosition
	vector<int> pos(sorteda.size());
	int j = 0;
	for (int i = 0; i <= sorteda.size()-1; i++) {
		if (i >= 1) {
			//cout << "First if, a[i]: " << sorteda[i]<< "; i-1: "<<sorteda[i - 1]<<"\n";
			if (sorteda[i] == sorteda[i - 1])j++;
			else j = 0;
		}
		while (sorteda[i] != a[j] && j<= a.size() - 1) {
			//cout << "while, j:"<<j << "\n";
			j++;
		}
		pos[i] = j;
	}
	return pos;
}

void arrayQuickSort(int arr[], int left, int right);
vector<int> quickSort(vector<int> a) {
	int** arr=new int*[a.size()];
	for (int i = 0; i < a.size(); i++)arr[i] = 0;
	for (int i = 0; i <= a.size()-1; i++)arr[i] = &a[i];
	arrayQuickSort(*arr, 0, a.size() - 1);
	for (int i = 0; i >= a.size(); i++)a[i] = *arr[i];
	return a;
}


void arrayQuickSort(int arr[], int left, int right) {
	int i = left, j = right, tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)i++;
		while (arr[j] > pivot)j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	/* recursion */
	if (left < j)arrayQuickSort(arr, left, j);
	if (i < right)arrayQuickSort(arr, i, right);
}

//Tests
void equalSizes(vector<int> a, vector<int> b,bool sizes) {
	if (a.size() != b.size())sizes = false;
}

void isItSorted(vector<int> a, bool sorted) {
	int i = 1;
	sorted = true;
	while (i <= a.size() - 1 && sorted == true) {
		if (a[i] < a[i - 1])sorted = false;
		i++;
	}
}

void equalValues(vector<int> a, vector<int> sorteda, bool values) {//This function works only is the second function is the sorted version of the first one.
	int size = 0;
	int i = 0;
	int j = 0;
	while (i <= sorteda.size() - 1 && values==true) {
		if (i >= 1) {
			if (sorteda[i] == sorteda[i - 1])j++;
			else j = 0;
		}
		while (sorteda[i] != a[j] && j <= a.size() - 1) {
			j++;
		}
		if(sorteda[i] == a[j])size++;
		if (j > a.size() - 1)values = false;
		i++;
	}
	if(size!=a.size() || size != sorteda.size())values = false;
}
