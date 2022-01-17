/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/17 17:30:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDIN_FILENO
#include <stdarg.h> // va_start, va_arg, va_end, va_copy
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////

int	ft_printf(const char *format, ...)
{
	const struct {int width; int precision} options = {
		.width = 0,
		.precision = -1,
	}
	while (*format)
	{
		if (*format == '%')
		{
			enter_options(format, options);
			filter_by_priorities(options);
			print
			reset_options(options);
		}
		format++;
	}
	return (42);
}

// int	ft_printf(const char *format, ...)
// {
// 	va_list	arg_ptr;
// 	int		d;
// 	char	c;
// 	char	*s;

// 	va_start(arg_ptr, format);
// 	while (*format)
// 	{
// 		// printf("%c\n", *format);
// 		if (*format == 's')
// 		{
// 			s = va_arg(arg_ptr, char *);
// 			printf("string %s\n", s);
// 		}
// 		else if (*format == 'd')
// 		{
// 			d = va_arg(arg_ptr, int);
// 			printf("int %d\n", d);
// 		}
// 		else if (*format == 'c')
// 		{
// 			c = (char)va_arg(arg_ptr, int);
// 			printf("char %c\n", c);
// 		}
// 		format++;
// 	}
// 	va_end(arg_ptr);
// 	// write(STDOUT_FILENO, 's', 1);
// 	return (3);
// }

////////////////////////////////////////////////////////////////////////////////
