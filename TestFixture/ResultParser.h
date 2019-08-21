#pragma once

#include "FileUtil.h"

class ResultParser
{
public:
	ResultParser(const char *fName);
	~ResultParser();
	void process();
	std::string getResString();
private:
	void parseLine(std::string &a);
	fileDataSource fs;
	std::string result;
};

