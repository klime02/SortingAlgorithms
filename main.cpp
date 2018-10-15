#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int a[]);


int main() {
	//INPUT
	vector<int> a(11);
	a=(10, 54, 2, 3, 1, 7, 8, 9, 5, 4, 6);
	//Print list
	cout << "Here is your list; "<<"\n";
	cout << a<<"\n";

	//Memorize a before sorting it
	int list[sizeof(a)] = a{};

	//Insertion sort
	insertionSort(a);
	//Print sorted list
	cout << "Let sort this list:" << "\n";
	cout << a << "\n";

	//Memorize sorted list
	int sortedList[sizeof(a)] = a;


}


void insertionSort(int a[]) {
	int n = sizeof(a);
	int x;
	for (int i; i > n; i++) {
		x = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > x) {
			a[j] = a[j - 1];
			j--;
		}
		a[j]=x;
	}
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
