// TestFixture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Hex.h"
#include "TestParser.h"
#include "ResultParser.h"
#include "FileUtil.h"


void runTest(unsigned int hashLength)
{
	std::ostringstream commandS;
	commandS << "Keccak.exe ";
	if (hashLength != 512)
	{
		commandS << "-w=";
		commandS << hashLength;
		commandS << " ";
	}
	commandS << "tst2.txt >op";
	
	system(commandS.str().c_str());
}

int main(int argc, char* argv[])
{
	fileDataSource rsp(argv[1]);
	std::string testData = rsp.getData();
	std::vector<std::string> testLines = splitIntoLines(testData);

	TestParser tp;
	for (auto &l : testLines)
	{
		bool comp = tp.parseLine(l);
		if (comp)
		{
			test t = tp.getTestDetails();
			t.prepareInputFile();
			runTest(t.hashLength);

			ResultParser rp("op");
			rp.process();

			if (rp.getResString() == t.result)
			{
				std::cout << "Test matched! \n";
			}
			else
			{
				std::cout << "Test not matched. \n";
				std::cout << "Expected result: " << t.result << "\n";
				std::cout << "Actual result: " << rp.getResString() << "\n";
			}
		}
	}
	
    return 0;
}

