#include <unistd.h>

static size_t	ft_strlen(char *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

static void	print_this(char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == ' ' || string[index] == '\t')
			break;
		write(STDOUT_FILENO, &string[index], 1);
		index++;
	}
}

static void	print_last_word(char *string)
{
	size_t	size;

	size = ft_strlen(string);
	if (size > 0 && string[size] == '\0')
		size--;
	while (size > 0 && (string[size] == ' ' || string[size] == '\t'))
		size--;
	while (size > 0 && (string[size] != ' ' && string[size] != '\t'))
		size--;
	if (string[size] != '\0')
	{
		if (string[size] != ' ' && string[size] != '\t')
			print_this(&string[size]);
		else if (string[size + 1] != ' ' && string[size + 1] != '\t' \
		&& string[size + 1] != '\0')
			print_this(&string[size + 1]);
	}
}

int	main(int arg_count, char **arg_verb)
{
	if (arg_count == 2)
		print_last_word(arg_verb[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
