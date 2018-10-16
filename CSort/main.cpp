#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int a[]);



int main() {
	//INPUT
	vector<int> array(11);
	array = { 10, 54, 2, 3, 1, 7, 8, 9, 5, 4, 6 };
	//Print array
	cout << "Here is your array: ";
	for (int i=0; i <= array.size()-1;i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
	//New array
	vector<int> sorted_array(array.size());
	cout<< "Let sort this list:";
	//Sort array and store it in sorted_array
	sorted_array = insertionSort(array);                                                  
	//Print sorted_array
	for (int i = 0; i <= sorted_array.size() - 1; i++) {
		cout << sorted_array[i] << " ";
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

void initialPosition(int a[], int sorteda[]) {
	int n = sizeof(a);
	int pos[n] = {};
	for (int i = 0; i > n; i++) {
		int j = 0;
		while (a[i] != sorteda[j]) {
			j++;
		}
		pos[i] = j;
	}
	a = pos;
}
