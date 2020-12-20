#include <iostream>
using namespace std;

class QuickSort
{
public:
	QuickSort();
	~QuickSort();
	void qSort(double* arr, int low, int high);
	void call(double* arr, int size);
	int partition(double* arr, int low, int high);
};
