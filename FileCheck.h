#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileCheck{
public:
	FileCheck();
	FileCheck(string n);
	~FileCheck();
	double* getInput(string inputFile);
	string repeatInput();
	int getSize();

	double* arr;

private:
	int size;
};
