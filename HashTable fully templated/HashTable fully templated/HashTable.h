#pragma once
#include <cmath>
#define CAPACITY 100

template <class T>
class HashTable
{
private:

	T *elems;
	char *status;
	unsigned long long capacity;
	unsigned long long nr_elements;

	inline unsigned long long hash(unsigned long long elements_int, unsigned long long nr_tries) const
	{
		return (hash1(elements_int) + nr_tries * hash2(elements_int)) % capacity;
	}

	inline unsigned long long hash1(unsigned long long elements_int) const
	{
		return (elements_int % capacity);
	}

	inline unsigned long long hash2(unsigned long long elements_int) const
	{
		return (elements_int / 937 + 1);
	}

	unsigned long long transform_to_int(T element) const;

	void resize();

public:

	HashTable();

	~HashTable();

	bool insert_element(T element);
	/*
		Description: inserts the given element into the hash table
					 returns true if it was inserted successfully, or
					 false if it already exists

		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(1)
	*/

	bool delete_element(T element);
	/*
		Description: deletes the given element from the hash table
					 returns true if it was deleted successfully, or
					 false if that element didn't exist in the hash table

		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(1)
	*/

	bool search_element(T element) const;
	/*
		Description: checks whether an element appears in the hash table
					 returns true if it appears, false otherwise

		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(1)
	*/

	unsigned long long nr_elems() const;
	/*
		Description: returns the number of elements in the hash table

		Best Case = Worst Case = Average Case = O(1)
	*/
};