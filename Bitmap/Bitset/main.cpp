#include <iostream>
#include <Windows.h>
#include <cassert>
#include "Bitset.h"

void test_basic()
{
	Bitset bs(32);
	// Bits should initially be 0
	for (size_t bit_index = 0; bit_index < bs.size(); ++bit_index)
		assert(bs.get_bit(bit_index) == 0);

	// Setting some bits to 1
	bs.set_bits(16, 25, 1);

	for (size_t bit_index = 16; bit_index <= 25; ++bit_index)
		assert(bs.get_bit(bit_index) == 1);

	// Setting all bits to 1
	bs.set_bits(0, 31, 1);

	for (size_t bit_index = 0; bit_index < bs.size(); ++bit_index)
		assert(bs.get_bit(bit_index) == 1);

	// Setting all bits to 0
	bs.set_bits(0, 31, 0);

	for (size_t bit_index = 0; bit_index < bs.size(); ++bit_index)
		assert(bs.get_bit(bit_index) == 0);

	assert(bs.size() == 32);
}

int main()
{
	test_basic();
	std::cout << "Tests passed successfully!\n";
	system("pause");
	return 0;
}