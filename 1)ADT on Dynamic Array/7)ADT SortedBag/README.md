# ADT Sorted Bag/Sorted Multiset

The ADT Sorted Bag/Sorted Multiset is a container in which elements do not have positions, and unlike sets, allows for multiple instances of each element.
In addition to the regular Bag/Multiset however, the elements are ordered by a relation, and iterating through the Sorted Bag, the elements will be found
in the right order. As a consequence, interrogations such as search and number of occurences go from **O(n)** to **O(log n)** if binary search is used.
In this example, it is represented using <element, frequency> pairs.
