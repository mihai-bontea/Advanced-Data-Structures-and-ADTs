#pragma once

class Bitset
{
private:
	char *data;
	size_t nr_bits;
	size_t nr_bytes;

public:

	Bitset(size_t _nr_bits);
	/*
		Description: Allocates enough memory to store the given number of bits. It doesn't have to be a multiple of
					 8 specifically.
		Throws: exception if enough memory can't be allocated
	*/

	~Bitset();
	/*
		Description: Frees the memory associated to the bitset
	*/

	bool get_bit(size_t index) const;
	/*
		Description: returns the value of the bit at the given index
		Throws: exception if index is invalid
	*/

	void set_bit(size_t index, bool value);
	/*
		Description: sets the bit at the given index to the given value
		Throws: exception if index is invalid
	*/
	
	void set_bits(size_t left, size_t right, bool value);
	/*
		Description: sets the bits belonging to [left, right] to the given value
		Throws: an exception if left > right or right >= total of bits
	*/

	size_t size() const;
	/*
		Description: returns the number of bits in this bitset
	*/
};