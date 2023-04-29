unsigned int	hcf(unsigned int a, unsigned int b, unsigned int factor);

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a * b) / hcf(a, b, 2));
}

unsigned int	hcf(unsigned int a, unsigned int b, unsigned int factor)
{
	if (a == 1 || b == 1 || factor < 2)
		return (1);
	while (factor > 1 && factor <= a && factor <= b)
	{
		if (a % factor == 0 && b % factor == 0)
			return (factor * hcf(a / factor, b / factor, factor));
		factor++;
	}
	return (1);
}
