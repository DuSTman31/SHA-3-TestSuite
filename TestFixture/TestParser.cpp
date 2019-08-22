#include "stdafx.h"
#include "TestParser.h"
using std::cout;


bool TestParser::parseMDLine(StringContext &a)
{
	StringContext b = a;
	if (matchString(b, "MD = "))
	{
		std::pair<bool, std::string> res = hexString(b);

		if (res.first == true)
		{
			digest = res.second;
		}
		return res.first;
	}
	else
	{
		return false;
	}
}

bool TestParser::parseMsgLine(StringContext &a)
{
	StringContext b = a;
	if (matchString(b, "Msg = "))
	{
		std::pair<bool, std::string> res = hexString(b);

		if (res.first == true)
		{
			message = res.second;
		}
		return res.first;
	}
	else
	{
		return false;
	}
}

bool TestParser::parseLengthLine(StringContext &a)
{
	StringContext b = a;
	if (matchString(b, "Len = "))
	{
		std::pair<bool, unsigned int> res = parseUInt(b);

		if (res.first == true)
		{
			length = res.second;
		}
		return res.first;
	}
	else
	{
		return false;
	}
}

bool TestParser::parseLine(std::string &a)
{
	if (a.length() == 0)
	{
		return false;
	}

	if (a[0] == 'L')
	{
		StringContext sc(a);
		bool lengthLine = parseLengthLine(sc);
		return false; 
	}
	else if (a[0] == 'M')
	{
		StringContext sc(a);
		StringContext sc2 = sc;

		if (!parseMsgLine(sc))
		{
			if (parseMDLine(sc2))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}
	else if (a[0] == '[')
	{
		StringContext sc(a);
		parseL(sc);
	}

	return false;

}

bool TestParser::parseL(StringContext &a)
{
	if (matchString(a, "[L = "))
	{
		std::pair<bool, unsigned int> res = parseUInt(a);
		if (res.first)
		{
			hashLength = res.second;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

test TestParser::getTestDetails()
{
	return test(length, message, digest, hashLength);
}
