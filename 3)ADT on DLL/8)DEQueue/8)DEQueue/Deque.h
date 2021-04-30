#pragma once
#include "DLL.h"

template<class T>
class Deque
{
private:
	DLL<T> elems;

public:
	
	Deque();

	~Deque();

	void push_front(T elem);
	/*
		Description: pushes an element to the front of the dequeue
		Best Case = Worst Case = Average Case = O(1)
	*/

	void push_back(T elem);
	/*
		Description: pushes an element to the end of the dequeue
		Best Case = Worst Case = Average Case = O(1)
	*/

	T front() const;
	/*
		Description: returns the element from the front of the dequeue
		throws: exception if the dequeue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	T back() const;
	/*
		Description: returns the element from the front of the queue
		throws: exception if the dequeue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	T pop_front();
	/*
		Description: removes and returns the element from the front of the dequeue(and returns it)
		throws: exception if the dequeue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	T pop_back();
	/*
		Description: removes and returns the element from the front of the dequeue(and returns it)
		throws: exception if the dequeue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the dequeue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

};
