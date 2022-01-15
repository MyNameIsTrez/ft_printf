/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/15 19:00:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDIN_FILENO
#include <stdarg.h> // va_start, va_arg, va_end, va_copy
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		d;
	char	c;
	char	*s;

	va_start(arg_ptr, format);
	while (*format)
	{
		// printf("%c\n", *format);
		if (*format == 's')
		{
			s = va_arg(arg_ptr, char *);
			printf("string %s\n", s);
		}
		else if (*format == 'd')
		{
			d = va_arg(arg_ptr, int);
			printf("int %d\n", d);
		}
		else if (*format == 'c')
		{
			c = (char)va_arg(arg_ptr, int);
			printf("char %c\n", c);
		}
		format++;
	}
	va_end(arg_ptr);
	// write(STDOUT_FILENO, 's', 1);
	return (3);
}

////////////////////////////////////////////////////////////////////////////////
