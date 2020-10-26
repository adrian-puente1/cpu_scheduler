#include<iostream>
#include"process.h"

// constructor
Process::Process()
{
	flag = true;
	active = true;
	wait = 0;
	turnA = 0;
	response = 0;
	dSize = 0;
	data = NULL;
	nextProcess = NULL;
	prevProcess = NULL;
}

// destructor
Process::~Process()
{
	delete []data;
	delete nextProcess;
	delete prevProcess;
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
void Process::insertProcess(Process* newProcess, Process* headProcess)
{
	if (headProcess == NULL)
	{
		headProcess = newProcess;
		headProcess->prevProcess = headProcess;
		headProcess->nextProcess = headProcess;
		return;
	}
	else 
	{
		newProcess->prevProcess = headProcess->prevProcess;
		newProcess->prevProcess->nextProcess = newProcess;
		newProcess->nextProcess = headProcess;
		headProcess->prevProcess = newProcess;
	}
}

// deletes process from list
void Process::deleteProcess(Process* badProcess, Process* headProcess)
{
	if (headProcess == NULL) { std::cout << "deleteProcess found null headProcess" << std::endl; return; }
	if (headProcess->nextProcess == headProcess) 
	{ 
		if (badProcess == headProcess) { headProcess = NULL; return; }
		else { std::cout << "deleteProcess did not match with only node" << std::endl; return; }
	}
	if (badProcess == headProcess)
	{
		headProcess->prevProcess->nextProcess = headProcess->nextProcess;
		headProcess->nextProcess->prevProcess = headProcess->prevProcess;
		return;
	}
	Process* traverseProcess = headProcess->nextProcess;
	while (traverseProcess != headProcess)
	{
		if (traverseProcess == badProcess)
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