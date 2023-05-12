#include <unistd.h>

static void	print_nbr(int nbr)
{
	char	c;

	if (nbr > 9)
		print_nbr(nbr / 10);
	c = nbr % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

static int	convert_number(char *string)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	while (string[index])
	{
		result = result * 10 + (string[index] - '0');
		index++;
	}
	return (result);
}

static unsigned int	get_str_size(char *string)
{
	unsigned int	size;

	size = 0;
	while (string[size])
		size++;
	return (size);
}

static void	print_table(int count, unsigned int size, int nbr, char *string)
{
	int			result;

	result = count * nbr;
	print_nbr(count);
	write(STDOUT_FILENO, " x ", 3);
	write(STDOUT_FILENO, string, size);
	write(STDOUT_FILENO, " = ", 3);
	print_nbr(result);
	write(STDOUT_FILENO, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	count;
	int	size;
	int	nbr;

	if (argc == 2)
	{
		count = 1;
		size = get_str_size(argv[1]);
		nbr = convert_number(argv[1]);
		while (count < 10)
		{
			print_table(count, size, nbr, argv[1]);
			count++;
		}
	}
	else
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
