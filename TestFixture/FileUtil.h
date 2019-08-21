#pragma once

class fileDataSink
{
public:
	fileDataSink(const char *fileName);
	~fileDataSink();
	void op(unsigned char a);

private:
	FILE *fHand;
};

class fileDataSource
{
public:
	fileDataSource(const char *fileName);
	~fileDataSource();
	std::string getData();
private:
	FILE *fHand;
};