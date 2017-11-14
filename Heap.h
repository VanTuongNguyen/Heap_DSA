#ifndef _HEAP
#define _HEAP
#include<queue>

class Heap
{
public:
	Heap(int maxsize);
	~Heap();
	void buildHeap(int *arrIn, int arrInSize);
	bool heapInsert(int dataIn);
	bool heapDelete();
	int getSize();
	bool isFull();
	bool isEmpty();
	void printLNR(int rootLoc);
	void printNLR();
	std::queue<int> priorityQueue();
private:
	void reheapUp(int childLoc);
	void reheapDown(int rootLoc);
	int* arr;
	int last;
	int maxSize;
};
#endif
