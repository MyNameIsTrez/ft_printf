/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/28 14:47:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDOUT_FILENO
#include <stdlib.h> // free

////////////////////////////////////////////////////////////////////////////////

void	free_parts(t_parts *parts)
{
	free(parts->left_pad);
	free(parts->prefix);
	free(parts->precision_or_zero_pad);
	free(parts->base_str);
	free(parts->right_pad);
}

void	set_left_right_pad(t_options *options, char *pad)
{
	if (options->flags.zero_fill)
	{
		free(pad);
		options->parts.left_pad = ft_empty_str();
		options->parts.right_pad = ft_empty_str();
	}
	else if (options->flags.pad_right)
	{
		options->parts.left_pad = ft_empty_str();
		options->parts.right_pad = pad;
	}
	else
	{
		options->parts.left_pad = pad;
		options->parts.right_pad = ft_empty_str();
	}
}

void	set_space_pad(t_options *options)
{
	const char	*pad = NULL;
	size_t		len;
	size_t		pad_len;

	if (!options->flags.zero_fill)
	{
		len = ft_strlen(options->parts.prefix) + ft_strlen(options->parts.precision_or_zero_pad)
			+ ft_strlen(options->parts.base_str);
		if (options->type == 'c' && ft_str_eq(options->parts.base_str, ""))
			len++;
		if (options->field_width > len)
		{
			pad_len = options->field_width - len;
			pad = ft_chr_repeat(' ', pad_len);
		}
	}
	if (pad == NULL)
		pad = ft_empty_str();
	set_left_right_pad(options, (char *)pad);
}

void	set_zero_pad(t_options *options)
{
	size_t	len;
	size_t	pad_len;

	if (ft_strchr(ZERO_PAD_TYPES, options->type) != NULL)
	{
		len = ft_strlen(options->parts.prefix) + ft_strlen(options->parts.base_str);
		if (options->field_width > len)
		{
			pad_len = options->field_width - len;
			options->parts.precision_or_zero_pad = ft_chr_repeat('0', pad_len);
		}
	}
}

void	set_precision_str(t_options *options)
{
	size_t	base_len;
	size_t	precision_len;

	if (ft_strchr(PRECISION_TYPES, options->type) != NULL)
	{
		base_len = ft_strlen(options->parts.base_str);
		if (options->precision > (ssize_t)base_len)
		{
			precision_len = (size_t)options->precision - base_len;
			options->parts.precision_or_zero_pad = ft_chr_repeat('0', precision_len);
		}
	}
}

ssize_t	pft_putstr(char *str, size_t *acc)
{
	ssize_t	a;

	a = ft_putstr(str);
	if (a < 0)
		return (a);
	if (acc != NULL)
		(*acc) += (size_t)a;
	return (a);
}

ssize_t	pft_putchr(char chr, size_t *acc)
{
	ssize_t	a;

	a = ft_putchar(chr);
	if (a < 0)
		return (a);
	if (acc != NULL)
		(*acc) += (size_t)a;
	return (a);
}

void	fill_parts(t_options *options)
{
	if (options->precision >= 0)
		set_precision_str(options);
	else if (options->flags.zero_fill)
		set_zero_pad(options);
	if (options->parts.precision_or_zero_pad == NULL)
		options->parts.precision_or_zero_pad = ft_empty_str();
	set_space_pad(options);
}

ssize_t	print_options(t_options *options)
{
	if (pft_putstr(options->parts.left_pad, &options->len) < 0)
		return (-1);
	if (pft_putstr(options->parts.prefix, &options->len) < 0)
		return (-1);
	if (pft_putstr(options->parts.precision_or_zero_pad, &options->len) < 0)
		return (-1);
	if (options->type == 'c')
	{
		if (pft_putchr(options->parts.base_str[0], &options->len) < 0)
			return (-1);
	}
	else if (pft_putstr(options->parts.base_str, &options->len) < 0)
		return (-1);
	if (pft_putstr(options->parts.right_pad, &options->len) < 0)
		return (-1);
	return (0);
}

// TODO: After changing get_options_table so it returns the result of accessing the table, update this function.
void	parse_argument(t_options *options, va_list arg_ptr)
{
	const static t_base_and_prefix_fn	options_table[] = {
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

	options_table[options->type](arg_ptr, options);
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

void	parse_options_type(const char **format, t_options *options)
{
	options->type = (unsigned char)**format;
}

void	parse_precision(const char **format, t_options *options)
{
	if (**format == '.')
	{
		options->precision = 0;
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		options->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	parse_field_width(const char **format, t_options *options)
{
	options->field_width = (size_t)ft_atoi(*format);
	if (options->field_width != 0)
		(*format) += ft_get_digit_count((intmax_t)options->field_width);
}

void	parse_flags(const char **format, t_options *options)
{
	while (**format != '\0' && ft_strchr(FLAGS, **format) != NULL)
	{
		if (**format == '#')
			options->flags.alternate = true;
		else if (**format == '0')
			options->flags.zero_fill = true;
		else if (**format == '-')
			options->flags.pad_right = true;
		else if (**format == ' ')
			options->flags.plus_space = true;
		else if (**format == '+')
			options->flags.plus_sign = true;
		(*format)++;
	}
}

void	initialize_parts(t_parts *parts)
{
	parts->left_pad = NULL;
	parts->prefix = NULL;
	parts->precision_or_zero_pad = NULL;
	parts->base_str = NULL;
	parts->right_pad = NULL;
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
	initialize_parts(&options->parts);
	options->field_width = 0;
	options->precision = -1;
	options->type = '\0';
	options->len = 0;
}

// TODO: Switch the arguments format and options around
void	parse_format(const char **format, t_options *options)
{
	initialize_options(options);
	parse_flags(format, options);
	parse_field_width(format, options);
	parse_precision(format, options);
	parse_options_type(format, options);
	fix_priorities(options);
}

int	ft_printf(const char *format, ...)
{
	t_options	options;
	int			chrs_printed;
	va_list		arg_ptr;
	const char	*non_format_start = format;
	size_t		bytes_written; // TODO: Better name.

	chrs_printed = 0;
	va_start(arg_ptr, format);
	while (*format != '\0')
	{
		format = ft_strchr(format, '%');
		if (format == NULL)
			break ;
		bytes_written = (size_t)(format - non_format_start);
		if (write(STDOUT_FILENO, non_format_start, bytes_written) == -1)
			return (-1);
		chrs_printed += bytes_written;
		format++;
		parse_format(&format, &options);
		parse_argument(&options, arg_ptr);
		fill_parts(&options);
		if (print_options(&options) == -1)
			return (-1);
		chrs_printed += options.len;
		free_parts(&options.parts);
		format++;
		non_format_start = format;
	}
	va_end(arg_ptr);
	// TODO: Check if ft_putstr_fd returns -1
	chrs_printed += (int)ft_putstr_fd((char *)non_format_start, STDOUT_FILENO);
	return (chrs_printed);
}
