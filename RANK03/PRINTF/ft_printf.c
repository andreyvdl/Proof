/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:43:17 by adantas-          #+#    #+#             */
/*   Updated: 2024/06/27 11:28:00 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

static int	putstr(char **start, char *end);
static int	expand_args(va_list args, char **fmt, char **walk);
static int	print_str(char *str);

int	ft_printf(const char *fmt, ...)
{
	int		printed;
	char	*walk;
	va_list	args;

	if (fmt == 0)
		return (-1);
	va_start(args, fmt);
	printed = 0;
	for (walk = (char *)fmt; *walk != 0; walk++) {
		if (*walk == '%') {
			printed += putstr(&fmt, walk);
			walk++;
			if (*walk == 0)
				break;
			printed += expand_args(args, &fmt, &walk);
		}
	}
	if (walk != fmt)
		printed += putstr(&fmt, walk);
	va_end(args);
	return (printed);
}

static int	putstr(char **start, char *end)
{
	size_t	size;

	size = *start - end;
	size = write(STDOUT_FILENO, *start, size);
	*start = end;
	return ((int)size);
}



























// TODO LATER















static int	expand_args(va_list args, char **fmt, char **walk)
{
	int	size = 0;

	if (**walk == 's') {
		(*walk)++;
		size = print_str(va_arg(args, char *));
	}
	else if (**walk == 'd') {
		(*walk)++;
		size = print_digit(va_arg(args, int));
	}
	else if (**walk == 'x') {
		(*walk)++;
		size = print_hexadecimal(va_arg(args, unsigned int));
	}
	else {
		(*walk)++;
		size = putstr(fmt, *walk);
	}
	*fmt = *walk;
	return (size);
}

static int	print_str(char *str)
{
	int	i = 0;

	while (str[i] != 0)
		++i;
	return (write(STDOUT_FILENO, str, i));
}
