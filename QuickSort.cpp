#include <iostream>
#include "QuickSort.h"
using namespace std;
#include <chrono>

//source https://stackoverflow.com/questions/21856025/getting-an-accurate-execution-time-in-c-micro-seconds
//for microseconds

QuickSort::QuickSort()
{
}

QuickSort::~QuickSort()
{
}

void QuickSort::call(double* arr, int size)
{
	//http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
	//https://en.cppreference.com/w/cpp/chrono/high_resolution_clock/now
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	qSort(arr, 0, size-1);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
	cout << "QuickSort took " << time << " microseconds." <<endl;
}

void QuickSort::qSort(double* arr, int low, int high)
{
	if(low < high)
	{
		int pivot = partition(arr, low, high);

		qSort(arr, low, pivot-1);
		qSort(arr, pivot+1, high);
	}
}


int QuickSort::partition(double* arr, int low, int high)
{
	double temp;
	double pivot = arr[high];

	int n = low - 1;

	for(int i = low; i <= high-1; i++)
	{
		if(arr[i] <= pivot)
		{
			n++;
			temp = arr[n];
			arr[n] = arr[i];
			arr[i] = temp;
		}
	}
	n++;
	temp = arr[n];
	arr[n] = arr[high];
	arr[high] = temp;
	return n;
}
