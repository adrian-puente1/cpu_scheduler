#include <iostream>
#include <stdio.h>
#include <vector>
#include "process.h"

const int numOfProcesses = 8;
const int arrWidth = 20;

// fills processPtr indices with data
void setProcesses(Process* processPtr[], int(*data)[arrWidth])
{
	int i = 0, k = 0;
	for (i = 0; i < numOfProcesses; i++)
	{
		while (data[i][k] != 0) { k++; }
		processPtr[i]->getData(data[i], k);
		k = 0;
	}
};

int main()
{
	int i = 0;
	std::vector <int> cpuIO;
	Process P1, P2, P3, P4, P5, P6, P7, P8;
	Process* processPtr[] = { &P1,&P2,&P3,&P4,&P5,&P6,&P7,&P8 };
	Process* headProcess = &P1;
	int data[numOfProcesses][arrWidth] = {
		{ 5, 27,  3, 31,  5, 43,  4, 18,  6, 22,  4, 26,  3, 24,  4,  0,  0,  0,  0,  0},// 15
		{ 4, 48,  5, 44,  7, 42, 12, 37,  9, 76,  4, 41,  9, 31,  7, 43,  8,  0,  0,  0},// 17
		{ 8, 33, 12, 41, 18, 65, 14, 21,  4, 61, 15, 18, 14, 26,  5, 31,  6,  0,  0,  0},// 17
		{ 3, 35,  4, 41,  5, 45,  3, 51,  4, 61,  5, 54,  6, 82,  5, 77,  3,  0,  0,  0},// 17
		{16, 24, 17, 21,  5, 36, 16, 26,  7, 31, 13, 28, 11, 21,  6, 13,  3, 11,  4,  0},// 19
		{11, 22,  4,  8,  5, 10,  6, 12,  7, 14,  9, 18, 12, 24, 15, 30,  8,  0,  0,  0},// 17
		{14, 46, 17, 41, 11, 42, 15, 21,  4, 32,  7, 19, 16, 33, 10,  0,  0,  0,  0,  0},// 15
		{ 4, 14,  5, 33,  6, 51, 14, 73, 16, 87,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0} // 11
	}; int(*dPtr)[arrWidth] = &data[0];
	
	setProcesses(processPtr, dPtr);
	for (i = 1; i < (sizeof(processPtr) / sizeof(processPtr[0])); i++) 
	{ processPtr[i]->insertProcess(headProcess); }
	
	cpuIO = processPtr[7]->popTop();
	std::cout << cpuIO.at(1) << std::endl;

	//while()
}