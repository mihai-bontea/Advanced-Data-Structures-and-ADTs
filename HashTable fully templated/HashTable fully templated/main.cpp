#include <iostream>
#include <Windows.h>
#include <cassert>
#include "HashTable.h"

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

void test_all()
{
	HashTable<int> ht;
	assert(ht.nr_elems() == 0);

	for (int i = 1; i <= 50; ++i)
		assert(ht.insert_element(i) == true);

	for (int i = 1; i <= 50; ++i)
		assert(ht.search_element(i) == true);

	for (int i = 1; i <= 50; ++i)
		assert(ht.insert_element(i) == false);

	assert(ht.nr_elems() == 50);

	for (int i = 1; i <= 50; ++i)
		assert(ht.delete_element(i) == true);

	for (int i = 1; i <= 50; ++i)
		assert(ht.delete_element(i) == false);

	assert(ht.nr_elems() == 0);
}

void test_custom_class()
{
	TestClass obj1;

	obj1.var1 = 1563631;
	obj1.var2 = 2949549494949;
	obj1.var3 = true;
	obj1.var4 = 'a';
	obj1.var5 = 3.14;

	HashTable<TestClass> ht;

	assert(ht.insert_element(obj1) == true);

	assert(ht.search_element(obj1) == true);

	assert(ht.insert_element(obj1) == false);

	assert(ht.delete_element(obj1) == true);

	assert(ht.delete_element(obj1) == false);

	// Adding objects
	for (unsigned index = 1; index <= 10; ++index)
	{
		TestClass aux;
		
		aux.var1 = aux.var2 = index;
		aux.var3 = true;
		aux.var4 = 'a';
		aux.var5 = 3.14;

		assert(ht.insert_element(aux) == true);
	}

	assert(ht.nr_elems() == 10);

	// Searching objects
	for (unsigned index = 1; index <= 10; ++index)
	{
		TestClass aux;

		aux.var1 = aux.var2 = index;
		aux.var3 = true;
		aux.var4 = 'a';
		aux.var5 = 3.14;

		assert(ht.search_element(aux) == true);
	}

	// Deleting objects
	for (unsigned index = 1; index <= 10; ++index)
	{
		TestClass aux;

		aux.var1 = aux.var2 = index;
		aux.var3 = true;
		aux.var4 = 'a';
		aux.var5 = 3.14;

		assert(ht.delete_element(aux) == true);
		assert(ht.delete_element(aux) == false);
	}

	assert(ht.nr_elems() == 0);
}

int main()
{
	test_all();
	test_custom_class();

	system("pause");
	return 0;
}