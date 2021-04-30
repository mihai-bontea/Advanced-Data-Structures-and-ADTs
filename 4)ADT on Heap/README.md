# ADTs on Heap

A heap is a hybrid between a dynamic array and a tree, as its elements are stored in a dynamic array but it can be viewed as a tree.
The tree must satisfy the **heap property**, that is, if the node P is the parent of the node C, the key associated to the node P must be greater than
or equal/less than or equal than the key associated to the node C, depending on whether it's a **max heap** or a **min heap**.
It can be used as an efficient representation for the **priority queue**. In this example, the heap is organized by a relation given by the user.
