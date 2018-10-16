#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> a);
vector<int> initialPosition(vector<int> a, vector<int> sorteda);


int main() {
	//INPUT
	vector<int> array(11);
	array = { 2,2, 2, 3, 1, 7, 8, 9, 5, 4, 6,1 };
	//Print array
	cout << "Here is your array: ";
	for (int i=0; i <= array.size()-1;i++) {
		cout << array[i] << " ";
	}
	cout << "\n";

	//New array
	vector<int> sorted_array(array.size());
	cout<< "Let sort this list: ";
	//Sort array and store it in sorted_array
	sorted_array = insertionSort(array);                                                  
	//Print sorted_array
	for (int i = 0; i <= sorted_array.size() - 1; i++) {
		cout << sorted_array[i] << " ";
	}
	cout << "\n";
	
	//Initial position
	vector<int> pos(array.size());
	cout << "Here are the initial positions: ";
	//Find the initial positions of the sorted array elements
	pos = initialPosition(array, sorted_array);
	//Print initial positions
	for (int i = 0; i <= pos.size() - 1; i++) {
		cout << pos[i] << " ";
	}	
	cout << "\n";

	return 0;
}


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
	vector<int> pos(sorteda.size());
	int j = 0;
	for (int i = 0; i <= sorteda.size()-1; i++) {
		if (i >= 1) {
			//cout << "First if, a[i]: " << sorteda[i]<< "; i-1: "<<sorteda[i - 1]<<"\n";
			if (sorteda[i] == sorteda[i - 1])j++;
			else j = 0;
		}
		while (sorteda[i] != a[j]) {
			//cout << "while, j:"<<j << "\n";
			j++;
		}
		pos[i] = j;
	}
	return pos;
}

//New
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
