#include <iostream>
using namespace std;

class SelectionSort
{
public:
	SelectionSort();
	~SelectionSort();
	void sSort(double* arr, int length);
	void call(double* arr, int size);
	void swap(double* arr, int n, int m);
};
