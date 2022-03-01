/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/01 17:30:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDOUT_FILENO
#include <stdlib.h> // free

////////////////////////////////////////////////////////////////////////////////

STATIC ssize_t	print_options(t_options *options)
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
	return ((ssize_t)options->len);
}

STATIC ssize_t	ft_printf_routine(char *format, t_options *options, va_list arg_ptr)
{
	size_t	chrs_printed;
	char	*non_format_start;

	chrs_printed = 0;
	non_format_start = format;
	while (*format != '\0')
	{
		format = ft_strchr(format, '%');
		if (format == NULL)
			break ;
		if (pft_put_substr(non_format_start, format, &chrs_printed) < 0)
			return (-1);
		format++;
		parse_format((const char **)&format, options);
		parse_argument(options, arg_ptr);
		fill_parts(options);
		if (accumulate(print_options(options), &chrs_printed) < 0)
			return (-1);
		free_parts(&options->parts);
		format++;
		non_format_start = format;
	}
	if (pft_putstr(non_format_start, (size_t *)&chrs_printed) < 0)
		return (-1);
	return ((ssize_t)chrs_printed);
}

int	ft_printf(const char *format, ...)
{
	t_options	options;
	int			chrs_printed;
	va_list		arg_ptr;

	va_start(arg_ptr, format);
	chrs_printed = (int)ft_printf_routine((char *)format, &options, arg_ptr);
	va_end(arg_ptr);
	return (chrs_printed);
}
