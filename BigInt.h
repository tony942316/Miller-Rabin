#pragma once

#include <bitset>

// This is where the idea for the 128 bit Integer was born
// This is not relevent to the Miller-Rabin test work for this has moved to tLib

class BigInt
{
public:
	BigInt();
	void PrintNum();
	void AddNum(unsigned long long y);
public:
	void operator+=(unsigned long long y)
	{
		if ((y % 2) != 0)
		{
			inc();
			y--;
		}
		inc(factorTwos(&y));
		for (int i = 0; i < y - 1; i++)
		{
			inc();
		}

	}
	unsigned short factorTwos(unsigned long long* num)
	{
		unsigned short count = 0;
		while (*num % 2 == 0)
		{
			*num = *num / 2;
			count++;
		}
		return count;
	}
//private:
	void inc(int start = 0);
	void translate(unsigned long long y);
	//unsigned long long expon(unsigned int x, unsigned int y);
private:
	std::bitset<128> num;
};

