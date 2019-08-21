#pragma once

#include "Parsing.h"
#include "Test.h"

class TestParser
{
public:
	bool parseLine(std::string &a);
	test getTestDetails();
private:
	bool parseMDLine(StringContext &a);
	bool parseMsgLine(StringContext &a);
	bool parseLengthLine(StringContext &a);
	bool parseL(StringContext &a);

	unsigned int hashLength = 512;
	std::string message;
	std::string digest;
	unsigned int length;
};