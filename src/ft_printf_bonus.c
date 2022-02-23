/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/23 17:29:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDOUT_FILENO
#include <stdlib.h> // free

////////////////////////////////////////////////////////////////////////////////

void	print_with_padding(char *conversion_str, t_conversion *conversion,
								int total_width)
{
	(void)conversion;
	write(STDOUT_FILENO, conversion_str, (size_t)total_width + 1);
	// (void)conversion_str;
	// write(STDOUT_FILENO, buffer, total_width + 1);
}

void	apply_precision_numbers(t_conversion *conversion)
{
	size_t	zeros_to_add;

	if (conversion->options.precision == 0 && ft_str_eq(conversion->conversion_str, "0"))
	{
		free(conversion->conversion_str);
		conversion->conversion_str = ft_strdup("");
	}
	else if (conversion->options.precision >= 1)
	{
		zeros_to_add = (size_t)conversion->options.precision - ft_strlen(
				conversion->conversion_str);
		if (zeros_to_add > 0)
		{
			// foo = ft_strjoin(ft_str_repeat("0", zeros_to_add),
			//		conversion->conversion_str);
			// free(conversion->conversion_str);
			// conversion->conversion_str = foo;
		}
	}
}

void	apply_precision(t_conversion *conversion)
{
	if (conversion->options.type == 'c')
	{

	}
	else if (conversion->options.type == 'p')
	{

	}
	else if (conversion->options.type == 's')
	{

	}
	else if (ft_strchr(CONVERSION_NUMBER_TYPES, conversion->options.type))
	{
		apply_precision_numbers(conversion);
	}
}

// TODO: Can this function get *conversion_table as an arg
//       so the return doesn't need to make a copy of it constantly?
const t_conversion_function	*get_conversion_table(void)
{
	// TODO: Which one should be used?
	// static const t_conversion_function	conversion_table[] = {
	// t_conversion_function static	conversion_table[] = {
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

int	print_conversion(t_conversion *conversion)
{
	// int		total_width;

	// if (ft_strchr(CONVERSION_TYPES, conversion->options.type) != NULL)
	// {
	// 	apply_precision(conversion);
	// 	total_width = ft_max((int)ft_strlen(conversion_str),
	// 			conversion->options.field_width);
	// 	print_with_padding(conversion_str, conversion, total_width);
	// 	return (total_width);
	// }
	// else
	// {
	// 	return (42);
	// }
	(void)conversion;
	return (42);
}

// TODO: Would making conversion_table here a static
//       prevent calling get_conversion_table() a second time or help somehow?
void	parse_argument(t_conversion *conversion, va_list arg_ptr)
{
	const t_conversion_function	*conversion_table = get_conversion_table();

	conversion_table[conversion->options.type](arg_ptr, conversion);
}

void	fix_priorities(t_conversion *conversion)
{
	if (conversion->options.flags.zero_fill && conversion->options.precision >= 0)
	{
		conversion->options.flags.zero_fill = false;
	}
}

void	parse_conversion_type(const char **format, t_conversion *conversion)
{
	conversion->options.type = (unsigned char)**format;
}

void	parse_precision(const char **format, t_conversion *conversion)
{
	if (**format == '.')
	{
		conversion->options.precision = 0;
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		conversion->options.precision = ft_atoi(*format);
		(*format) += ft_get_digit_count(conversion->options.precision);
	}
}

void	parse_field_width(const char **format, t_conversion *conversion)
{
	conversion->options.field_width = (size_t)ft_atoi(*format);
	if (conversion->options.field_width != 0)
		(*format) += ft_get_digit_count((intmax_t)conversion->options.field_width);
}

void	parse_flags(const char **format, t_conversion *conversion)
{
	while (**format != '\0' && ft_strchr(FLAGS, **format) != NULL)
	{
		if (**format == '#')
			conversion->options.flags.alternate = true;
		else if (**format == '0')
			conversion->options.flags.zero_fill = true;
		else if (**format == '-')
			conversion->options.flags.aligned_left = true;
		else if (**format == ' ')
			conversion->options.flags.plus_space = true;
		else if (**format == '+')
			conversion->options.flags.plus_sign = true;
		(*format)++;
	}
}

void	initialize_flags(t_flags *flags)
{
	flags->alternate = false;
	flags->zero_fill = false;
	flags->aligned_left = false;
	flags->plus_space = false;
	flags->plus_sign = false;
}

// precision is -1 by default instead of 0 cause:
// printf("'%d'\n", 0) -> '0' but printf("'%.d'\n", 0) -> ''
void	initialize_options(t_options *options)
{
	initialize_flags(&options->flags);
	options->field_width = 0;
	options->precision = -1;
	options->type = '\0';
	options->negative = false; // TODO: Necessary?
}

void	initialize_state(t_conversion *conversion)
{
	initialize_options(&conversion->options);
	conversion->conversion_str = NULL; // TODO: Necessary?
}

// TODO: Switch the arguments format and conversion around
void	parse_format(const char **format, t_conversion *conversion)
{
	initialize_state(conversion);
	parse_flags(format, conversion);
	parse_field_width(format, conversion);
	parse_precision(format, conversion);
	parse_conversion_type(format, conversion);
	fix_priorities(conversion);
}

int	ft_printf(const char *format, ...)
{
	t_conversion	conversion;
	int				chars_printed;
	va_list			arg_ptr;

	chars_printed = 0;
	va_start(arg_ptr, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			parse_format(&format, &conversion);
			if (conversion.options.type != '%')
			{
				parse_argument(&conversion, arg_ptr);
				// apply_precision(&conversion);
			}
			chars_printed += print_conversion(&conversion);
		}
		format++;
	}
	va_end(arg_ptr);
	return (chars_printed);
}
