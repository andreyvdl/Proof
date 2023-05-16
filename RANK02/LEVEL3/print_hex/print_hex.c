#include <unistd.h>

#define HEX "0123456789abcdef"

static void	print_hex(size_t nbr)
{
	if (nbr > 15)
		print_hex(nbr / 16);
	write(STDOUT_FILENO, &HEX[nbr % 16], 1);
}

static size_t	ft_atoi(char *str)
{
	size_t	nbr;

	while ((*str == ' ' || *str == '\t') && *str != '\0')
		str++;
	nbr = 0;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
