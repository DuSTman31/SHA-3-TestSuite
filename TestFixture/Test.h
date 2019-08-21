#pragma once


class test
{
public:
	test(unsigned int s, const char *sr, const char *re, unsigned int hl); 
	test(unsigned int s, std::string &sr, std::string &re, unsigned int hl);
	void prepareInputFile();

	unsigned int hashLength;
	unsigned int size;
	std::string source;
	std::string result;
};
