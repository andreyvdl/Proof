#include <stdio.h>
#include <stdlib.h>

static int	ft_isprime(int nbr)
{
	if (nbr == 2)
		return (1);
	else if (nbr == 3)
		return (1);
	else if (nbr == 5)
		return (1);
	else if (nbr == 7)
		return (1);
	else if (nbr % 2 != 0 && nbr % 3 != 0 && nbr % 5 != 0 && nbr % 7 != 0)
		return (1);
	return (0);
}

static int	basic_cases(int nbr)
{
	if (nbr < 0)
	{
		printf("\n");
		return (1);
	}
	else if (nbr <= 1)
	{
		printf("%d\n", nbr);
		return (1);
	}
	else if (ft_isprime(nbr))
	{
		printf("%d\n", nbr);
		return (1);
	}
	return (0);
}

static void	print_prime_factors(int nbr)
{
	int	factor;

	if (basic_cases(nbr))
		return ;
	factor = 2;
	while (factor <= nbr)
	{
		if (nbr % factor == 0 && ft_isprime(factor))
		{
			printf("%d", factor);
			nbr /= factor;
			if (nbr > 1)
				printf("*");
		}
		else
			factor++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_prime_factors(atoi(argv[1]));
	else
		printf("\n");
	return (0);
}
