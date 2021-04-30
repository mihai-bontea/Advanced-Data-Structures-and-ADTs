# ADT Queue

The ADT Queue is a container in which elements are kept in order and access is restricted to the two ends of the container, front and rear.
The two principal operations are addition of elements to the end, named **push/enqueue**, and removal of elements from the front, named
**pop/dequeue**.
It has a FIFO policy(First In First Out).
In this example, it is represented on a circular dynamic array. Queue operations should ideally be done in O(1). Under the circular dynamic
array representation this is respected. However, in the case of exceeding the capacity, a resize is needed, which adds an additional O(n)
to the push/enqueue operation, due to the need of copying the elements from the old memory block to the new memory block.
