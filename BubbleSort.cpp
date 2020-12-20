#include <iostream>
#include "BubbleSort.h"
using namespace std;
#include <chrono>

BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::call(double* arr, int size)
{
	
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	bSort(arr, size);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
	cout << "BubbleSort took " << time << " microseconds." <<endl;
}

void BubbleSort::bSort(double* arr, int length)
{
	for(int i = 0; i < length-1; i++)
	{
		for(int j = 0; j < length-i-1; j++)
		{
			if(arr[j] > arr[j+1])
				swap(arr, j, j+1);
		}
	}
}

void BubbleSort::swap(double* arr, int n, int m)
{
	int temp = arr[n];
	arr[n] = arr[m];
	arr[m] = temp;
}
