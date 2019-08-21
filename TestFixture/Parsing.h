#pragma once

static inline bool isHexDigit(const char c)
{
	if (((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'F')) | ((c >= 'a') && (c <= 'f')))
	{
		return true;
	}
	return false;
}

static inline bool isDecimal(const char a)
{
	if (a >= '0' && a <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

class StringContext
{
public:
	StringContext(std::string &a) : content(a)
	{
		offset = 0;
	};
	StringContext(const StringContext &a) : content(a.content)
	{
		offset = a.offset;
	};
	void operator=(const StringContext &a)
	{
		content = a.content;
		offset = a.offset;
	};
	char getChar()
	{
		return content[offset];
	};
	void advance(unsigned int i)
	{
		offset += i;
	};
	bool checkLengthSufficient(unsigned int i)
	{
		if (offset + i < content.length())
		{
			return true;
		}
		else
		{
			return false;
		}
	};
private:
	std::string &content;
	unsigned int offset;
};

template<typename T1>
bool matchString(T1 &ctx, std::string &b)
{
	T1 ctx2 = ctx;
	if (ctx2.checkLengthSufficient(b.length()))
	{
		auto i = b.begin();

		while (i != b.end())
		{
			if (ctx2.getChar() != *i)
			{
				return false;
			}
			i++;
			ctx2.advance(1);
		}
		ctx = ctx2;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T1>
std::pair<bool, std::string> hexString(T1 &ctx)
{
	std::pair<bool, std::string> res;
	res.first = false;

	if (!isHexDigit(ctx.getChar()))
	{
		return res;
	}
	else
	{
		res.first = true;
		res.second.append(1, ctx.getChar());
		ctx.advance(1);

		while (ctx.checkLengthSufficient(0) && isHexDigit(ctx.getChar()))
		{
			res.second.append(1, ctx.getChar());

			ctx.advance(1);
		}
		return res;

	}
}

template<typename T1>
std::pair<bool, unsigned int> parseUInt(T1 &ctx)
{
	std::pair<bool, unsigned int> res;
	res.first = false;

	if (!isDecimal(ctx.getChar()))
	{
		return res;
	}
	else
	{
		res.first = true;
		res.second = ctx.getChar() - '0';
		ctx.advance(1);

		while (ctx.checkLengthSufficient(0) && isDecimal(ctx.getChar()))
		{
			res.second *= 10;
			res.second += ctx.getChar() - '0';

			ctx.advance(1);
		}
		return res;
	}
}

std::vector<std::string> splitIntoLines(std::string &in);
