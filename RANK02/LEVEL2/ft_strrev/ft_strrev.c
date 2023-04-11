#define NULL ((void *)0)

typedef unsigned long int	t_size;

static t_size	ft_strlen(char *string)
{
	t_size	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

char	*ft_strrev(char *str)
{
	t_size	index;
	t_size	size;
	char	temp;

	if (str == NULL)
		return (str);
	index = 0;
	size = ft_strlen(str) - 1;
	while (index < size)
	{
		temp = str[index];
		str[index] = str[size];
		str[size] = temp;
		index++;
		size--;
	}
	return (str);
}
