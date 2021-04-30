#include "Bitset.h"
#include <stdexcept>
#define ON 0xFF
#define OFF 0

Bitset::Bitset(size_t _nr_bits)
{
	nr_bits = _nr_bits;
	nr_bytes = nr_bits / 8;
	if (nr_bits % 8 != 0)
		++nr_bytes;

	// Allocating memory
	data = new char[nr_bytes];

	if (data == nullptr)
		throw std::bad_alloc();

	// Setting the memory
	for (size_t byte_index = 0; byte_index < nr_bytes; ++byte_index)
		data[byte_index] = OFF;
}

Bitset::~Bitset()
{
	if (data != nullptr)
		delete[] data;
}

bool Bitset::get_bit(size_t index) const
{
	if (index >= nr_bits)
		throw std::exception();

	// Determining the byte and bit of interest

	char byte_of_interest = data[index / 8];
	size_t bit_of_interest = index % 8;

	char mask = 1;
	mask = mask << (7 - bit_of_interest);

	return (mask & byte_of_interest) != 0;
}

void Bitset::set_bit(size_t index, bool value)
{
	if (index >= nr_bits)
		throw std::exception();

	char *byte_of_interest = &(data[index / 8]);
	size_t bit_of_interest = index % 8;

	char mask = 1;
	mask = mask << (7 - bit_of_interest);

	if (value)
		*byte_of_interest = ((*byte_of_interest) | mask);
	else
		*byte_of_interest = ((*byte_of_interest) ^ mask);
}

void Bitset::set_bits(size_t left, size_t right, bool value)
{
	if (left > right || right >= nr_bits)
		throw std::exception();

	for (size_t bit_index = left; bit_index <= right; ++bit_index)
		set_bit(bit_index, value);
}

size_t Bitset::size() const
{
	return nr_bits;
}
