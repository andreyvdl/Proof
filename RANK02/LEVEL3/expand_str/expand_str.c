#include <unistd.h>

static void	expand_str(char *str)
{
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		while (*str != ' ' && *str != '\t' && *str != '\0')
		{
			write(STDOUT_FILENO, str, 1);
			str++;
		}
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str != '\0')
			write(STDOUT_FILENO, "   ", 3);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
