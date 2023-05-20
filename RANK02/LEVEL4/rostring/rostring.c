#include <unistd.h>
#include <stdlib.h>

static void	print_string(char *str)
{
	while ((*str == ' ' || *str == '\t') && *str != '\0')
		str++;
	while (*str != ' ' && *str != '\t' && *str != '\0')
		str++;
	while ((*str == ' ' || *str == '\t') && *str != '\0')
		str++;
	if (*str == '\0')
		return ;
	while (*str != '\0')
	{
		while (*str != ' ' && *str != '\t' && *str != '\0')
		{
			write(STDOUT_FILENO, str, 1);
			str++;
		}
		while ((*str == ' ' || *str == '\t') && *str != '\0')
			str++;
		if (*str != '\0')
			write(STDOUT_FILENO, " ", 1);
	}
	if (*str == '\0')
		write(STDOUT_FILENO, " ", 1);
}

static void	print_first_word(char *str)
{
	while ((*str == ' ' || *str == '\t') && *str != '\0')
		str++;
	while (*str != ' ' && *str != '\t' && *str != '\0')
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		print_string(argv[1]);
		print_first_word(argv[1]);
	}
	else
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
