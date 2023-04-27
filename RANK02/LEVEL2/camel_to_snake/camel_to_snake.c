#include <unistd.h>

//N tem nenhum exemplo invalido, entao cosiderei todos os inputs validos.

static void	print_in_snake(char *string);

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_in_snake(argv[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

static void	print_in_snake(char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
		{
			string[index] += 32;
			write(STDOUT_FILENO, "_", 1);
		}
		write(STDOUT_FILENO, &string[index], 1);
		index++;
	}
}
