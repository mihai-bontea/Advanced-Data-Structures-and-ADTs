#include <iostream>
#include <Windows.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include "BTree.h"

void test_search_insert1()
{
	BTree<int> bt(3);
	
	std::vector<int> v;
	
	// Adding the elements from 1 to 300 to a vector
	for (int nr = 1; nr <= 300; ++nr)
		v.push_back(nr);

	// Shuffling the contents of the vector
	std::random_shuffle(v.begin(), v.end());

	// Inserting the contents of the vector into the B Tree
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		bt.insert(*it);

	// Searching the contents of the vector into the B Tree
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		assert(bt.search(*it) == true);
		
}


int main()
{
	test_search_insert1();

	std::cout << "All tests passed! \n";

	system("pause");
	return 0;
}