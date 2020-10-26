#include<iostream>
#include<stdio.h>
#include"process.h"

int main()
{
	int i = 0;
	int k = 0;
	Process* headProcess = NULL;
	int* stream = NULL;
	Process P1, P2, P3, P4, P5, P6, P7, P8;

	int data[8][20] = { 
		{ 5, 27,  3, 31,  5, 43,  4, 18,  6, 22,  4, 26,  3, 24,  4,  0,  0,  0,  0,  0} ,
		{ 4, 48,  5, 44,  7, 42, 12, 37,  9, 76,  4, 41,  9, 31,  7, 43,  8,  0,  0,  0},
		{ 8, 33, 12, 41, 18, 65, 14, 21,  4, 61, 15, 18, 14, 26,  5, 31,  6,  0,  0,  0} ,
		{ 3, 35,  4, 41,  5, 45,  3, 51,  4, 61,  5, 54,  6, 82,  5, 77,  3,  0,  0,  0} ,
		{16, 24, 17, 21,  5, 36, 16, 26,  7, 31, 13, 28, 11, 21,  6, 13,  3, 11,  4,  0} ,
		{11, 22,  4,  8,  5, 10,  6, 12,  7, 14,  9, 18, 12, 24, 15, 30,  8,  0,  0,  0} ,
		{14, 46, 17, 41, 11, 42, 15, 21,  4, 32,  7, 19, 16, 33, 10,  0,  0,  0,  0,  0} ,
		{ 4, 14,  5, 33,  6, 51, 14, 73, 16, 87,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0} 
	};
	// create Pn process ojects and fill with data and data size
	{
		stream = data[i];				// stores address of process
		while (data[i][k] != 0) { k++; }	// finds length of data
		P1.getData(stream, k);
		k = 0;
		i++;
	
		stream = data[i];
		while (data[i][k] != 0) { k++; }
		P2.getData(stream, k);
		k = 0;
		i++;

		stream = data[i];
		while (data[i][k] != 0) { k++; }
		P3.getData(stream, k);
		k = 0;
		i++;

		stream = data[i];
		while (data[i][k] != 0) { k++; }
		P4.getData(stream, k);
		k = 0;
		i++;

		stream = data[i];
		while (data[i][k] != 0) { k++; }
		P5.getData(stream, k);
		k = 0;
		i++;

		stream = data[i];
		while (data[i][k] != 0) { k++; }
		P6.getData(stream, k);
		k = 0;
		i++;

		stream = data[i];
		while (data[i][k] != 0) { k++; }
		P7.getData(stream, k);
		k = 0;
		i++;

		stream = data[i];
		while (data[i][k] != 0) { k++; }
		P8.getData(stream, k);
		k = 0;
	}


}

