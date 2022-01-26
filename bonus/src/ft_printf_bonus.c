/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/26 12:18:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

// #include <unistd.h> // write, STDOUT_FILENO
// #include <stdarg.h> // va_start, va_arg, va_end, va_copy

// ////////////////////////////////////////////////////////////////////////////////

// char	*get_char(char **format, t_options *options);
// char	*get_string(char **format, t_options *options);
// char	*get_pointer(char **format, t_options *options);
// char	*get_decimal(char **format, t_options *options);
// char	*get_decimal(char **format, t_options *options);
// char	*get_unsigned(char **format, t_options *options);
// char	*get_hex_lower(char **format, t_options *options);
// char	*get_hex_upper(char **format, t_options *options);
// char	*get_percent(char **format, t_options *options);

// void	print_with_padding(char *conversion_str, t_options *options,
// 								int total_width)
// {
// 	// write(STDOUT_FILENO, buffer, byte_count);
// }

// // TODO: Can this function get *conversion_table as an arg
// //       so the return doesn't need to make a copy of it constantly?
// const t_conversion_function	*get_conversion_table(void)
// {
// 	const static t_conversion_function	conversion_table[] = {
// 	['c'] = get_char,
// 	['s'] = get_string,
// 	['p'] = get_pointer,
// 	['d'] = get_decimal,
// 	['i'] = get_decimal,
// 	['u'] = get_unsigned,
// 	['x'] = get_hex_lower,
// 	['X'] = get_hex_upper,
// 	['%'] = get_percent,
// 	};

// 	return (conversion_table);
// }

// // TODO: Would making conversion_table here a static
// //       prevent calling get_conversion_table() a second time or help somehow?
// int	print_argument(const char **format, t_options *options)
// {
// 	char						conversion_type;
// 	const t_conversion_function	*conversion_table = get_conversion_table();
// 	char						*conversion_str;
// 	int							total_width;

// 	conversion_type = **format;
// 	if (ft_strchr(CONVERSION_TYPES, conversion_type) != NULL)
// 	{
// 		conversion_str = conversion_table[conversion_type](format, options);
// 		total_width = ft_max(ft_strlen(conversion_str), options->field_width);
// 		print_with_padding(conversion_str, options, total_width);
// 		return (total_width);
// 	}
// 	else
// 	{

// 	}
// }

// void	fix_priorities(t_options *options)
// {
// 	if (options->flags.zero_fill && options->precision >= 0)
// 	{
// 		options->flags.zero_fill = false;
// 	}
// }

// void	parse_precision(t_options *options, const char **format)
// {

// }

// void	parse_field_width(t_options *options, const char **format)
// {

// }

void	parse_flags(t_options *options, const char **format)
{
	while (**format != '\0' && ft_strchr(FLAGS, **format) != NULL)
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

// TODO: Switch the arguments format and options around
void	fill_options(const char **format, t_options *options)
{
	initialize_options(options);
	parse_flags(options, format);
	// parse_field_width(options, format);
	// parse_precision(options, format);
	// fix_priorities(options);
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
			format++;
			fill_options(&format, &options);
			// chars_printed += print_argument(&format, &options);
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
