#include "stdafx.h"

std::vector<std::string> splitIntoLines(std::string &in)
{
	std::string buf;
	std::vector<std::string> lines;

	for (unsigned int i = 0; i != in.length(); i++)
	{
		if (in[i] == '\n')
		{
			buf.shrink_to_fit();
			lines.push_back(buf);
			buf = std::string();
			buf.reserve(1024);
		}
		else if (in[i] == '\r')
		{
		}
		else
		{
			buf.append(1, in[i]);
		}
	}
	if (buf.length() > 0) {
		lines.push_back(buf);
	}

	return lines;
}