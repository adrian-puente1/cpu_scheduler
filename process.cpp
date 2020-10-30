#include <iostream>
#include <vector>
#include"process.h"

// constructor
Process::Process()
{
	active = true;
	wait = 0;
	turnA = 0;
	response = 0;
	dSize = 0;
	data = NULL;
	nextProcess = this;
	prevProcess = this;
	incrementer = 0;
}

// destructor
Process::~Process()
{

}

// sets data to size of stream and sets all values equal to stream
void Process::getData(int* stream, int size)
{
	int i = 0;
	dSize = size;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = stream[i];
		//if (data[0] == 8) { std::cout << data[i] << " "; }

	}
}

// prints out data variable
void Process::readData()
{
	for (int i = 0; i < dSize; i++)
	{std::cout << data[i] << " ";}
	std::cout << std::endl;
}

// inserts process at end of process list
void Process::insertProcess(Process* headProcess)
{
	if (headProcess == NULL)
	{
		headProcess = this;
		headProcess->prevProcess = headProcess;
		headProcess->nextProcess = headProcess;
		return;
	}
	else 
	{
		this->prevProcess = headProcess->prevProcess;
		this->prevProcess->nextProcess = this;
		this->nextProcess = headProcess;
		headProcess->prevProcess = this;
	}
}

// deletes process from list
void Process::deleteProcess(Process* headProcess)
{
	if (headProcess == NULL) { std::cout << "deleteProcess found null headProcess" << std::endl; return; }
	if (headProcess->nextProcess == headProcess) 
	{ 
		if (this == headProcess) { headProcess = NULL; return; }
		else { std::cout << "deleteProcess did not match with only node" << std::endl; return; }
	}
	if (this == headProcess)
	{
		headProcess->prevProcess->nextProcess = headProcess->nextProcess;
		headProcess->nextProcess->prevProcess = headProcess->prevProcess;
		return;
	}
	Process* traverseProcess = headProcess->nextProcess;
	while (traverseProcess != headProcess)
	{
		if (traverseProcess == this)
		{
			traverseProcess->prevProcess->nextProcess = traverseProcess->nextProcess;
			traverseProcess->nextProcess->prevProcess = traverseProcess->prevProcess;
			return;
		}
		traverseProcess = traverseProcess->nextProcess;
	}
	std::cout << "deleteProcess did not find any match with badProcess" << std::endl;
	return;
}

// returns data[cpu,io] in vector
std::vector <int> Process::popTop()
{
	int k = incrementer;
	std::vector <int> topTwo;
	if ((incrementer < dSize) && (incrementer - 2) < k)
	{
		topTwo.push_back(data[incrementer]); incrementer++;
		if ((incrementer < dSize) && (incrementer - 2) < k)
		{
			topTwo.push_back(data[incrementer]); incrementer++;
			return topTwo;
		}
		else { topTwo.push_back(0); active = false; return topTwo; }// get turnaround
	}
	else { topTwo.push_back(0); topTwo.push_back(0); return topTwo; }
}