#include<iostream>
#include"Heap.h"
#include<queue>

using namespace std;

int main()
{
	Heap maxHeap(5);
	int array[5] = { 1,2,3,4,5 };
	
	maxHeap.buildHeap(array, 5);
	maxHeap.printNLR();
	queue<int> qu = maxHeap.priorityQueue();
	
		
	
	system("pause");

}