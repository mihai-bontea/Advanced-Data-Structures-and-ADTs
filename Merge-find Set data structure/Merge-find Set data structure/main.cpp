#include <iostream>
#include <Windows.h>
#include <cassert>
#include "MergeFindSet.h"

void test()
{
	// Taking the first 6 non-zero natural numbers
	MergeFindSet mfs(6);

	assert(mfs.are_same_set(1, 2) == false);
	assert(mfs.are_same_set(4, 6) == false);
	
	// Merging the sets containing 1 and 2, resulted set: {1, 2}
	mfs.merge_sets(1, 2);
	assert(mfs.are_same_set(1, 2) == true);

	// Merging the sets containing 4 and 6, resulted set: {4, 6}
	mfs.merge_sets(4, 6);
	assert(mfs.are_same_set(4, 6) == true);
	
	// Merging the sets containing 1 and 4, resulted set: {1, 2, 4, 6}
	mfs.merge_sets(1, 4);
	assert(mfs.are_same_set(2, 6) == true);
}

int main()
{
	test();
	std::cout << "Passed all tests!\n";
	system("pause");
	return 0;
}