# (Templated) ADT Queue

The ADT Queue is a container in which elements are kept in order and access is restricted to the two ends of the container, front and rear.
The two principal operations are addition of elements to the end, named **push/enqueue**, and removal of elements from the front, named
**pop/dequeue**.
It has a FIFO policy(First In First Out).
In this example, it is represented on a singly linked list, which allows the principal queue operations to be done in **O(1)**.
It is fully templated.