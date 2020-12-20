#include <iostream>
#include "InsertionSort.h"
using namespace std;
#include <chrono>

InsertionSort::InsertionSort()
{
}

InsertionSort::~InsertionSort()
{
}

void InsertionSort::call(double* arr, int size)
{

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	iSort(arr, size);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
	cout << "InsertionSort took " << time << " microseconds." <<endl;
}

void InsertionSort::iSort(double* arr, int length)
{
	int j = 0;
	for(int i = 1; i < length; i++)
	{
		int temp = arr[i];
		j= i-1;
		while(j >= 0 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = temp;
	}
}
