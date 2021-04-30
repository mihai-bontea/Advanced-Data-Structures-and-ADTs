#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include "AVLTree.h"

void test_insert()
{
	AVLTree<int> at;
	assert(at.is_empty() == true);

	// Adding the elements from [0, 200] to a vector
	std::vector<int> v;
	for (int index = 0; index <= 200; ++index)
		v.push_back(index);

	// Shuffling the elements
	std::random_shuffle(v.begin(), v.end());

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		assert(at.insert(*it) == true);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		assert(at.search(*it) == true);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		assert(at.insert(*it) == false);
}

void test_delete()
{
	AVLTree<int> at;
	assert(at.is_empty() == true);

	// Adding the elements from [0, 100] to a vector
	std::vector<int> v;
	for (int index = 0; index <= 100; ++index)
		v.push_back(index);

	// Shuffling the elements
	std::random_shuffle(v.begin(), v.end());

	// Insert the elements into the AVL Tree
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		assert(at.insert(*it) == true);

	// Remove the elements from the AVL Tree
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		assert(at.remove(*it) == true);
	}
}

void test_delete1()
{
	AVLTree<int> at;
	at.insert(1);
	at.insert(2);
	at.insert(0);

	assert(at.remove(0) == true);
	assert(at.remove(1) == true);
	assert(at.remove(2) == true);
}

int main()
{
	test_insert();
	
	//test_delete();

	test_delete1();

	system("pause");
	return 0;
}