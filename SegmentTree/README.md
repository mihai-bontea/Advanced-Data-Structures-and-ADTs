# Segment/Interval Trees

A segment tree(statistic tree) is a tree data structure used for storing information about segments or intervals.
It is a structure that cannot be modified once it's built, and it is used for querying certain interval.
It is a balanced tree(the difference between the depth of the left subtree and the right subtree is at most 1).

in this project, it is fully templated(can hold any object) and it receives a relation(bool function) that dictates
what the tree keeps track of.
