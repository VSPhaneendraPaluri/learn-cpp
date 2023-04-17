#include "BitManipulations.h"

bool BitManipulations::isIthBitSet(uint32_t input, uint8_t bitPosition)
{
	return (input & (1 << bitPosition)) == (1 << bitPosition);
}

void BitManipulations::setIthBit(uint32_t& input, uint8_t bitPosition)
{
	input |= (1 << bitPosition);
}

void BitManipulations::clearIthBit(uint32_t& input, uint8_t bitPosition)
{
	input &= ~(1 << bitPosition);
}

void BitManipulations::removeLastSetBit(uint32_t& input)
{
	input &= (input - 1);
}

bool BitManipulations::isGivenNumberEven(uint32_t input)
{
	return ((input % 2) == 0)             // modulo of 2
		&& ((input & 0x1) == 0x0)         // last digit to be 0x0
		&& (((input / 2) * 2) == input)   // integral divisor of 2
		&& (((input >> 1) << 1) == input);// same as above, achieved using shift operators
}

bool BitManipulations::isGivenNumberOdd(uint32_t input)
{
	return ((input % 2) == 0x1)           // module of 2 leaves remainder 1
		&& ((input & 0x1) == 0x1)         // LSB is 0x1
		&& (((input / 2) * 2) != input)   // not a perfect integer divisible by 2
		&& (((input >> 1) << 1) != input);
}

bool BitManipulations::isGivenNumberPowerOf2(uint32_t input)
{
	return (input & (input - 1)) == 0;
}

bool BitManipulations::isGivenNumberPowerOf4(uint32_t input)
{
	if (input == 0) return false;
	while (input % 4 == 0) { input = input / 4; }
	if (input == 1) return true;
	else return false;
}

bool BitManipulations::isGivenNumberPowerOf8(uint32_t input)
{
	if (input == 0) return false;
	while (input % 8 == 0) { input = input / 8; }
	if (input == 1) return true;
	else return false;
}

bool BitManipulations::isGivenNumberPowerOf16(uint32_t input)
{
	if (input == 0) return false;
	return !(input & (input - 1)) && (input % 15 == 1);
}

void BitManipulations::toggleIthBit(uint32_t& input, uint8_t bitPosition)
{
	input ^= (1 << bitPosition);
}

uint8_t BitManipulations::getSetBitsCount(uint32_t input)
{
	uint8_t count = 0;
	while (input != 0)
	{
		if (input & 0x1) { count++; }
		input >>= 1;
	}
	return count;
}
