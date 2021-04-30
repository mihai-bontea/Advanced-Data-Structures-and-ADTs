#include "AVLTree.h"

template <class TComp>
AVLTree<TComp>::AVLTree(): root{NULL}
{

}

template <class TComp>
void AVLTree<TComp>::postorder_deletion(Node<TComp> *node)
{
	if (node->left != NULL)
		postorder_deletion(node->left);
	if (node->right != NULL)
		postorder_deletion(node->right);
	delete node;
}

template <class TComp>
AVLTree<TComp>::~AVLTree()
{
	if (root != NULL)
		postorder_deletion(root);
}

template <class TComp>
bool AVLTree<TComp>::search(TComp key) const
{
	// We are going through the AVL Tree starting from the root
	Node<TComp> *current_node = root;

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

	return current_node != NULL;
}

template <class TComp>
Node<TComp> *AVLTree<TComp>::rotate_right(Node<TComp> *node)
{
	// Initialize
	Node<TComp> *new_root = node->left;
	Node<TComp> *lr_child = new_root->right;

	// Rotate
	new_root->right = node;
	node->left = lr_child;

	// Update heights
	lr_child->height = maxim(get_height(lr_child->left), get_height(lr_child->right)) + 1;
	node->height = maxim(get_height(node->left), get_height(node->right)) + 1;
	new_root->height = maxim(get_height(new_root->left), get_height(new_root->right)) + 1;

	return new_root;
}

template <class TComp>
Node<TComp> *AVLTree<TComp>::rotate_left(Node<TComp> *node)
{
	// Initialize
	Node<TComp> *new_root = node->right;
	Node<TComp> *rl_child = new_root->left;

	// Rotate
	new_root->left = node;
	node->right = rl_child;

	// Update heights
	node->height = maxim(get_height(node->left), get_height(node->right)) + 1;
	new_root->height = maxim(get_height(new_root->left), get_height(new_root->right)) + 1;

	return new_root;
}

template <class TComp>
Node<TComp> *AVLTree<TComp>::insert_utility(Node<TComp> *node, TComp key, bool &duplicate)
{
	// Initially, find the leaf position to which the new node would belong
	if (node == NULL)
		return new Node<TComp>(key);

	// Go down the left subtree
	if (key < node->key)
		node->left = insert_utility(node->left, key, duplicate);

	// Go down the right subtree
	else if (key > node->key)
		node->right = insert_utility(node->right, key, duplicate);

	// Mark that a duplicate key exists
	else
	{
		duplicate = true;
		return node;
	}

	// Update the height of this node
	node->height = maxim(get_height(node->left), get_height(node->right)) + 1;

	// Check if the node became unbalanced as a result of this insertion
	int balance = get_balance(node);

	// Unbalanced case 1: Left Left case
	if (balance > 1 && key < node->left->key)
		return rotate_right(node);

	// Unbalanced case 2: Right Right case
	if (balance < -1 && key > node->right->key)
		return rotate_left(node);

	// Unbalanced case 3: Left Right case
	if (balance > 1 && key > node->left->key)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	// Unbalanced case 4: Right Left case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	
	return node;
}

template <class TComp>
bool AVLTree<TComp>::insert(TComp key)
{
	bool duplicate = false;
	root = insert_utility(root, key, duplicate);
	return !duplicate;
}

template <class TComp>
bool AVLTree<TComp>::is_empty() const
{
	return root == NULL;
}

template <class TComp>
Node<TComp> *AVLTree<TComp>::min_value_node(Node<TComp> *node) const
{
	Node<TComp> *current_node = node;

	while (current_node->left != NULL)
		current_node = current_node->left;

	return current_node;
}

template <class TComp>
Node<TComp> *AVLTree<TComp>::remove_utility(Node<TComp> *node, TComp key, bool &deleted)
{
	// Initially, find the node to be deleted
	if (node == NULL)
		return node;

	// Go down the left subtree
	if (key < node->key)
		node->left = remove_utility(node->left, key, deleted);

	// Go down the right subtree
	else if (key > node->key)
		node->right = remove_utility(node->right, key, deleted);

	// Else, mark that the key was found, and delete the node
	else
	{
		deleted = true;

		// Node with no children or one child
		if (node->left == NULL || node->right == NULL)
		{
			Node<TComp> *aux_node = node->left ? node->left : node->right;

			// No children
			if (aux_node == NULL)
			{
				aux_node = node;
				node = NULL;
			}
			else
				*node = *aux_node;

			delete aux_node;
		}
		// Node with two children: get inorder successor
		else
		{
			Node<TComp> *aux_node = min_value_node(node);

			// Copy the inorder successor's data
			node->key = aux_node->key;

			// Delete the inorder successor
			bool n;
			node->right = remove_utility(node->right, aux_node->key, n);
		}
	}

	// If we just removed the root, return the node(NULL)
	if (node == NULL)
		return node;

	// Update the height of the node
	node->height = maxim(get_height(node->left), get_height(node->right)) + 1;

	// Check if the node became unbalanced
	int balance = get_balance(node);

	// Left Left case
	if (balance > 1 && get_balance(node->left) >= 0)
		return rotate_right(node);

	// Left Right case
	if (balance > 1 && get_balance(node->left) < 0)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	// Right Right case
	if (balance < -1 && get_balance(node->right) <= 0)
		return rotate_left(node);

	// Right Left case
	if (balance < -1 && get_balance(node->right) > 0)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}

	return node;
}

template <class TComp>
bool AVLTree<TComp>::remove(TComp key)
{
	bool deleted = false;
	root = remove_utility(root, key, deleted);
	return deleted;
}

template class AVLTree<int>;
