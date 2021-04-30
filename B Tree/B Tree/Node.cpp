#include "Node.h"

template <class TComp>
Node<TComp>::Node(unsigned _min_degree, bool _is_leaf): min_degree{ _min_degree }, is_leaf{_is_leaf}, nr_keys{ 0 }
{
	keys = new TComp[min_degree * 2 - 1];
	children = new Node<TComp> *[min_degree * 2];
}

//======================================================================================

template <class TComp>
void Node<TComp>::traverse(std::ostream &stream) const
{
	unsigned index = 0;
	for (index = 0; index < nr_keys; ++index)
	{
		// Traverse the subtree that has children[index] as root first, if not leaf
		if (is_leaf == false)
			children[index]->traverse(stream);
		stream << keys[index] << " ";
	}
	// There is an additional child we did not traverse
	if (is_leaf == false)
		children[index]->traverse(stream);
}

template <class TComp>
Node<TComp> *Node<TComp>::search(TComp key)
{
	// Find the first key greater than or equal to k
	// To do: change to binary search
	unsigned index = 0;
	while (index < nr_keys && key > keys[index])
		++index;

	// If we found the key, return this node 
	if (keys[index] == key)
		return this;

	// If key is not found here and this is a leaf node, return NULL 
	if (is_leaf == true)
		return NULL;

	// Recur to the appropriate child
	return children[index]->search(key);
}

//======================================================================================

template <class TComp>
void Node<TComp>::insert_non_full(TComp key)
{
	// Initialize index as the index of the rightmost element
	int index = nr_keys - 1;

	if (is_leaf == true)
	{
		// Making room for the new key and finding the position
		// Where it must be inserted
		while (index >= 0 && keys[index] > key)
		{
			keys[index + 1] = keys[index];
			--index;
		}
		// Insert the new key
		keys[index + 1] = key;
		++nr_keys;
	}
	else
	{
		// Find the child which is going to have the given key
		// To do: change to binary search
		while (index >= 0 && keys[index] > key)
			--index;

		// If the found child is full, split it
		if (children[index + 1]->nr_keys == 2 * min_degree - 1)
		{
			split_child(index + 1, children[index + 1]);

			// After the child at index + 1 is split, its middle key goes to its parent
			// and it is split into two => decide which of the two is going to have the 
			// given key

			if (keys[index + 1] < key)
				++index;
		}
		children[index + 1]->insert_non_full(key);
	}
}

template <class TComp>
void Node<TComp>::split_child(int c_index, Node<TComp> *full_node)
{
	// Allocate memory for a node which will store the keys of 'full node'
	// starting from t + 1

	Node<TComp> *z = new Node(full_node->min_degree, full_node->is_leaf);

	z->nr_keys = min_degree - 1;

	// Copy the last (min_degree - 1) keys to z
	for (unsigned index = 0; index < min_degree - 1; ++index)
		z->keys[index] = full_node->keys[index + min_degree];

	// Copy the last min_degree children of full_node to z, if not leaf
	if (full_node->is_leaf == false)
	{
		for (unsigned index = 0; index < min_degree; ++index)
			z->children[index] = full_node->children[index + min_degree];
	}

	// Update the number of keys in y
	full_node->nr_keys = min_degree - 1;

	// The current node is going to have an additional child: z
	// right after full_node
	for (int index = nr_keys; index >= c_index + 1; --index)
		children[index + 1] = children[index];

	// Link the new child to this node 
	children[c_index + 1] = z;

	// A key of full_node will move to this node.
	for (int index = nr_keys - 1; index >= c_index; --index)
		keys[index + 1] = keys[index];

	// Copy the middle key of y to this node 
	keys[c_index] = full_node->keys[min_degree - 1];

	// Increment the number of keys in this node 
	++nr_keys;
}

//======================================================================================

template class Node<int>;