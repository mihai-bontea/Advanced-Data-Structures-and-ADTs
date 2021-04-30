#pragma once
#include <iostream>
#include <string>

template <class T>
class SegmentTree
{
private:
	T *elems;
	unsigned segment_len;
	bool(*r)(const T &p1, const T &p2);

	void BuildTree(std::istream &stream, unsigned Node, unsigned Left, unsigned Right);

	void UpdateTree(unsigned Node, unsigned Left, unsigned Right, unsigned pos, T val);

	const T& QueryTree(unsigned Node, unsigned Left, unsigned Right, unsigned qA, unsigned qB) const;

public:
	SegmentTree(bool(*_r)(const T &p1, const T &p2));
	/*
		Description: constructor which receives a relation used for comparing
	*/

	~SegmentTree();
	/*
		Description: destructor, cleans up the memory
	*/

	void Read(std::istream &stream);
	/*
		Description: wrapper for building the tree from a given stream
				     the amount of elements and then the elements itself
					 should be inputed

		throws: exception if the length is negative or zero

		Best Case = Average Case = Worse Case = O(n)
	*/

	void Update(unsigned position, T value);
	/*
		Description: wrapper for UpdateTree function
					 sets the element at position to the element given

		throws: exception if position is not valid
				the array is considered to be indexed from 1

		Average Case = O(log n)
	*/

	const T& Query(unsigned qA, unsigned qB) const;
	/*
		Description: wrapper for QueryTree function
					 returns the statistic for the segment [qA, qB]

		throws: exception if qA or qB is invalid, or if qA > qB
				the array is considered to be indexed from 1

		Average Case = O(log n)
	*/

};