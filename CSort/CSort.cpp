#include <iostream>
#include <vector>
using namespace std;

bool sizes = true;
bool sorted = true;
bool basic = true;

void arrayQuickSort(int arr[], int left, int right);
void arrayQuickSortIn(int arr[], int bas[], int left, int right);

void equalSizes(vector<int> a, vector<int> b);
void isItSorted(vector<int> a);
void isItBasic(vector<int> a);

void testResultBS();

//Insertion sort
void insertionSort(vector<int>& a) {
	//Sort
	int x;
	for (int i = 0; i <= a.size() - 1; i++) {
		x = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > x) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;
	}
	//Sort test
	isItSorted(a);
	if (sorted == false) {
		cout << "The array has not been well sorted!" << "\n";
		vector<int> empty(0);
		a= empty;
	}
}
//Initial sort with initial position
void insertionSort(vector<int>& a, vector<int>& pos) {
	//Basic array test
	isItBasic(pos);
	//Sizes test
	equalSizes(a, pos);
	//Reaction to tests
	if (sizes == false||basic==false) {
		testResultBS();
		vector<int> empty(0);
		a= empty;
		return;
	}
	//Sort
	int x, posX;
	for (int i = 0; i <= a.size() - 1; i++) {
		x = a[i]; posX = pos[i];
		int j = i;
		while (j > 0 && a[j - 1] > x) {
			a[j] = a[j - 1]; pos[j] = pos[j - 1];
			j--;
		}
		a[j] = x; pos[j] = posX;
	}
	//Sort test
	isItSorted(a);
	if (sorted == false) {
		cout << "The array has not been well sorted!" << "\n";
		vector<int> empty(0);
		a = empty; pos = empty;
	}
}

//Quick sort
void quickSort(vector<int>& a) {
	int n = a.size();
	//processing vector to array
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)arr[i] = &a[i];

	//Sort
	arrayQuickSort(*arr,0, n - 1);
	for (int i = 0; i >= n; i++)a[i] = *arr[i];

	//Sort test
	isItSorted(a);
	if (sorted == false) {
		cout << "The array has not been well sorted!" << "\n";
		vector<int> empty(0);
		a = empty;
	}
}
void arrayQuickSort(int arr[], int left, int right) {
	int i = left, j = right, tmp, posTemp;
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

//Quick sort with initial position
void quickSort(vector<int>& a, vector<int>& pos) {
	//Basic array test
	isItBasic(pos);
	//Sizes test
	equalSizes(a, pos);
	//Reaction to tests
	if (sizes == false || basic == false) {
		testResultBS();
		vector<int> empty(0);
		a = empty;
		return;
	}
	//processing vector to array
	int n = a.size();
	int** arr = new int*[n];

	for (int i = 0; i < n; i++)arr[i] = &a[i];
	//basicArray
	int** posArr = new int*[n];
	for (int i = 0; i < n; i++)posArr[i] = &pos[i];
	//Sort
	arrayQuickSortIn(*arr, *posArr, 0, n - 1);
	for (int i = 0; i >= n; i++)a[i] = *arr[i];
	for (int i = 0; i >= n; i++)pos[i] = *posArr[i];

	//Sort test
	isItSorted(a);
	if (sorted == false) {
		cout << "The array has not been well sorted!" << "\n";
		vector<int> empty(0);
		a = empty; pos = empty;
	}
}
void arrayQuickSortIn(int arr[], int pos[], int left, int right) {
	int i = left, j = right, tmp, posTemp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)i++;
		while (arr[j] > pivot)j--;
		if (i <= j) {
			tmp = arr[i]; posTemp = pos[i];
			arr[i] = arr[j]; pos[i] = pos[j];
			arr[j] = tmp; pos[j] = posTemp;
			i++;
			j--;
		}
	}
	/* recursion */
	if (left < j)arrayQuickSortIn(arr, pos, left, j);
	if (i < right)arrayQuickSortIn(arr, pos, i, right);
}

//Usefull functions
vector<int> basicVector(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i;
	}
	return v;
}
void printVector(vector<int> v) {
	for (int i = 0; i <= v.size() - 1; i++)cout << v[i] << " ";
	cout << "\n";
}

//Tests
void equalSizes(vector<int> a, vector<int> b) {
	sizes = true;
	if (a.size() != b.size())sizes = false;
}
void isItSorted(vector<int> a) {
	sorted = true;
	int i = 1;
	while (i < a.size() && sorted == true) {
		if (a[i] < a[i - 1])sorted = false;
		i++;
	}
}
void isItBasic(vector<int> a) {//This function works only is the second function is the sorted version of the first one.
	basic = true;
	if (a[0] != 0)basic = false;
	int i = 1;
	while (basic == true && i < a.size()) {
		if (a[i] != a[i - 1]+1)basic = false;
		i++;
	}
}

//Print after tests
void testResultBS() {
	if (basic == false)cout << "Your basic array is not really a basic array, sorry!" << "\n";
	if (sizes == false)cout << "The array and the basic array are not the same size!" << "\n";
}
