/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_ft_printf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 14:57:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	pft_print_options(t_options *options)
{
	if (pft_putstr(options->parts.left_pad, &options->len) != OK)
		return (ERROR);
	if (pft_putstr(options->parts.prefix, &options->len) != OK)
		return (ERROR);
	if (pft_putstr(options->parts.precision_or_zero_pad,
			&options->len) != OK)
		return (ERROR);
	if (options->type == 'c')
	{
		if (pft_putchar(options->parts.base_str[0], &options->len) != OK)
			return (ERROR);
	}
	else if (pft_putstr(options->parts.base_str, &options->len) != OK)
		return (ERROR);
	if (pft_putstr(options->parts.right_pad, &options->len) != OK)
		return (ERROR);
	return (OK);
}

STATIC t_status	pft_printf_loop(char *format, char **non_format_start,
									t_options *options, va_list arg_ptr)
{
	while (*format != '\0')
	{
		pft_initialize_options(options);
		format = ft_strchr(format, '%');
		if (format == NULL)
			break ;
		if (pft_put_substr(*non_format_start, format, &options->len) != OK)
			return (ERROR);
		format++;
		pft_parse_format(&format, options);
		if (pft_parse_argument(options, arg_ptr) != OK)
			return (pft_free_parts(&options->parts));
		if (pft_fill_parts(options) != OK)
			return (pft_free_parts(&options->parts));
		if (pft_print_options(options) != OK)
			return (pft_free_parts(&options->parts));
		pft_free_parts(&options->parts);
		format++;
		*non_format_start = format;
	}
	return (OK);
}

/**
 * @brief This is a recreation of printf() from libc.
 * It doesn’t implement the buffer management of the original printf().
 * It handles the following conversions: "cspdiuxX%" .
 * It handles any combination of the following flags: "-0.# +"
 * and the minimum field width.
 *
 * @param format See "man 3 printf".
 *
 * @return If successful, returns the number of characters printed
 * (excluding the null terminator).
 * If an output error is encountered, a negative value is returned.
 */
t_i32	ft_printf(const char *format, ...)
{
	t_options	options;
	va_list		arg_ptr;
	char		*non_format_start;

	options.len = 0;
	non_format_start = (char *)format;
	va_start(arg_ptr, format);
	if (pft_printf_loop((char *)format, &non_format_start, &options, arg_ptr)
		!= OK)
		return (-1);
	if (pft_putstr(non_format_start, &options.len) != OK)
		return (-1);
	va_end(arg_ptr);
	return ((t_i32)options.len);
}
