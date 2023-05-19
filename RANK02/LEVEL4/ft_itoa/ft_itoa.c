#include <stdlib.h>

static char	*int_min_case(void)
{
	int		nbr;
	int		size;
	char	*array;

	nbr = __INT_MAX__;
	size = 11;
	array = (char *)malloc(sizeof(char) * size + 1);
	if (array == NULL)
		return (array);
	array[0] = '-';
	array[size] = '\0';
	array[size - 1] = nbr % 10 + '1';
	nbr /= 10;
	size -= 2;
	while (size != 0)
	{
		array[size] = nbr % 10 + '0';
		nbr /= 10;
		size--;
	}
	return (array);
}

static int	count_digits(char nbr)
{
	int	digits;

	digits = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

static char	*negative(int nbr)
{
	int		digits;
	char	*array;

	digits = count_digits(nbr);
	array = (char *)malloc(sizeof(char) * (digits + 2));
	if (array == NULL)
		return (array);
	array[0] = '-';
	array[digits] = '\0';
	digits--;
	while (digits != 0)
	{
		array[digits] = (nbr % 10) + '0';
		nbr /= 10;
		digits--;
	}
	return (array);
}

char	*ft_itoa(int nbr)
{
	int		digits;
	char	*array;

	if (nbr == (__INT_MAX__ * -1) - 1)
		return (int_min_case());
	else if (nbr < 0)
		return (negative(nbr * -1));
	digits = count_digits(nbr);
	array = (char *)malloc(sizeof(char) * (digits + 1));
	if (array == NULL)
		return (array);
	array[digits] = '\0';
	digits--;
	while (digits != 0)
	{
		array[digits] = (nbr % 10) + '0';
		nbr /= 10;
		digits--;
	}
	array[0] = nbr + '0';
	return (array);
}
