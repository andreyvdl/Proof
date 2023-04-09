#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

static int	ft_isspace(char character)
{
	if (character == ' ' || character == '\t')
		return (TRUE);
	else if (character == '\v' || character == '\r')
		return (TRUE);
	else if (character == '\f' || character == '\n')
		return (TRUE);
	return (FALSE);
}

static void	increment_whitespaces(char *string, int	*index)
{
	while (string[*index] != '\0')
	{
		if (ft_isspace(string[*index]) == FALSE)
			break ;
		(*index)++;
	}
	if (string[*index] != '\0')
		(*index)++;
}

static int	ft_isnum(char character)
{
	if (character >= '0' && character <= '9')
		return (TRUE);
	return (FALSE);
}

static int	negative_return(char *string, int *index)
{
	int	result;

	result = 0;
	while (string[*index] != '\0')
	{
		if (ft_isnum(string[*index]) == FALSE)
			break ;
		result += string[*index] - '0';
		(*index)++;
	}
	return (result * -1);
}

static int	convert_to_int(char *string, int *index)
{
	int	result;

	result = 0;
	while (string[*index] != '\0')
	{
		if (ft_isnum(string[*index]) == FALSE)
			break ;
		result += string[*index] - '0';
		(*index)++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	index;

	if (str == NULL)
		return (0);
	index = 0;
	increment_whitespaces((char *)str, &index);
	if (str[index] == '-')
	{
		index++;
		return (negative_return((char *)str, &index));
	}
	else if (str[index] == '+')
		index++;
	return (convert_to_int((char *)str, &index));
}
