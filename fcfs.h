#ifndef FCFS
#define FCFS

struct Node
{
public:
	Node();
	~Node();
	void addSauce(Process* process);		// add node
	void delEminem(Process* process);		// delete node

private:
	Process mozzSticc;						// data
	Node* marinara;							// next pointer
	Node* willTheRealDataPleaseStandUp;		// previous pointer
};

#endif // !FCFS
