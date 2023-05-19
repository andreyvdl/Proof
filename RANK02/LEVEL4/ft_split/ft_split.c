#include <stdlib.h>

static int	count_words(char *str)
{
	int	words;

	words = 0;
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str != '\0')
			words++;
		while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0')
			str++;
	}
	return (words);
}

static char	*extract_word(char *str)
{
	int		size;
	int		loop;
	char	*word;

	size = 0;
	while (str[size] != ' ' && str[size] != '\t' && str[size] != '\n' && \
	str[size] != '\0')
		size++;
	word = (char *)malloc(sizeof(char) * (size + 1));
	word[size] = '\0';
	loop = 0;
	while (loop != size)
	{
		word[loop] = *str;
		loop++;
		str++;
	}
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	int		words;
	char	**matrix;

	if (str == NULL)
		return (NULL);
	words = count_words(str);
	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (matrix);
	matrix[words] = NULL;
	i = 0;
	while (i != words)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		matrix[i] = extract_word(str);
		while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0')
			str++;
		i++;
	}
	return (matrix);
}
