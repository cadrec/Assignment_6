#include <iostream>
using namespace std;

class BubbleSort
{
public:
	BubbleSort();
	~BubbleSort();
	void bSort(double* arr, int length);
	void call(double* arr, int size);
	void swap(double* arr, int n, int m);
};
