#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1

#define SUCCESS 0

int	can_fit_in_a_int(char *number)
{
	long int	compare;

	compare = (long int)atoi(number);
	if (compare > __INT_MAX__ || compare < -(__INT_MAX__) - 1)
		return (FALSE);
	return (TRUE);
}

int	operator_is_valid(char *operator)
{
	if (operator[0] == '\0')
		return (FALSE);
	if (operator[1] != '\0')
		return (FALSE);
	if (operator[0] == '+')
		return (TRUE);
	if (operator[0] == '-')
		return (TRUE);
	if (operator[0] == '*')
		return (TRUE);
	if (operator[0] == '/')
		return (TRUE);
	if (operator[0] == '%')
		return (TRUE);
	return (FALSE);
}

int	validator(char *first_number, char *operator, char *second_number)
{
	if (first_number == NULL || can_fit_in_a_int(first_number) == FALSE)
		return (FALSE);
	if (second_number == NULL || can_fit_in_a_int(second_number) == FALSE)
		return (FALSE);
	if (operator == NULL || operator_is_valid(operator) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	do_the_math(char *first_number, char operator, char *second_number)
{
	if (operator == '+')
		printf("%d", atoi(first_number) + atoi(second_number));
	else if (operator == '-')
		printf("%d", atoi(first_number) - atoi(second_number));
	else if (operator == '*')
		printf("%d", atoi(first_number) * atoi(second_number));
	else if (operator == '/')
	{
		if (atoi(second_number) != 0)
			printf("%d", atoi(first_number) / atoi(second_number));
	}
	else if (operator == '%')
	{
		if (atoi(second_number) != 0)
			printf("%d", atoi(first_number) % atoi(second_number));
	}
}

int	main(int arg_count, char **arg_verb)
{
	if (arg_count == 4)
	{
		if (validator(arg_verb[1], arg_verb[2], arg_verb[3]) == TRUE)
			do_the_math(arg_verb[1], arg_verb[2][0], arg_verb[3]);
	}
	printf("\n");
	return (SUCCESS);
}
