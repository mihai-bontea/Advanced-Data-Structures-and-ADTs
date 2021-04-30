#include <iostream>
#include <Windows.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include "BST.h"

void test_search_insert()
{
	BST<int> bst;
	assert(bst.is_empty() == true);
	assert(bst.search(1) == false);

	// Inserting all elements from [0, 50]
	for (int index = 1; index < 50; index += 2)
		bst.insert(index);

	for (int index = 50; index >= 0; index -= 2)
		bst.insert(index);

	// Inserting already existing elements
	for (int index = 10; index <= 20; ++index)
		bst.insert(index);

	assert(bst.is_empty() == false);

	// Searching all elements from [0, 50]

	for (int index = 0; index <= 50; ++index)
		assert(bst.search(index) == true);

	assert(bst.search(100) == false);
}


void test_remove_case1()
{
	/*
		Case 1: node to be deleted is a leaf
					1
				   / \
				  /   \
				 0     2
		-remove 0 and 2, then 1
	*/

	BST<int> bst1;

	bst1.insert(1);
	bst1.insert(2);
	bst1.insert(0);

	assert(bst1.remove(0) == true);
	assert(bst1.remove(2) == true);

	assert(bst1.search(0) == false);
	assert(bst1.search(2) == false);
	
	assert(bst1.search(1) == true);

	assert(bst1.remove(0) == false);
	assert(bst1.remove(2) == false);

	assert(bst1.remove(1) == true);
	assert(bst1.search(1) == false);
	
	assert(bst1.is_empty() == true);
}


void test_remove_case2()
{
	/*
		Case 2: node to be deleted is a leaf
					2
				   / 
				  /   
				 1
				/
			   /
			  0
		-remove 1, then 2
	*/

	BST<int> bst1;

	bst1.insert(2);
	bst1.insert(1);
	bst1.insert(0);

	assert(bst1.remove(1) == true);
	assert(bst1.search(1) == false);

	assert(bst1.remove(2) == true);
	assert(bst1.search(2) == false);

	assert(bst1.search(0) == true);
}


void test_remove_case3()
{
	/*
		Case 3: node to be deleted has two children
					1
				   / \
				  /   \
				 0     2
		-remove 1
	*/

	BST<int> bst1;
	
	bst1.insert(1);
	bst1.insert(0);
	bst1.insert(2);

	assert(bst1.remove(1) == true);
}


void test_remove_quantity()
{
	BST<int> bst;

	std::vector<int> v;

	// Add all elements from [0, 100] to this vector
	for (int index = 0; index <= 100; ++index)
		v.push_back(index);

	// Shuffle the contents of the vector
	std::random_shuffle(v.begin(), v.end());

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		bst.insert(*it);

	// Assert that the contents of the vector appear in the BST
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		assert(bst.search(*it) == true);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		assert(bst.remove(*it) == true);
	}
}

void test_remove_quantity_freq()
{
	BST<int> bst;

	std::vector<int> v;

	// Add all elements from [0, 100] to this vector
	for (int index = 0; index <= 100; ++index)
		v.push_back(index);

	// Shuffle the contents of the vector 5 times, add it to the BST
	for (unsigned index_shuffle = 0; index_shuffle < 5; ++index_shuffle)
	{
		std::random_shuffle(v.begin(), v.end());

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
			bst.insert(*it);
	}

	// Delete all the 5 instances of those elements
	for (unsigned index_delete = 0; index_delete < 5; ++index_delete)
	{
		// Assert that the contents of the vector appear in the BST
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
			assert(bst.search(*it) == true);

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			assert(bst.remove(*it) == true);
		}
	}

	assert(bst.is_empty() == true);
}


int main()
{
	test_search_insert();

	test_remove_case1();

	test_remove_case2();

	test_remove_case3();

	test_remove_quantity();

	test_remove_quantity_freq();

	std::cout << "All tests passed!\n";

	system("pause");
	return 0;
}