#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	static char	reference;

	if (tab == 0x0 || \
	(begin.x < 0 || begin.x >= size.x) || (begin.y < 0 || begin.y >= size.y))
		return ;
	if (reference == '\0')
		reference = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == reference)
		flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == reference)
		flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == reference)
		flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == reference)
		flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
}

#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
