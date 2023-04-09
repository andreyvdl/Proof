#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 0

int	can_print(char *string, char *available_chars)
{
	size_t	chars_index;
	size_t	string_index;

	chars_index = 0;
	string_index = 0;
	while (string[string_index] != '\0')
	{
		while (available_chars[chars_index] != '\0')
		{
			if (string[string_index] == available_chars[chars_index])
				break ;
			chars_index++;
		}
		if (available_chars[chars_index] == '\0')
			return (FALSE);
		string_index++;
	}
	return (TRUE);
}

size_t	ft_strlen(char *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

int	main(int arg_count, char **arg_verb)
{
	if (arg_count == 3)
	{
		if (can_print(arg_verb[1], arg_verb[2]) == TRUE)
			write(STDOUT_FILENO, arg_verb[1], ft_strlen(arg_verb[1]));
	}
	write(STDOUT_FILENO, "\n", 1);
	return (SUCCESS);
}
