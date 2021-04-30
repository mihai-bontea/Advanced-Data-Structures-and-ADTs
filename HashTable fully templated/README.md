# HashTable

A hash table is a data structure that uses a hash function to compute an index into an array of slots.
Searching for an element takes O(1) time complexity but only as average case(worst case is O(n)). Since most hash
functions aren't perfect, **collisions** can happen, when the hash function generates the same index for two different objects.
As a result, conflict resolution techniques are used. In this example, *open addressing with double hashing* is used.
It can hash any object, by viewing it as a char array and generating an integer based on the bytes it contains. This integer
will be used in the hashing functions.