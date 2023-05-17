#include <stdbool.h>

#define HEX "0123456789abcdef"

static bool	is_hex(char c)
{
	if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (true);
	else if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static int	negative(const char *str, int base)
{
	int		nbr;

	nbr = 0;
	while (is_hex(*str) && *str <= HEX[base - 1])
	{
		if (*str >= 'a' && *str <= 'f')
			nbr = nbr * base + (*str - 'a' + 10);
		else if (*str >= 'A' && *str <= 'F')
			nbr = nbr * base + (*str - 'A' + 10);
		else
			nbr = nbr * base + (*str - '0');
		str++;
	}
	return (-nbr);
}

static int	positive(const char *str, int base)
{
	int nbr;

	if (*str == '+')
		str++;
	nbr = 0;
	while (is_hex(*str) && *str <= HEX[base - 1])
	{
		if (*str >= 'a' && *str <= 'f')
			nbr = nbr * base + (*str - 'a' + 10);
		else if (*str >= 'A' && *str <= 'F')
			nbr = nbr * base + (*str - 'A' + 10);
		else
			nbr = nbr * base + (*str - '0');
		str++;
	}
	return (nbr);
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (str_base <= 1)
		return (0);
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '\0')
		return (0);
	else if (*str == '-')
		return (negative(str + 1, str_base));
	else
		return (positive(str, str_base));
}
