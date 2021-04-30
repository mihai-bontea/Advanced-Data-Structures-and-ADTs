# Segment/Interval Trees with Lazy Propagation

A segment tree(statistic tree) is a tree data structure used for storing information about segments or intervals.
It is a structure that cannot be modified once it's built, and it is used for querying certain interval.
It is a balanced tree(the difference between the depth of the left subtree and the right subtree is at most 1).

in this project, it is fully templated(can hold any object) and it receives a relation(bool function) that dictates
what the tree keeps track of.

## What sets a segment/interval tree with lazy propagation apart from the regular segment/interval trees?

In certain situations, you may want to update an interval from [start, end], instead of a single element.
Using the regular single element updating function in a for, such an operation would have a complexity of O(n).
However, there is a more efficient way, that only has O(log n) complexity, and will require us to modify the **Update** function,
and also the **Query** function. It is called *lazy* because once we find the interval we are looking for, we stop there
without updating the children nodes. Thus, when we perform a **Query** operation on certain intervals, we may need to update
them if they were postponed by the **Update** function. On the bright side, only the intervals we are interested in will be updated,
making the process more efficient.

