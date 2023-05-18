#include <unistd.h>

static void	capitalize(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
	write(STDOUT_FILENO, str, 1);
	while (*str != '\0')
	{
		str++;
		if ((*str >= 'A' && *str <= 'Z') && \
		(*(str - 1) != ' ' && *(str - 1) != '\t'))
			*str += 32;
		else if ((*str >= 'a' && *str <= 'z') && \
		(*(str - 1) == ' ' || *(str - 1) == '\t'))
			*str -= 32;
		write(STDOUT_FILENO, str, 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}

int main(int argc, char **argv)
{
	argv++;
	if (argc > 1)
	{
		while (*argv)
		{
			capitalize(*argv);
			argv++;
		}
	}
	else
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
