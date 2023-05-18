#include <unistd.h>
#include <stdlib.h>

static int	ft_atoi(char *str)
{
	int	nbr;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		return (0);
	else if (*str == '+')
		str++;
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if (nbr < 1)
		return (0);
	return (nbr);
}

static void	base_cases(int nbr)
{
	if (nbr <= 1)
		write(STDOUT_FILENO, "0\n", 2);
	else if (nbr < 3)
		write(STDOUT_FILENO, "2\n", 2);
	else if (nbr < 5)
		write(STDOUT_FILENO, "5\n", 2);
	else if (nbr < 7)
		write(STDOUT_FILENO, "10\n", 3);
	else
		write(STDOUT_FILENO, "17\n", 3);
}

static void	print_nbr(int nbr)
{
	char	c;

	if (nbr > 9)
		print_nbr(nbr / 10);
	c = nbr % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

static void	prime_sum(int nbr)
{
	int	prime;

	prime = 2;
	if (nbr < 11)
		base_cases(nbr);
	else if (nbr > 411232)
		write(STDOUT_FILENO, "0\n", 2);
	else
	{
		while (nbr > 2)
		{
			if ((nbr % 2 == 0  && nbr > 2) || (nbr % 3 == 0 && nbr > 3) || \
			(nbr % 5 == 0 && nbr > 5) || (nbr % 7 == 0 && nbr > 7))
				nbr--;
			else
			{
				prime += nbr;
				nbr--;
			}
		}
		print_nbr(prime);
		write(STDOUT_FILENO, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		prime_sum(nbr);
	}
	else
		write(STDOUT_FILENO, "0\n", 2);
	exit(0);
}
