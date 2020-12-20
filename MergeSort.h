#include <iostream>
using namespace std;

class MergeSort
{
public:
	MergeSort();
	~MergeSort();
	void merge(double arr[], int i, int m, int j);
	void call(double* arr, int size);
	void mSort(double arr[], int i, int j);

};
