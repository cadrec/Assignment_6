#include <iostream>
#include "SelectionSort.h"
using namespace std;
#include <chrono>

SelectionSort::SelectionSort()
{
}

SelectionSort::~SelectionSort()
{
}

void SelectionSort::call(double* arr, int size)
{

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	sSort(arr, size);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
	cout << "SelectionSort took " << time << " microseconds." <<endl;
}

void SelectionSort::sSort(double* arr, int length)
{
	for(int i = 0; i < length-1; i++)
	{
		int min = i;
		for(int j = i+1; j < length; j++)
		{
			if(arr[j] > arr[min])
				min = j;
			swap(arr, min, i);
		}
	}
}

void SelectionSort::swap(double* arr, int n, int m)
{
	int temp = arr[n];
	arr[n] = arr[m];
	arr[m] = temp;
}
