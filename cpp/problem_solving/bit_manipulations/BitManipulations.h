#pragma once

#include <stdint.h>

class BitManipulations
{
public:
	bool isIthBitSet(uint32_t input, uint8_t bitPosition);
	void setIthBit(uint32_t& input, uint8_t bitPosition);
	void clearIthBit(uint32_t& input, uint8_t bitPosition);
	void removeLastSetBit(uint32_t& input);
	bool isGivenNumberEven(uint32_t input);
	bool isGivenNumberOdd(uint32_t input);
	bool isGivenNumberPowerOf2(uint32_t input);
	bool isGivenNumberPowerOf4(uint32_t input);
	bool isGivenNumberPowerOf8(uint32_t input);
	bool isGivenNumberPowerOf16(uint32_t input);
	void toggleIthBit(uint32_t& input, uint8_t bitPosition);
	uint8_t getSetBitsCount(uint32_t input);
};
