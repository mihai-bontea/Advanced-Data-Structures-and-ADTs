#pragma once
#include <iostream>
#include "Node.h"

template <class TComp>
class Node;

template <class TComp>
class BTree
{
private:
	unsigned min_degree;
	Node<TComp> *root;

public:

	BTree(unsigned _min_degree);

	void traverse_tree(std::ostream &stream) const;

	bool search(TComp key);
	/*
		Description: searches in the B Tree for the given key

		Disk pages accessed: O(log n)
		Total CPU time: O(t *log n) where t is the minimum degree
	*/

	void insert(TComp key);
	/*
		Description: inserts the given key into the B Tree

		Disk pages accessed: O(log n)
		Total CPU time: O(t *log n) where t is the minimum degree
	*/
};

