#include <unistd.h>

static void	putnbr(int n)
{
	char	digit;

	if (n > 9)
		putnbr(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	putnbr(argc - 1);
	write(1, "\n", 1);
	(void)argv;
	return (0);
}
