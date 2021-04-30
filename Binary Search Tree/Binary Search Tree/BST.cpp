#include "BST.h"

template <class TComp>
BST<TComp>::BST(): root{ NULL }
{

}

template <class TComp>
void BST<TComp>::postorder_deletion(BSTNode<TComp> *node)
{
	if (node->left != NULL)
		postorder_deletion(node->left);
	if (node->right != NULL)
		postorder_deletion(node->right);
	delete node;
}

template <class TComp>
BST<TComp>::~BST()
{
	if (root != NULL)
		postorder_deletion(root);
}

template <class TComp>
BSTNode<TComp> *BST<TComp>::search_utility(TComp key) const
{
	// We are going through the BST starting from the root
	BSTNode<TComp> *current_node = root;

	while (current_node != NULL && current_node->key != key)
	{
		// If the key we are looking for is less than the node's key,
		// we evaluate the left subtree
		if (current_node->key > key)
			current_node = current_node->left;
		// Else, we evaluate the right subtree
		else
			current_node = current_node->right;
	}

	return current_node;
}

template <class TComp>
bool BST<TComp>::search(TComp key) const
{
	return search_utility(key) != NULL;
}

template <class TComp>
void BST<TComp>::insert(TComp key)
{
	/*
		We are going to keep track of two nodes, the current and the previous
		When the current becomes NULL, a new node containing the given key will be
		created and set as either the left or right child of the previous node,
		in case the previous one is not NULL too(empty tree). If we find the exact
		key, we simply increase its frequency.
	*/
	BSTNode<TComp> *previous_node = NULL;
	BSTNode<TComp> *current_node = root;

	while (current_node != NULL)
	{
		previous_node = current_node;

		if (key == current_node->key)
		{
			current_node->elem_count++;
			return;
		}
		else if (key < current_node->key)
		{
			current_node = current_node->left;
		}
		else
		{
			current_node = current_node->right;
		}
	}

	// Previous node exists, create a new node with this key and set it as either
	// its left or right child
	if (previous_node != NULL)
	{
		BSTNode<TComp> *child = new BSTNode<TComp>(key);

		if (previous_node->key > key)
			previous_node->left = child;
		else
			previous_node->right = child;
	}
	// Empty tree, create a new node with this key and set it as root
	else
	{
		BSTNode<TComp> *child = new BSTNode<TComp>(key);
		root = child;
	}
}

template <class TComp>
BSTNode<TComp> *BST<TComp>::remove_utility(BSTNode<TComp> *node, TComp key, bool &deleted)
{
	if (node == NULL)
		return node;

	if (key < node->key)
	{
		node->left = remove_utility(node->left, key, deleted);
		return node;
	}

	else if (key > node->key)
	{
		node->right = remove_utility(node->right, key, deleted);
		return node;
	}
	else
	{
		deleted = true;
		node->elem_count--;
		if (node->elem_count == 0)
		{
			// Node with only one child or no child
			if (node->left == NULL)
			{
				BSTNode<TComp> *temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == NULL)
			{
				BSTNode<TComp> *temp = node->left;
				delete node;
				return temp;
			}
			// Node with two children: get inorder successor
			
			BSTNode<TComp> *prev = node;
			BSTNode<TComp> *current = node->right;
			// Find the leftmost leaf of the right subtree
			while (current != NULL && current->left != NULL)
			{
				prev = current;
				current = current->left;
			}

			// Copy the successor's content to this node
			node->key = current->key;
			node->elem_count = current->elem_count;

			// Delete the inorder successor

			if (prev->left != NULL && prev->left == current)
			{
				prev->left = current->right;
			}
			else
			{
				prev->right = current->right;
			}
			delete current;
		}
		return node;
	}
}

template <class TComp>
bool BST<TComp>::remove(TComp key)
{
	bool deleted = false;
	root = remove_utility(root, key, deleted);
	return deleted;
}

template <class TComp>
bool BST<TComp>::is_empty() const
{
	return root == NULL;
}

template class BST<int>;