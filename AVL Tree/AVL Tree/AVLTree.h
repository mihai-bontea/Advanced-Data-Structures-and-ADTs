#pragma once
#include <iostream>

template <class TComp>
struct Node
{
	TComp key;
	Node<TComp> *left, *right;
	int height;

	Node(TComp key): key{key}, left{NULL}, right{NULL}, height{1}
	{

	}
};


template <class TComp>
class AVLTree
{
private:

	Node<TComp> *root;

	void postorder_deletion(Node<TComp> *node);
	/*
		Description: utility function called by the destructor to cleanup the memory
					 by doing a postorder traversal of it and deleting the nodes in
					 the process

		Best Case = Average Case = Worst Case = O(n)
	*/

	inline int maxim(const int x, const int y) const
	{
		if (x > y)
			return x;
		return y;
		//return (x > y)? x : y;
	}

	inline int get_height(Node<TComp> *node) const
	{
		if (node == NULL)
			return 0;
		return node->height;
	}

	inline int get_balance(Node<TComp> *node) const
	{
		if (node == NULL)
			return 0;
		return get_height(node->left) - get_height(node->right);
	}

	Node<TComp> *rotate_right(Node<TComp> *node);
	/*
		Description: utility function used to rotate towards right
					 the subtree having the given node as root
	*/

	Node<TComp> *rotate_left(Node<TComp> *node);
	/*
		Description: utility function used to rotate towards left
					 the subtree having the given node as root
	*/

	Node<TComp> *insert_utility(Node<TComp> *node, TComp key, bool &duplicate);
	/*
		Description: recursive utility function used to insert a key into the AVL tree
	*/

	Node<TComp> *min_value_node(Node<TComp> *node) const;
	/*
		Description: utility function used to find the minimum value node in a 
					 subtree having the given node as root
	*/

	Node<TComp> *remove_utility(Node<TComp> *node, TComp key, bool &deleted);
	/*
		Description: utility function used to delete a node containing a given key
					 from the AVL Tree
	*/

public:

	AVLTree();
	/*
		Description: the constructor for the AVL Tree, initializes the container

		Best Case = Average Case = Worst Case = O(1)
	*/

	~AVLTree();
	/*
		Description: the destructor for the AVL Tree, cleans up the memory

		Best Case = Average Case = Worst Case = O(n)
	*/

	bool search(TComp key) const;
	/*
		Description: returns true if the key appears in the AVL Tree,
					 false otherwise

		Preconditions: elements must be comparable(have the relational operators
					   implemented)

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(log n)
	*/

	bool insert(TComp key);
	/*
		Description: wrapper function, inserts the given key into the AVL Tree
					 returns true if key was inserted successfully, false if a
					 duplicate exists

		Preconditions: elements must be comparable(have the relational operators
					   implemented)

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(log n)
	*/

	bool remove(TComp key);
	/*
		Description: wrapper function, removes the given key from the AVL Tree
					 returns true if key was deleted successfully, false if the
					 given key is not found in the AVL Tree

		Preconditions: elements must be comparable(have the relational operators
					   implemented)

		Best Case = O(1)
		Average Case = O(log n)
		Worst Case = O(log n)
	*/

	bool is_empty() const;
	/*
		Description: returns true if the AVL Tree is empty, false otherwise
		Best Case = Average Case = Worst Case = O(1)
	*/
};