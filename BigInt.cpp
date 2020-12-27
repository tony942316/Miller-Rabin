#include "BigInt.h"

#include <iostream>

BigInt::BigInt()
{
	num.reset();
}

void BigInt::PrintNum()
{
	std::cout << num << '\n';
}

void BigInt::AddNum(unsigned long long y)
{

}

void BigInt::inc(int start)
{
	for (int i = start; i < num.size(); i++)
	{
		if (num[i] == 0)
		{
			num[i] = 1;
			break;
		}
		else
		{
			num[i] = 0;
		}
	}
}

void BigInt::translate(unsigned long long y)
{
	std::bitset<64> newY;
	newY.reset();
	while ((y % 2) == 0);
}

//unsigned long long expon(unsigned int x, unsigned int y)
//{
//	unsigned long long answer = 1;
//	while (y != 0)
//	{
//		answer *= x;
//		y--;
//	}
//	return answer;
//}
