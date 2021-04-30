# AVL Tree

An AVL Tree is a self-balancing Binary Search Tree(BST). In such a tree, the difference between the heights of the left and right subtree of a node
is kept at either 0 or 1. This implies that for an AVL Tree, a node must also keep track of height in addition to the key and pointers to its children.
When an AVL Tree is no longer balanced after an insertion or a deletion, the tree is **rebalanced** to restore this property.
Rebalancing is achieved by one or more **tree rotations**. See below:

## The point of rebalancing

The principal BST operations depend on the height of the BST. An issue is that a BST can easily become *skewed*, leading to **O(n)** time complexity.
If the BST is kept balanced, the height of the tree will be log n, leading to **O(log n)** time complexity for search, insert, and delete.
