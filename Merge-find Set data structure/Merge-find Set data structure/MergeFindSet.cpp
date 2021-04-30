#include "MergeFindSet.h"
#include <limits>
#include <stdexcept>

MergeFindSet::MergeFindSet(unsigned _max_element): max_element{ _max_element }
{
	if (max_element == 0 || max_element > MAX)
		throw std::exception("Number outside accepted range!");

	tree = new unsigned[max_element + 1];
	rank = new unsigned[max_element + 1];

	if (tree == nullptr || rank == nullptr)
		throw std::exception("Can't allocate the required memory!");

	for (unsigned index = 1; index <= max_element; ++index)
	{
		// Initially, each node points to itself(a set containing only one element)
		tree[index] = index;
		
		// Initially, the rank of each tree is 1
		rank[index] = 1;
	}
}


MergeFindSet::~MergeFindSet()
{
	delete[] tree;
	delete[] rank;
}

bool MergeFindSet::are_same_set(unsigned element1, unsigned element2)
{
	if (element1 == 0 || element1 > MAX)
		throw std::exception("element1 outside accepted range!");

	if (element2 == 0 || element2 > MAX)
		throw std::exception("element2 outside accepted range!");

	if (element1 == element2)
		return true;

	return find(element1) == find(element2);
}


unsigned MergeFindSet::find(unsigned element)
{
	unsigned root;

	// Go upwards in order to find a node which points to itself(root)
	for (root = element; tree[root] != root; root = tree[root]);

	// Applying path compression
	unsigned aux;
	while (tree[element] != element)
	{
		aux = tree[element];
		tree[element] = root;
		element = aux;
	}

	return root;
}


void MergeFindSet::merge_sets(unsigned element1, unsigned element2)
{
	if (element1 == 0 || element1 > MAX)
		throw std::exception("element1 outside accepted range!");

	if (element2 == 0 || element2 > MAX)
		throw std::exception("element2 outside accepted range!");

	unsigned root1, root2;
	root1 = find(element1);
	root2 = find(element2);

	if (root1 == root2)
		throw std::exception("Elements belong to the same set already!");

	unite(root1, root2);
}


void MergeFindSet::unite(unsigned root1, unsigned root2)
{
	// Unite the set with the smaller rank to the one with the larger rank
	if (rank[root1] > rank[root2])
		tree[root2] = root1;
	else
		tree[root1] = root2;

	if (rank[root1] == rank[root2])
		++rank[root2];
}

