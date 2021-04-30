#pragma once
#include <iostream>

template <class TComp>
class BTree;

template <class TComp>
class Node
{
	friend class BTree<TComp>;
private:
	TComp *keys;
	unsigned min_degree;
	Node<TComp> **children;
	unsigned nr_keys;
	bool is_leaf;

public:

	Node(unsigned _min_degree, bool _is_leaf);

	void traverse(std::ostream &stream) const;

	Node<TComp> *search(TComp key);

	void insert_non_full(TComp key);

	void split_child(int c_index, Node<TComp> *full_node);
};