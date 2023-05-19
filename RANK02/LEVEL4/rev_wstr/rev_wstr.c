#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while (*end != '\0')
		end++;
	return (end - str);
}

static void	print_word(char *str)
{
	while (*str != '\0' && *str != ' ' && *str != '\t')
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
	write(STDOUT_FILENO, " ", 1);
}

static void	print_last_word(char *str)
{
	while (*str != '\0' && *str != ' ' && *str != '\t')
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

static void	reverse_printing(char *str)
{
	size_t	index;

	index = ft_strlen(str);
	index--;
	while (index > 0)
	{
		while ((str[index] != ' ' && str[index] != '\t') && index > 0)
			index--;
		if (index == 0)
			break ;
		print_word(str + index + 1);
		while ((str[index] == ' ' || str[index] == '\t') && index > 0)
			index--;
	}
	print_last_word(str);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		reverse_printing(argv[1]);
	else
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
