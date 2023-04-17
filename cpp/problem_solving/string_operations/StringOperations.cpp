#include "StringOperations.h"

char StringOperations::convertCharacterUppercaseToLowercase(char input)
{
	return (input | ' ');
}

char StringOperations::convertCharacterLowercaseToUppercase(char input)
{
	return (input & '_'); // or, (input - ' ')
}

char StringOperations::invertCharacterCase(char input)
{
	return (input ^ ' ');
}
