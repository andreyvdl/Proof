int	ft_strcmp(char *s1, char *s2)
{
	int	indx;

	indx = 0;
	while (s1[indx] != '\0' && s2[indx] != '\0' && s1[indx] == s2[indx])
		indx++;
	return (s1[indx] - s2[indx]);
}
