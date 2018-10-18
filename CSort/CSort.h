#ifndef CSort
#define CSort
#include<vector>
using namespace std;

void insertionSort(vector<int>& a);
void insertionSort(vector<int>& a, vector<int>& pos);
void quickSort(vector<int>& a);
void quickSort(vector<int>& a, vector<int>& pos);

vector<int> basicVector(int n);
void printVector(vector<int> v);
#endif
