#pragma once
#include <iostream>

template <class TComp>
struct BSTNode
{
	TComp key;
	unsigned elem_count;

	BSTNode *left, *right;

	BSTNode(TComp key) : key{ key }, elem_count{ 1 }, left{ NULL }, right{ NULL }
	{

	}
};


template <class TComp>
class BST
{
private:

	BSTNode<TComp> *root;

	void postorder_deletion(BSTNode<TComp> *node);
	/*
		Description: utility function called by the destructor to cleanup the memory
					 by doing a postorder traversal of it and deleting the nodes in
					 the process

		Best Case = Average Case = Worst Case = O(n)
	*/

	BSTNode<TComp> *search_utility(TComp key) const;
	/*
		Description: utility function, returns the pointer to the node containing
					 the given key, or NULL if it isn't found

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(n)
	*/

	BSTNode<TComp> *remove_utility(BSTNode<TComp> *node, TComp key, bool &deleted);
	/*
		Description: utility function, used for deleting

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(n)
	*/

public:

	BST();
	/*
		Description: the constructor for the BST, initializes the container

		Best Case = Average Case = Worst Case = O(1)
	*/

	~BST();
	/*
		Description: the destructor for the BST, cleans up the memory

		Best Case = Average Case = Worst Case = O(n)
	*/

	bool search(TComp key) const;
	/*
		Description: returns true if the key appears in the BST,
					 false otherwise

		Preconditions: elements must be comparable(have the relational operators
					   implemented)

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(n)
	*/

	void insert(TComp key);
	/*
		Description: inserts the given key into the BST

		Preconditions: elements must be comparable(have the relational operators
					   implemented)

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(n)
	*/

	bool remove(TComp key);
	/*
		Description: removes one instance of the given key from the BST

		Preconditions: elements must be comparable(have the relational operators
					   implemented)

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(n)
	*/

	bool is_empty() const;
	/*
		Description: returns true if the BST is empty, false otherwise

		Best Case = Average Case = Worst Case = O(1)
	*/
};
