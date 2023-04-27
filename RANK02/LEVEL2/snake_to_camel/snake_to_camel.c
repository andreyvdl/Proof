#include <unistd.h>

static void	print_camel(char *string);

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_camel(argv[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

static void	print_camel(char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '_')
		{
			index++;
			string[index] -= 32;
		}
		write(STDOUT_FILENO, &string[index], 1);
		index++;
	}
}
