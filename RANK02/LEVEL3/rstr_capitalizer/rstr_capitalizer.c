#include <unistd.h>

static void	rcapitalizer(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z' && \
		(*(str + 1) != ' ' && *(str + 1) != '\t' && *(str + 1) != '\0'))
			*str += 32;
		else if (*str >= 'a' && *str <= 'z' && \
		(*(str + 1) == ' ' || *(str + 1) == '\t' || *(str + 1) == '\0'))
			*str -= 32;
		write(STDOUT_FILENO, str, 1);
		str++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

int	main(int argc, char **argv)
{
	argv++;
	if (argc > 1)
	{
		while (*argv)
		{
			rcapitalizer(*argv);
			argv++;
		}
	}
	else
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
