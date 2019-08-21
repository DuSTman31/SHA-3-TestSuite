#include "stdafx.h"
#include "FileUtil.h"
#include "RAII_Wrapper.h"

fileDataSink::fileDataSink(const char *fileName) {
	fHand = fopen(fileName, "wb");
};

fileDataSink::~fileDataSink() {
	fclose(fHand);
};

void fileDataSink::op(unsigned char a) {
	fwrite(&a, 1, 1, fHand);
};




fileDataSource::fileDataSource(const char *fileName) {
	fHand = fopen(fileName, "rb");
};

fileDataSource::~fileDataSource() {
	fclose(fHand);
};

std::string fileDataSource::getData() {
	size_t bufferSize = 4096;
	fseek(fHand, 0, SEEK_END);
	size_t fSize = ftell(fHand);
	fseek(fHand, 0, SEEK_SET);

	std::string sbuf;
	sbuf.reserve(fSize);

	ArrayWrapper<char> buf(bufferSize);
	while (true)
	{
		unsigned int bytesRead = fread((void *)buf.data, 1, bufferSize, fHand);

		sbuf.append(buf.data, bytesRead);
		if (bytesRead < bufferSize)
		{
			break;
		}
	}
	return sbuf;
};