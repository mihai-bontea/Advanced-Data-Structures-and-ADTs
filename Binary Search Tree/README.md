# Binary Search Tree(BST)

A binary search tree, or ordered binary tree, is a container which stores items in an ordered fashion. The name comes from the fact that after a comparison
with a node, about half of the tree elements(in an ideal case) can be skipped, similarly to applying a binary search on a sorted aray. As a consequence,
the average time complexity of search, insert and delete is **O(log n)**. However, it may degenerate, leading to a worst case time complexity of **O(n)**
(ends up having a structure similar to a linked list). **Balanced** search trees aim to resolve this shortcoming.

In order for a binary tree to be considered a binary search tree, the following properties must be satisfied:

* All the keys found in the left subtree rooted in a node have strictly lesser keys than the node's

* All the keys found in the right subtree rooted in a node have strictly greater keys than the node's

* The left and right subtrees of any given node must also be binary search trees

As a consequence, duplicate keys shouldn't exist in a binary search tree. However, in practice this limitation might be an inconvenience. In this
example, each node has a key and a frequency associated to it, in order to satisfy those rules and also make duplicate keys possible. It is also
templated, allowing different types of keys, as long as the relational operators are implemented for those types.

## Uses

A binary search tree is a fundamental data structure, and it can be used as a representation for sets, bags or maps.

![Binary_search_tree svg](https://user-images.githubusercontent.com/51800513/65818794-bfb8d080-e21d-11e9-8bf9-25b77b7dc6c3.png)


## Acknowledgments

https://en.wikipedia.org/wiki/Binary_search_tree

-picture