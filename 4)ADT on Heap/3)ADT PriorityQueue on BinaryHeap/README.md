# Priority Queue

The ADT Priority Queue is a container in which elements are kept in order and access is restricted. It is an extension of a queue, where instead of the
order in which we inserted the elements mattering, **each element has a priority associated to it**. Only the element with the highest priority can be
accessed. In the case of two elements having the same priority, then the order in which they were inserted in the priority queue matters, the first
inserted having greater importance. The two principal operations are addition of elements to the container, named **push/enqueue**, and removal of
the highest priority element, named **pop/dequeue**. Here it is represented on a binary heap, an efficient representation for a priority queue.
