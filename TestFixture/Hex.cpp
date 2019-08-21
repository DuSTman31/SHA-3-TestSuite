#include "stdafx.h"
#include "Hex.h"

unsigned char Hex::decodeHexChar(char a)
{
	if (a >= '0' && a <= '9')
	{
		return a - '0';
	}
	if (a >= 'A' && a <= 'F')
	{
		return ((a - 'A') + 10);
	}
	if (a >= 'a' && a <= 'f')
	{
		return ((a - 'a') + 10);
	}
}

unsigned char Hex::decodeHexCharPair(unsigned char a, unsigned char b)
{
	unsigned char c = decodeHexChar(a);
	unsigned char d = decodeHexChar(b);
	c = c << 4;
	return (c | d);
}
