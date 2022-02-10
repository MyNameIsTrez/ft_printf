/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/10 11:42:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDOUT_FILENO

////////////////////////////////////////////////////////////////////////////////

void	print_with_padding(char *conversion_str, t_options *options,
								int total_width)
{
	(void)options;
	write(STDOUT_FILENO, conversion_str, (size_t)total_width + 1);
	// (void)conversion_str;
	// write(STDOUT_FILENO, buffer, total_width + 1);
}

// TODO: Can this function get *conversion_table as an arg
//       so the return doesn't need to make a copy of it constantly?
const t_conversion_function	*get_conversion_table(void)
{
	// TODO: Which one should be used?
	// static const t_conversion_function	conversion_table[] = {
	// t_conversion_function static	conversion_table[] = {
	static t_conversion_function	conversion_table[] = {
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

// TODO: Would making conversion_table here a static
//       prevent calling get_conversion_table() a second time or help somehow?
int	print_argument(unsigned char conversion_type, t_options *options,
					va_list arg_ptr)
{
	const t_conversion_function	*conversion_table = get_conversion_table();
	char						*conversion_str;
	int							total_width;

	if (ft_strchr(CONVERSION_TYPES, conversion_type) != NULL)
	{
		conversion_str = conversion_table[conversion_type](arg_ptr);
		total_width = ft_max((int)ft_strlen(conversion_str),
				options->field_width);
		print_with_padding(conversion_str, options, total_width);
		return (total_width);
	}
	else
	{
		return (42);
	}
}

void	fix_priorities(t_options *options)
{
	if (options->flags.zero_fill && options->precision >= 0)
	{
		options->flags.zero_fill = false;
	}
}

void	parse_precision(const char **format, t_options *options)
{
	if (**format == '.')
	{
		options->precision = 0;
		(*format)++;
	}
	if (**format != '\0' && ft_isdigit(**format))
	{
		options->precision = ft_atoi(*format);
	}
}

void	parse_field_width(const char **format, t_options *options)
{
	options->field_width = ft_atoi(*format);
	(*format) += ft_get_digit_count(options->field_width);
}

void	parse_flags(const char **format, t_options *options)
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

// precision is -1 by default instead of 0
// as it signifies using the length of the number/string/etc.
// printf("%d", 0) -> '0' but
// printf("%.d", 0) -> '', printf("%.0d", 0) -> '' and printf("%.1d", 0) -> '0'
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
	parse_flags(format, options);
	parse_field_width(format, options);
	parse_precision(format, options);
	fix_priorities(options);
}

int	ft_printf(const char *format, ...)
{
	t_options		options;
	int				chars_printed;
	va_list			arg_ptr;
	unsigned char	conversion_type;

	chars_printed = 0;
	va_start(arg_ptr, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			fill_options(&format, &options);
			conversion_type = (unsigned char)*format;
			chars_printed += print_argument(conversion_type, &options, arg_ptr);
		}
		format++;
	}
	va_end(arg_ptr);
	return (chars_printed);
}

////////////////////////////////////////////////////////////////////////////////
