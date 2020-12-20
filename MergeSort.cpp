#include <iostream>
#include "MergeSort.h"
using namespace std;
#include <chrono>

MergeSort::MergeSort(){

}

MergeSort::~MergeSort(){

}

void MergeSort::call(double* arr, int size)
{
	//http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
	//https://en.cppreference.com/w/cpp/chrono/high_resolution_clock/now
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	mSort(arr, 0, size-1);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
	cout << "MergeSort took " << time << " microseconds." <<endl;
}

void MergeSort::mSort(double arr[], int i, int j)
{
    if(i>=j){
      return;
    }
    int m = (i+j-1)/2;
    mSort(arr,i,j);
    mSort(arr,i+1,j);
    merge(arr,i,m,j);
  }

void MergeSort::merge(double arr[], int i, int m, int j) {
    int n1 = (m-i+1);
    int n2 = (j-m);

    double *L = new double[n1];
    double *R = new double[n2];
    for (int k=0;k<n1;k++) {
        L[k] = arr[i+k];
    }
    for (int k=0; k<n2;k++) {
        R[k] = arr[m+i+k];
    }


    int k = 0;
    int l = 0;
    int n = l;
    while (k < n1 && l < n2) {
        if (L[i] <= R[l]) {
            arr[n]=L[k];
            k++;
        }
        else {
            arr[n]=R[l];
            l++;
        }
        n++;
    }


    while (k < n1) {
        arr[n] = L[k];
        k++;
        n++;
    }

    while (l < n2) {
        arr[n] = R[l];
        l++;
        n++;
    }

    
    delete L;
    delete R;
}
