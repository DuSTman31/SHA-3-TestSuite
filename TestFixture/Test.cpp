#include "stdafx.h"
#include "Test.h"

#include "Hex.h"
#include "FileUtil.h"

template<typename T1>
static inline unsigned char hexDecode(T1 &begin, T1 &end)
{
	unsigned char b = 0;
	unsigned char c = 0;

	if (begin == end)
	{
		return 0;
	}
	b = *begin;
	begin++;
	if (begin == end)
	{
		return 0;
	}
	c = *begin;
	begin++;
	return Hex::decodeHexCharPair(b, c);
}


test::test(unsigned int s, const char *sr, const char *re, unsigned int hl) : size(s), source(sr), result(re), hashLength(hl) {};


test::test(unsigned int s, std::string &sr, std::string &re, unsigned int hl) : size(s), source(sr), result(re), hashLength(hl) {};

void test::prepareInputFile()
{
	std::vector<unsigned char> b;
	for (auto aI = source.begin(); aI != source.end();)
	{
		b.push_back(hexDecode(aI, source.end()));
	}
	unsigned int amtWritten = 0;

	fileDataSink ops("tst2.txt");
	while (amtWritten < size)
	{
		for (auto i : b)
		{
			if (amtWritten == size)
			{
				break;
			}
			unsigned char c = i;
			ops.op(c);
			amtWritten += 8;
		}
	}
}