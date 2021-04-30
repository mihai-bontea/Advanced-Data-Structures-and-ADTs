#include <fstream>
#include <Windows.h>
#include <cassert>
#include "SegmentTree.h"

// With this function, the segment tree will keep track of the minimum of 2 ranges
bool minimum(const int &p1, const int &p2)
{
	return p1 <= p2;
}

// With this function, the segment tree will keep track of the maximum of 2 ranges
bool maximum(const int &p1, const int &p2)
{
	return p1 >= p2;
}

void test1()
{
	std::ifstream fin("file.in");
	SegmentTree<int> tree(minimum);
	tree.Read(fin);
	
	assert(tree.Query(1, 13) == 1);
	assert(tree.Query(2, 4) == 2);
	assert(tree.Query(10, 10) == 8);
	assert(tree.Query(9, 13) == 8);
	assert(tree.Query(5, 8) == 1);
}

void test2()
{
	std::ifstream fin("file.in");
	SegmentTree<int> tree(maximum);
	tree.Read(fin);

	assert(tree.Query(1, 13) == 31);
	assert(tree.Query(2, 4) == 6);
	assert(tree.Query(10, 10) == 8);
	assert(tree.Query(9, 13) == 31);
	assert(tree.Query(5, 8) == 4);
}

void test3()
{
	std::ifstream fin("file.in");
	SegmentTree<int> tree(maximum);
	tree.Read(fin);

	assert(tree.Query(1, 4) == 6);
	// Setting all elements in the [1, 4] range to 7
	tree.UpdateRange(1, 4, 7);
	assert(tree.Query(1, 4) == 7);

	assert(tree.Query(6, 10) == 12);
	// Setting all elements in the [6, 10] range to 5
	tree.UpdateRange(6, 10, 5);
	assert(tree.Query(6, 10) == 5);

	// Setting all the elements to 99
	tree.UpdateRange(1, 13, 99);
	
	for (unsigned i = 1 ; i <= 13 ; ++i)
		for (unsigned j = i; j <= 13; ++j)
			assert(tree.Query(i, j) == 99);
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}