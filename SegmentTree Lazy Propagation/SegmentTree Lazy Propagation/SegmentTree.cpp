#include "SegmentTree.h"
#include <stdexcept>
#include <cstring>

template <class T>
SegmentTree<T>::SegmentTree(bool(*_r)(const T &p1, const T &p2)) : r{ _r }, elems{ nullptr }, surplus{ nullptr }
{

}

template <class T>
SegmentTree<T>::~SegmentTree()
{
	delete[] elems;
	delete[] surplus;
}

template <class T>
void SegmentTree<T>::Read(std::istream &stream)
{
	// Read the length and throw an exception if it is less than or equal to 0
	stream >> segment_len;

	if (segment_len <= 0)
		throw std::exception();

	// If the segment tree is already keeping track of something, clear up the memory
	if (elems != nullptr)
	{
		delete[] elems;
		delete[] surplus;

		elems = nullptr;
		surplus = nullptr;
	}

	// Allocating memory, and initializing the surplus array
	// surplus[Node] = true iff we also need to update its children(lazy propagation)
	elems = new T[(segment_len + 1) * 4];
	surplus = new bool[(segment_len + 1) * 4];
	memset(surplus, 0, sizeof(bool) * (segment_len + 1) * 4);

	BuildTree(stream, 1, 1, segment_len);
}

template <class T>
void SegmentTree<T>::BuildTree(std::istream &stream, unsigned Node, unsigned Left, unsigned Right)
{
	if (Left == Right)
	{
		stream >> elems[Node];
	}
	else
	{
		unsigned Mid = (Left + Right) / 2;
		BuildTree(stream, 2 * Node, Left, Mid);
		BuildTree(stream, 2 * Node + 1, Mid + 1, Right);
		elems[Node] = r(elems[2 * Node], elems[2 * Node + 1]) ? elems[2 * Node] : elems[2 * Node + 1];
	}
}

template <class T>
void SegmentTree<T>::UpdateTree(unsigned Node, unsigned Left, unsigned Right, unsigned start, unsigned end, T val)
{
	if (start <= Left && Right <= end)
	{
		elems[Node] = val;
		surplus[Node] = true;
	}
	else
	{
		if (surplus[Node] == true)
		{
			// Update children, set as lazy
			elems[2 * Node] = elems[Node];
			elems[2 * Node + 1] = elems[Node];

			surplus[2 * Node] = true;
			surplus[2 * Node + 1] = true;

			// Mark the current node as no longer lazy
			surplus[Node] = false;
		}

		unsigned Mid = (Left + Right) / 2;
		if (start <= Mid)
		{
			UpdateTree(2 * Node, Left, Mid, start, end, val);
		}
		
		if (end > Mid)
		{
			UpdateTree(2 * Node + 1, Mid + 1, Right, start, end, val);
		}

		elems[Node] = r(elems[2 * Node], elems[2 * Node + 1]) ? elems[2 * Node] : elems[2 * Node + 1];
	}
}

template <class T>
void SegmentTree<T>::UpdateRange(unsigned start, unsigned end, T value)
{
	// Check if the range given is valid, throw exception if it is not
	if (start <= 0 || end <= 0 || start > segment_len  || end > segment_len || start > end )
		throw std::exception();

	UpdateTree(1, 1, segment_len, start, end, value);
}

template <class T>
const T& SegmentTree<T>::QueryTree(unsigned Node, unsigned Left, unsigned Right, unsigned qA, unsigned qB) const
{
	if (qA <= Left && Right <= qB)
		return elems[Node];
	else
	{
		if (surplus[Node] == true)
		{
			// Update children, set as lazy
			elems[2 * Node] = elems[Node];
			elems[2 * Node + 1] = elems[Node];

			surplus[2 * Node] = true;
			surplus[2 * Node + 1] = true;

			// Mark the current node as no longer lazy
			surplus[Node] = false;
		}

		unsigned Mid = (Left + Right) / 2;
		T result1;
		T result2;
		if (qA <= Mid)
		{
			result1 = QueryTree(2 * Node, Left, Mid, qA, qB);
		}
		if (qB > Mid)
		{
			result2 = QueryTree(2 * Node + 1, Mid + 1, Right, qA, qB);
		}

		if (qA <= Mid && qB > Mid)
		{
			return r(result1, result2) ? result1 : result2;
		}
		else if (qA <= Mid)
		{
			return result1;
		}
		else
		{
			return result2;
		}
	}
}

template <class T>
const T& SegmentTree<T>::Query(unsigned qA, unsigned qB) const
{
	// Check if the range given is valid, throw exception if it is not
	if (qA <= 0 || qB <= 0 || qA > segment_len || qB > segment_len || qA > qB)
		throw std::exception();

	return QueryTree(1, 1, segment_len, qA, qB);
}

template class SegmentTree<int>;
template class SegmentTree<float>;
template class SegmentTree<std::string>;