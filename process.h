#ifndef PROCESS
#define PROCESS

/*
waiting time - sum of periods a process spent waiting in the ready queue
turnaround time - the interval from the time of submission to the time of a process completion -> wait + cpu + io
response time - time from submission to first response
*/

class Process
{
	int* data;					// array with process data
	bool flag;					// if true, data[0] is CPU burst, else I/O
	bool active;				// if true, process is not completed
	int wait;					// waiting time of process
	int turnA;					// turnaround time of process
	int response;				// response time of process
	int dSize;					// size of data

public:
	Process();
	void getData(int* stream, int size);
	void readData();
	~Process();
};

#endif // !PROCESS
