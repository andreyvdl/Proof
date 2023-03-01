#include <unistd.h>
#define NUMS "0123456789"

void putnbr(int i)
{
	if (i > 9)
		putnbr(i / 10);
	write(1, &NUMS[i % 10], 1);
}

int main(void)
{
	for (int i = 1; i < 101; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else
		{
			putnbr(i);
			write(1, "\n", 1);
		}
	}

	return (0);
}