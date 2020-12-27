#include <iostream>
#include <conio.h>

//#include "BigInt.h"

void Miller_Rabin(unsigned int n, unsigned int a);
unsigned short factorTwos(unsigned int* num);
unsigned long long expon(unsigned int x, unsigned int y);

// Miller-Rabin test for primality 
// Did this in 3 hours to answer a question on the cse 1729 forum lol

int main()
{
	//BigInt hello;
	//hello.PrintNum();
	//hello + 5;
	//hello.PrintNum();
	//hello + 12;
	//hello.PrintNum();
	unsigned int n = 0;
	unsigned int a = 25;
	double temp = 0.0;
	temp = pow(9, 21);
	std::cout << "Welcome to the Miller-Rabin test for primality!\n";
	std::cout << "Please input a non negative odd number to be tested: ";
	std::cin >> n;
	std::cout << '\n';
	for (int i = 2; i < (n - 1); i++)
	{
		std::cout << '[' << i << "]: ";
		Miller_Rabin(n, i);
	}
	std::cout << "\nThank you for using the Miller-Rabin test for primality!\n";
	std::cout << "Press any key to Exit!\n";
	_getch();
	return 0;
}

void Miller_Rabin(unsigned int n, unsigned int a)
{
	unsigned int m = 0;
	unsigned int k = 0;
	unsigned int b = 0;
	m = n - 1;
	k = factorTwos(&m);
	b = expon(a, m) % n;
	if ((n % 2) == 0)
	{
		std::cout << "Even numbers can't be prime!\n";
	}
	else if ((b == 1) || (b == (n - 1)))
	{
		std::cout << n << " is probably prime!\n";
	}
	else
	{
		for (unsigned int i = 0; i < k; i++)
		{
			b = (b * b) % n;
			if (b == 1)
			{
				std::cout << n << " is not prime.\n";
				break;
			}
			else if (b == (n - 1))
			{
				std::cout << n << " is probably prime!\n";
				break;
			}
			else if (i == k - 1)
			{
				std::cout << n << " is not prime.\n";
				break;
			}
		}
	}
}

unsigned short factorTwos(unsigned int* num)
{
	unsigned short count = 0;
	while ((*num) % 2 == 0)
	{
		(*num) = (*num) / 2;
		count++;
	}
	return count;
}


// 
unsigned long long expon(unsigned int x, unsigned int y)
{
	unsigned long long answer = 1;
	while (y != 0)
	{
		answer *=  x;
		y--;
	}
	return answer;
}