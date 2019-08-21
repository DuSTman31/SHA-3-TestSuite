#include "stdafx.h"
#include "ResultParser.h"

#include "Parsing.h"

ResultParser::ResultParser(const char *fName) : fs(fName)
{
}


ResultParser::~ResultParser()
{
}

void ResultParser::process()
{
	std::string fileContents = fs.getData();
	std::vector<std::string> rl = splitIntoLines(fileContents);

	for (auto &l : rl)
	{
		parseLine(l);
	}
}

void ResultParser::parseLine(std::string &a)
{
	StringContext sc(a);

	while (sc.checkLengthSufficient(0) && sc.getChar() != ':')
	{
		sc.advance(1);
	}
	if (!sc.checkLengthSufficient(0))
	{
		return;
	}

	sc.advance(1);
	if (!sc.checkLengthSufficient(0))
	{
		return;
	}

	sc.advance(1);

	std::pair<bool, std::string> res = hexString(sc);

	if (res.first)
	{
		result = res.second;
	}
}

std::string ResultParser::getResString()
{
	return result;
}