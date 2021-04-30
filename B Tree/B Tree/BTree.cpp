#include "BTree.h"

template <class TComp>
BTree<TComp>::BTree(unsigned _min_degree): min_degree{ _min_degree }, root{ NULL }
{

}

template <class TComp>
void BTree<TComp>::traverse_tree(std::ostream &stream) const
{
	if (root != NULL)
		root->traverse(stream);
}

template <class TComp>
bool BTree<TComp>::search(TComp key)
{
	if (root == NULL)
		return false;
	else
		return (root->search(key) != NULL);
}

template <class TComp>
void BTree<TComp>::insert(TComp key)
{
	// If the tree is empty
	if (root == NULL)
	{
		// Allocate new root and set the given key as its first element
		root = new Node<TComp>(min_degree, true);
		root->keys[0] = key;
		root->nr_keys = 1;
	}
	// If the tree is not empty
	else
	{
		// If the root is full
		if (root->nr_keys == min_degree * 2 - 1)
		{
			// Allocate a new empty root and split the old root
			Node<TComp> *new_root = new Node<TComp>(min_degree, false);

			// Old root becomes child of new root
			new_root->children[0] = root;

			new_root->split_child(0, root);

			// Decide which child will receive the given key
			unsigned index = 0;
			if (new_root->keys[0] < key)
				++index;
			new_root->children[index]->insert_non_full(key);

			// Set the root of the tree to the new root
			root = new_root;
		}
		// If the root is not full, insert the given key normally
		else
			root->insert_non_full(key);
	}
}

template class BTree<int>;