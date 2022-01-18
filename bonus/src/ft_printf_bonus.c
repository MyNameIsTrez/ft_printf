/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/18 17:46:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDIN_FILENO
#include <stdarg.h> // va_start, va_arg, va_end, va_copy
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////

char	*get_char(t_options *options);
char	*get_string(t_options *options);
char	*get_pointer(t_options *options);
char	*get_decimal(t_options *options);
char	*get_decimal(t_options *options);
char	*get_unsigned(t_options *options);
char	*get_hex_lower(t_options *options);
char	*get_hex_upper(t_options *options);
char	*get_percent(t_options *options);

const t_conversion_function	*get_conversion_table(void)
{
	const static t_conversion_function	conversion_table[] = {
	['c'] = get_char,
	['s'] = get_string,
	['p'] = get_pointer,
	['d'] = get_decimal,
	['i'] = get_decimal,
	['u'] = get_unsigned,
	['x'] = get_hex_lower,
	['X'] = get_hex_upper,
	['%'] = get_percent,
	};

	return (conversion_table);
}

void	fix_priorities(t_options *options)
{
	if (options->flags.zero_fill && options->precision >= 0)
	{
		options->flags.zero_fill = false;
	}
}

void	parse_flags(t_options *options, char **format)
{
	while (**format != '\0' && ft_strchr(FLAGS, **format) == NULL)
	{
		if (**format == '#')
			options->flags.alternate = true;
		if (**format == '0')
			options->flags.zero_fill = true;
		if (**format == '-')
			options->flags.aligned_left = true;
		if (**format == ' ')
			options->flags.plus_space = true;
		if (**format == '+')
			options->flags.plus_sign = true;
		(*format)++;
	}
}

void	initialize_options(t_options *options)
{
	options->flags.alternate = false;
	options->flags.zero_fill = false;
	options->flags.aligned_left = false;
	options->flags.plus_space = false;
	options->flags.plus_sign = false;
	options->field_width = 0;
	options->precision = -1;
}

void	get_options(char **format, t_options *options)
{
	initialize_options(options);
	parse_flags(options, format);
	parse_field_width(options, format);
	parse_precision(options, format);
	fix_priorities(options);
}

int	print_argument(char *format, t_options *options)
{
	const t_conversion_function	*conversion_table = get_conversion_table();
	char						*str;
	int							chars_printed;

	chars_printed = 0;
	str = conversion_table[*format](options);
	chars_printed += ft_strlen(str);
	return (chars_printed);
}

int	ft_printf(const char *format, ...)
{
	t_options	options;
	int			chars_printed;

	chars_printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			get_options(&format, &options);
			chars_printed += print_argument(format, &options);
		}
		format++;
	}
	return (chars_printed);
}

// int	ft_printf(char *format, ...)
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
