#include <iostream>
using namespace std;
#include "FileCheck.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"


//used for runtime tracking on all of sort.cpp files
//http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
//https://en.cppreference.com/w/cpp/chrono/high_resolution_clock/now
//microseconds used for more accurate runtime and easier to compare
//https://stackoverflow.com/questions/21856025/getting-an-accurate-execution-time-in-c-micro-seconds

int main(int argc, char const *argv[])
{
  if(argc > 1)
  {
  	double* ar;

    //filename in command line
    string inputFile = argv[1];
    FileCheck input;//calls file
    ar = input.getInput(inputFile);
    double* arr = new double[input.getSize()];

    arr = ar;

    //calls sorting algorithms
  	QuickSort quick;
  	quick.call(arr, input.getSize());
  	BubbleSort bubble;
  	bubble.call(arr, input.getSize());
  	SelectionSort selection;
  	selection.call(arr, input.getSize());
  	InsertionSort insertion;
  	insertion.call(arr, input.getSize());
    MergeSort merge;
    merge.call(arr, input.getSize());

  }
  else
  {
    cout<<"Error: Please make sure filename is entered on correct command line."<<endl;
  }
}
