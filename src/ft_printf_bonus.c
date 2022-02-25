/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 16:40:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDOUT_FILENO
#include <stdlib.h> // free

////////////////////////////////////////////////////////////////////////////////

enum e_parts_indices
{
	LEFT_PAD,
	PREFIX,
	PRECISION_OR_ZERO_PAD,
	BASE_STR,
	RIGHT_PAD,
	PARTS_LEN
};

void	set_precision_str(char *parts[PARTS_LEN], t_conversion *conversion)
{
	size_t	base_len;
	size_t	precision_len;

	if (ft_strchr(PRECISION_TYPES, conversion->options.type) != NULL)
	{
		base_len = ft_strlen(parts[BASE_STR]);
		if (conversion->options.precision > (ssize_t)base_len)
		{
			precision_len = (size_t)conversion->options.precision - base_len;
			parts[PRECISION_OR_ZERO_PAD] = ft_stralloc(precision_len);
			ft_memset(parts[PRECISION_OR_ZERO_PAD], '0', precision_len);
		}
	}
}

void	set_zero_pad(char *parts[PARTS_LEN], t_conversion *conversion)
{
	size_t	len;
	size_t	pad_len;

	if (ft_strchr(ZERO_PAD_TYPES, conversion->options.type) != NULL)
	{
		len = ft_strlen(parts[PREFIX]) + ft_strlen(parts[BASE_STR]);
		if (conversion->options.field_width > len)
		{
			pad_len = conversion->options.field_width - len;
			parts[PRECISION_OR_ZERO_PAD] = ft_stralloc(pad_len);
			ft_memset(parts[PRECISION_OR_ZERO_PAD], '0', pad_len);
		}
	}
}

void	set_left_right_pad(char *parts[PARTS_LEN], t_conversion *conversion,
							char *pad)
{
	if (conversion->options.flags.zero_fill)
	{
		parts[LEFT_PAD] = ft_strdup("");
		parts[RIGHT_PAD] = ft_strdup("");
	}
	else if (conversion->options.flags.pad_right)
	{
		parts[LEFT_PAD] = ft_strdup("");
		parts[RIGHT_PAD] = pad;
	}
	else
	{
		parts[LEFT_PAD] = pad;
		parts[RIGHT_PAD] = ft_strdup("");
	}
}

void	set_space_pad(char *parts[PARTS_LEN], t_conversion *conversion)
{
	char	*pad;
	size_t	len;
	size_t	pad_len;

	pad = NULL;
	if (!conversion->options.flags.zero_fill)
	{
		len = ft_strlen(parts[PREFIX]) + ft_strlen(parts[PRECISION_OR_ZERO_PAD])
			+ ft_strlen(parts[BASE_STR]);
		if (conversion->options.type == 'c' && parts[BASE_STR][0] == '\0')
			len++;
		if (conversion->options.field_width > len)
		{
			pad_len = conversion->options.field_width - len;
			pad = ft_stralloc(pad_len);
			ft_memset(pad, ' ', pad_len);
		}
	}
	set_left_right_pad(parts, conversion, pad);
}

int	print_conversion(t_conversion *conversion)
{
	char	*parts[PARTS_LEN];
	int		len;

	parts[PREFIX] = conversion->prefix;
	parts[BASE_STR] = conversion->base_str;
	parts[PRECISION_OR_ZERO_PAD] = NULL;
	if (conversion->options.precision >= 0)
		set_precision_str(parts, conversion);
	else if (conversion->options.flags.zero_fill)
		set_zero_pad(parts, conversion);
	if (parts[PRECISION_OR_ZERO_PAD] == NULL)
		parts[PRECISION_OR_ZERO_PAD] = ft_strdup("");
	set_space_pad(parts, conversion);
	len = (int)ft_putstr(parts[LEFT_PAD]);
	len += (int)ft_putstr(parts[PREFIX]);
	len += (int)ft_putstr(parts[PRECISION_OR_ZERO_PAD]);
	if (conversion->options.type == 'c')
		len += (int)ft_putchar_fd(parts[BASE_STR][0], STDOUT_FILENO);
	else
		len += (int)ft_putstr(parts[BASE_STR]);
	len += (int)ft_putstr(parts[RIGHT_PAD]);
	free(parts[LEFT_PAD]);
	free(parts[PREFIX]);
	free(parts[PRECISION_OR_ZERO_PAD]);
	free(parts[BASE_STR]);
	free(parts[RIGHT_PAD]);
	return (len);
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

// TODO: Would making conversion_table here a static
//       prevent calling get_conversion_table() a second time or help somehow?
void	parse_argument(t_conversion *conversion, va_list arg_ptr)
{
	const t_conversion_function	*conversion_table = get_conversion_table();

	conversion_table[conversion->options.type](arg_ptr, conversion);
}

void	fix_priorities(t_options *options)
{
	if (options->precision >= 0 && options->type == '%')
		options->precision = -1;
	if (options->flags.zero_fill && options->precision >= 0)
		options->flags.zero_fill = false;
	if (options->flags.zero_fill && options->flags.pad_right)
		options->flags.zero_fill = false;
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
		while (ft_isdigit(**format))
			(*format)++;
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
			conversion->options.flags.pad_right = true;
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
	flags->pad_right = false;
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
}

void	initialize_state(t_conversion *conversion)
{
	initialize_options(&conversion->options);
	conversion->base_str = NULL;
	conversion->prefix = NULL;
}

// TODO: Switch the arguments format and conversion around
void	parse_format(const char **format, t_conversion *conversion)
{
	initialize_state(conversion);
	parse_flags(format, conversion);
	parse_field_width(format, conversion);
	parse_precision(format, conversion);
	parse_conversion_type(format, conversion);
	fix_priorities(&conversion->options);
}

int	ft_printf(const char *format, ...)
{
	t_conversion	conversion;
	int				chars_printed;
	va_list			arg_ptr;
	const char		*non_format_start = format;

	chars_printed = 0;
	va_start(arg_ptr, format);
	while (*format != '\0')
	{
		format = ft_strchr(format, '%');
		if (format == NULL)
			break ;
		chars_printed += (int)write(STDOUT_FILENO, non_format_start, (size_t)(format - non_format_start));
		format++;
		parse_format(&format, &conversion);
		parse_argument(&conversion, arg_ptr);
		chars_printed += print_conversion(&conversion);
		format++;
		non_format_start = format;
	}
	va_end(arg_ptr);
	chars_printed += (int)ft_putstr_fd((char *)non_format_start, STDOUT_FILENO);
	return (chars_printed);
}
