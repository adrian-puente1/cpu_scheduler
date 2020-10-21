#include<iostream>
#include"process.h"

Process::Process()
{
	flag = true;
	active = true;
	wait = 0;
	turnA = 0;
	response = 0;
	dSize = 0;
	data = NULL;
}

Process::~Process()
{
	delete []data;
}

void Process::getData(int* stream, int size)
{
	int i = 0;
	dSize = size;
	data = new int[size];

	for (int i = 0; i < size; i++) // sets data to size of stream and sets all values equal to stream
	{
		data[i] = stream[i];
	}
}

void Process::readData()
{
	for (int i = 0; i < dSize; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}