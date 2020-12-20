#include <iostream>
#include <fstream>
#include <string>
#include "FileCheck.h"
using namespace std;

	FileCheck::FileCheck()
	{

	}

	FileCheck::FileCheck(string n)
	{
		getInput(n);
	}

	FileCheck::~FileCheck()
	{

	}

	double* FileCheck::getInput(string inputFile)//file input
	{
		string line;
		double temp;
		int i=0;

    	ifstream file;
    	file.open(inputFile);
        if(file.fail())//file check
        {
            cout<<"File input was invalid. Please try again."<<endl;
            inputFile = repeatInput();//rechecks if invalid
        }

    	getline(file, line);
    	temp = atof(line.c_str());
    	size = temp;
    	arr = new double[size];

    	while(getline(file, line))
    	{

    		temp = atof(line.c_str());
    		arr[i] = temp;
    		i++;
    	}
        file.close();

        return arr;
	}

	int FileCheck::getSize()
	{
		return size;
	}

	string FileCheck::repeatInput()//if incorrect file is entered
	{
		string inputFile;
		cout<<"Input name of file: "<<endl;
	    cin>>inputFile;
	    ifstream file(inputFile);
	    if(file.fail())//file check
	    {
	        cout<<"File input was invalid. Please try again."<<endl;
	        inputFile = repeatInput();
	    }
	    file.close();
	    return inputFile;
	}
