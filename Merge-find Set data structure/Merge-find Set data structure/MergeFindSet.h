#pragma once
#define MAX 100000

class MergeFindSet
{
private:

	unsigned max_element;
	unsigned *tree;
	unsigned *rank;

	unsigned find(unsigned element);
	/*
		Description: utility function, returns the root of the tree that element belongs to

		Average Case = O(a(n)), where a(n) is the inverse Ackermann function
					   a(n) < 5 for any n, so it can be approximated to O(1)
	*/

	void unite(unsigned root1, unsigned root2);
	/*
		Description: utility function, unites the set rooted in root1 with the set rooted in root2

		Average Case = O(a(n)), where a(n) is the inverse Ackermann function
					   a(n) < 5 for any n, so it can be approximated to O(1)
	*/

public:

	MergeFindSet(unsigned _max_element);
	/*
		Description: constructor, allocates the required memory for the [1, max_element] range
					 and initializes the data

		throws: exception if the number given is outside of the accepted range or if it fails
				to allocate the required amount of memory

		Best Case = Worst Case = Average Case = O(n)
	*/

	~MergeFindSet();
	/*
		Description: destructor, deallocates the memory
	*/

	bool are_same_set(unsigned element1, unsigned element2);
	/*
		Description: returns True if the two given elements belong to the same set,
					 False otherwise

		throws: exception if the numbers given are outside of the accepted range

		Average Case = O(a(n)), where a(n) is the inverse Ackermann function
					   a(n) < 5 for any n, so it can be approximated to O(1)
	*/

	void merge_sets(unsigned element1, unsigned element2);
	/*
		Description: merges the set containing element1 with the set containing element2

		throws: exception if the numbers given are outside of the accepted range or if
		        the elements already belong to the same set

		Average Case = O(a(n)), where a(n) is the inverse Ackermann function
					   a(n) < 5 for any n, so it can be approximated to O(1)
	*/
};