#include <iostream>
#include <cassert>
#include <Windows.h>
#include "Deque.h"

void test_fun()
{
	Deque<int> dq;
	assert(dq.isEmpty() == true);

	for (int elem = 1; elem <= 50; ++elem)
	{
		dq.push_back(elem);
		assert(dq.back() == elem);
	}

	assert(dq.isEmpty() == false);
	assert(dq.front() == 1);
	assert(dq.back() == 50);

	for (int elem = 1; elem <= 50; ++elem)
	{
		assert(dq.front() == elem);
		assert(dq.pop_front() == elem);
	}

	assert(dq.isEmpty() == true);

	for (int elem = 1; elem <= 50; ++elem)
		dq.push_back(elem);

	for (int elem = 50; elem >= 1; --elem)
	{
		assert(dq.back() == elem);
		assert(dq.pop_back() == elem);
	}

}


int main()
{
	test_fun();
	std::cout << "Tests ran successfully!\n";
	system("pause");
	return 0;
}