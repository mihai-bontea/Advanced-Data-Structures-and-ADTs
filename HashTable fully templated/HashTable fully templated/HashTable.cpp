#include "HashTable.h"
#include <cstring>
#include <string>
#include <iostream>
#define MAX_BYTES 25
#define NIL 'n'
#define DELETED 'd'
#define OCCUPIED 'o'

template <class T>
HashTable<T>::HashTable()
{
	capacity = CAPACITY;
	elems = new T[capacity];
	status = new char[capacity];

	memset(status, NIL, sizeof(char) * capacity);

	nr_elements = 0;
}

template <class T>
HashTable<T>::~HashTable()
{
	delete[] elems;
}

template <class T>
unsigned long long HashTable<T>::transform_to_int(T element) const
{
	void *ptr = &element;
	unsigned long long elements_int = 0;

	for (unsigned index = 0; index * sizeof(char) <= sizeof(T) && index <= MAX_BYTES; ++index)
		elements_int += abs(*((char *)ptr + index));

	return elements_int;
}

template <class T>
bool HashTable<T>::insert_element(T element)
{
	unsigned long long elements_int = transform_to_int(element);
	unsigned long long nr_tries = 0;
	unsigned long long position;

	while (true)
	{
		position = hash(elements_int, nr_tries);

		if (status[position] != OCCUPIED)
		{
			elems[position] = element;
			status[position] = OCCUPIED;
			++nr_elements;
			return true;
		}
		else if (elems[position] == element)
		{
			return false;
		}
		++nr_tries;
		if (nr_tries >= capacity)
		{
			resize();
			nr_tries = 0;
		}
	}
}

template <class T>
bool HashTable<T>::delete_element(T element)
{
	unsigned long long elements_int = transform_to_int(element);
	unsigned long long nr_tries = 0;
	unsigned long long position;

	while (true)
	{
		position = hash(elements_int, nr_tries);

		if (status[position] == NIL)
			return false;

		else if (status[position] == OCCUPIED)
		{
			if (elems[position] == element)
			{
				status[position] = DELETED;
				--nr_elements;
				return true;
			}
		}
		++nr_tries;
		if (nr_tries >= capacity)
			return false;
	}
}

template <class T>
bool HashTable<T>::search_element(T element) const
{
	unsigned long long elements_int = transform_to_int(element);
	unsigned long long nr_tries = 0;
	unsigned long long position;

	while (true)
	{
		position = hash(elements_int, nr_tries);

		if (status[position] == NIL)
			return false;

		else if (status[position] == OCCUPIED)
		{
			if (elems[position] == element)
			{
				return true;
			}
			
		}
		++nr_tries;
		if (nr_tries >= capacity)
			return false;
	}
}

template <class T>
void HashTable<T>::resize()
{
	//std::cout << "Resizing...";
	unsigned long long old_capacity = capacity;
	capacity *= 2;

	//Initializing a backup table
	T *backup_elems = new T[old_capacity];
	char *backup_status = new char[old_capacity];

	for (unsigned long long index = 0; index < old_capacity; ++index)
	{
		backup_elems[index] = elems[index];
		backup_status[index] = status[index];
	}

	delete[] elems;
	delete[] status;

	//Initializing the new array with double the size
	T *new_elems = new T[capacity];
	char *new_status = new char[capacity];
	memset(new_status, NIL, sizeof(char) * capacity);

	elems = new_elems;
	status = new_status;

	for (unsigned long long index = 0; index < old_capacity; ++index)
		if (backup_status[index] != NIL && backup_status[index] != DELETED)
			insert_element(backup_elems[index]);

	delete[] backup_elems;
	delete[] backup_status;
}

template <class T>
unsigned long long HashTable<T>::nr_elems() const
{
	return nr_elements;
}

template class HashTable<int>;
template class HashTable<bool>;
template class HashTable<long long>;
template class HashTable<float>;
template class HashTable<double>;
template class HashTable<char>;
template class HashTable<std::string>;

class TestClass
{
public:

	int var1;
	long long var2;
	bool  var3;
	char var4;
	double var5;

	bool operator==(const TestClass &other) const
	{
		if (this->var1 != other.var1)
			return false;
		if (this->var2 != other.var2)
			return false;
		if (this->var3 != other.var3)
			return false;
		if (this->var4 != other.var4)
			return false;
		if (this->var5 != other.var5)
			return false;

		return true;
	}
};

template class HashTable<TestClass>;
