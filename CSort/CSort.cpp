#include <iostream>
#include <vector>
using namespace std;

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
	for (int i = 0; i <= sorteda.size()-1; i++) {
		int j = 0;
		while (sorteda[i] != a[j]) {
			j++;
		}
		pos[i] = j;
	}
	return pos;
}
