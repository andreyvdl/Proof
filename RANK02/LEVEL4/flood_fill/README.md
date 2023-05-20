# EN-US

> Assignment name  : flood_fill   
> Expected files   : *.c, *.h   
> Allowed functions: -   
> 
> --------------------------------------------------------------------------------   
> 
> Write a function that takes a char ** as a 2-dimensional array of char, a   
> t_point as the dimensions of this array and a t_point as the starting point.   
> 
> Starting from the given 'begin' t_point, this function fills an entire zone   
> by replacing characters inside with the character 'F'. A zone is an group of   
> the same character delimitated horizontally and vertically by other characters   
> or the array boundry.   
> 
> The flood_fill function won't fill diagonally.   
> 
> The flood_fill function will be prototyped like this:   
>   `void  flood_fill(char **tab, t_point size, t_point begin);`   
> 
> The t_point structure is prototyped like this:   
>
> ```c
>   typedef struct  s_point   
>   {   
>     int           x;   
>     int           y;   
>   }               t_point;   
> ```
> 
> Example:   
>
> ```sh
> $> cat test.c
> #include <stdlib.h>
> #include <stdio.h>
> #include "flood_fill.h"
> 
> char** make_area(char** zone, t_point size)
> {
> 	char** new;
> 
> 	new = malloc(sizeof(char*) * size.y);
> 	for (int i = 0; i < size.y; ++i)
> 	{
> 		new[i] = malloc(size.x + 1);
> 		for (int j = 0; j < size.x; ++j)
> 			new[i][j] = zone[i][j];
> 		new[i][size.x] = '\0';
> 	}
> 
> 	return new;
> }
> 
> int main(void)
> {
> 	t_point size = {8, 5};
> 	char *zone[] = {
> 		"11111111",
> 		"10001001",
> 		"10010001",
> 		"10110001",
> 		"11100001",
> 	};
> 
> 	char**  area = make_area(zone, size);
> 	for (int i = 0; i < size.y; ++i)
> 		printf("%s\n", area[i]);
> 	printf("\n");
> 
> 	t_point begin = {7, 4};
> 	flood_fill(area, size, begin);
> 	for (int i = 0; i < size.y; ++i)
> 		printf("%s\n", area[i]);
> 	return (0);
> }
> ```
>
> ```sh
> $> gcc flood_fill.c test.c -o test; ./test
> 11111111
> 10001001
> 10010001
> 10110001
> 11100001
> 
> FFFFFFFF
> F000F00F
> F00F000F
> F0FF000F
> FFF0000F
> ```

# PT-BR

> Assignment name  : flood_fill   
> Expected files   : *.c, *.h   
> Allowed functions: -   
> 
> --------------------------------------------------------------------------------   
>
> Escreva uma função que recebe um char ** como um array de char bi-dimensional,   
> um t_point como as dimensões deste array e um t_point como ponto de partida.   
>
> Começando do t_point 'begin' dado, esta função preenche uma zona inteira   
> substituindo os caracteres dentro dela pelo caractere 'F'. Uma zona é um   
> grupo de caracteres iguais delimitados horizontalmente e verticalmente por   
> outros caracteres ou pela borda do array.   
>
> A função flood_fill não preencherá diagonalmente.   
>
> A função flood_fill será prototipada assim:   
>   `void  flood_fill(char **tab, t_point size, t_point begin);`   
>
> A estrutura t_point é prototipada assim:   
>
> ```c
>   typedef struct  s_point   
>   {   
>     int           x;   
>     int           y;   
>   }               t_point;   
> ```
> 
> Exemplo:   
>
> ```sh
> $> cat test.c
> #include <stdlib.h>
> #include <stdio.h>
> #include "flood_fill.h"
> 
> char** make_area(char** zone, t_point size)
> {
> 	char** new;
> 
> 	new = malloc(sizeof(char*) * size.y);
> 	for (int i = 0; i < size.y; ++i)
> 	{
> 		new[i] = malloc(size.x + 1);
> 		for (int j = 0; j < size.x; ++j)
> 			new[i][j] = zone[i][j];
> 		new[i][size.x] = '\0';
> 	}
> 
> 	return new;
> }
> 
> int main(void)
> {
> 	t_point size = {8, 5};
> 	char *zone[] = {
> 		"11111111",
> 		"10001001",
> 		"10010001",
> 		"10110001",
> 		"11100001",
> 	};
> 
> 	char**  area = make_area(zone, size);
> 	for (int i = 0; i < size.y; ++i)
> 		printf("%s\n", area[i]);
> 	printf("\n");
> 
> 	t_point begin = {7, 4};
> 	flood_fill(area, size, begin);
> 	for (int i = 0; i < size.y; ++i)
> 		printf("%s\n", area[i]);
> 	return (0);
> }
> ```
>
> ```sh
> $> gcc flood_fill.c test.c -o test; ./test
> 11111111
> 10001001
> 10010001
> 10110001
> 11100001
> 
> FFFFFFFF
> F000F00F
> F00F000F
> F0FF000F
> FFF0000F
> ```
