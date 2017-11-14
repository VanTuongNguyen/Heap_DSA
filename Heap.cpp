#include "Heap.h"
#include <iostream>
#include<queue>
using namespace std;

Heap::Heap(int maxsize)
{
	arr = new int[maxsize];
	last = -1;
	arr[0] = -1;
	maxSize = maxsize;
}


Heap::~Heap()
{
	delete[] arr;
}

void Heap::reheapUp(int childLoc)
{
	while (childLoc >= 0)
	{
		if (arr[childLoc] < arr[(childLoc - 1) / 2])
		{
			int temp = arr[childLoc];
			arr[childLoc] = arr[(childLoc - 1) / 2];
			arr[(childLoc - 1) / 2] = temp;
			childLoc = (childLoc - 1) / 2;
		}
		else break;
	}
}

void Heap:: reheapDown(int rootLoc)
{
	while (1)
	{
		int left = 2 * rootLoc + 1;
		int right = 2 * rootLoc + 2;
		int min=left;
		if (left <= last)
		{
			if (right <= last && arr[left] > arr[right])
				min = right;
			if (arr[min] < arr[rootLoc])
			{
				int temp = arr[rootLoc];
				arr[rootLoc] = arr[min];
				arr[min] = temp;
				rootLoc = min;
			}
		}
		else break;
	}
}

void Heap::printLNR(int rootLoc)
{
	if (rootLoc > last) return;
	printLNR(2 * rootLoc + 1);
	cout << arr[rootLoc]<<' ';
	printLNR(2 * rootLoc + 2);
}
bool Heap::isEmpty()
{
	if (last==-1)return true;
	else return false;
}

bool Heap::isFull()
{
	if (last == maxSize - 1) return true;
	return false;
}

int Heap::getSize()
{
	return last + 1;
}

void Heap::buildHeap(int *arrIn, int arrInSize)
{
	for (int i = 0; i < arrInSize; i++)
	{
		arr[last+1] = arrIn[i];
		last += 1;
		reheapUp(i);
	}
}
bool Heap::heapDelete()
{
	if (last==-1) return false;
	int temp = arr[0];
	arr[0] = arr[last];
	arr[last] = temp;
	last -= 1;
	reheapDown(0);
	return true;

}

bool Heap::heapInsert(int dataIn)
{
	if (last==-1) return false;
	arr[last + 1] = dataIn;
	last += 1;
	reheapUp(last);
	return true;
	
	
}

void Heap::printNLR()
{
	for (int i = 0; i < last+1; i++)
	{
		cout << arr[i] << ' ';
	}
}

queue<int> Heap::priorityQueue()
{
	queue<int> qu;
	
	int cap = last;
	for (int i = 0; i < cap+1; i++)
	{
		heapDelete();
	}
	for (int i = cap; i >= 0; i--)
	{
		qu.push(arr[i]);
	}
	return qu;
}