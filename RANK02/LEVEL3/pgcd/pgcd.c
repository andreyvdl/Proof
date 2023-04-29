#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b);

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		/* if (validation(argv[1]) && validation(argv[2]))
			pgcd(atoi(argv[1]), atoi(argv[2])); */
		pgcd(atoi(argv[1]), atoi(argv[2]));
	}
	printf("\n");
	return (0);
}

/* Validar se o int é válido é muito dificil...
int	validation(char *str)
{
	size_t	nbr;

	if (str_is_invalid(str))
		return (0);
	nbr = (size_t)atoi(str);
	if (nbr > __INT_MAX__)
		return (0);
	return (1);
}

int	str_is_invalid(char *str)
{
	while (*str != '\0' && (*str == ' ' || *str == '\t'))
		str++;
	if (*str == '-' || *str == '\0')
		return (1);
	else if (*str == '+')
		str++;
	if (*str == '\0')
		return (1);
	else if (*str == '0' && *(str + 1) == '0')
	{
		while (*str == '0')
			str++;
	}
	while (*str >= '0' && *str <= '9')
		str++;
} */

void	pgcd(int a, int b)
{
	int				div;
	unsigned int	biggest;
	
	if (a <= 0 || b <= 0)
		return ;
	else if (a == 1 || b == 1)
	{
		printf("1");
		return ;
	}
	biggest = 1;
	div = 2;
	while (div > 1 && div <= a && div <= b)
	{
		if (a % div == 0 && b % div == 0)
			biggest = div;
		div++;
	}
	printf("%d", biggest);
}
