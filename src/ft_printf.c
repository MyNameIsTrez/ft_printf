/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/04 16:58:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_success	print_options(t_options *options)
{
	if (pft_putstr(options->parts.left_pad, &options->len) < 0)
		return (ERROR);
	if (pft_putstr(options->parts.prefix, &options->len) < 0)
		return (ERROR);
	if (pft_putstr(options->parts.precision_or_zero_pad, &options->len) < 0)
		return (ERROR);
	if (options->type == 'c')
	{
		if (pft_putchr(options->parts.base_str[0], &options->len) < 0)
			return (ERROR);
	}
	else if (pft_putstr(options->parts.base_str, &options->len) < 0)
		return (ERROR);
	if (pft_putstr(options->parts.right_pad, &options->len) < 0)
		return (ERROR);
	return (SUCCESS);
}

STATIC void	ft_printf_routine(char *format, char **non_format_start,
									t_options *options, va_list arg_ptr)
{
	// pft_initialize_options(options);
	while (*format != '\0')
	{
		pft_initialize_options(options);
		format = ft_strchr(format, '%');
		if (format == NULL)
			break ;
		if (pft_put_substr(*non_format_start, format, &options->len) < 0)
			return;
		format++;
		pft_parse_format(&format, options);
		if (ft_error(pft_parse_argument(options, arg_ptr)))
			return (pft_free_parts(&options->parts));
		if (ft_error(pft_fill_parts(options)))
			return (pft_free_parts(&options->parts));
		if (ft_error(print_options(options)))
			return (pft_free_parts(&options->parts));
		pft_free_parts(&options->parts);
		format++;
		*non_format_start = format;
	}
	// TODO: This is also reached with the break above, is that wanted?
	pft_putstr(*non_format_start, &options->len);
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
int	ft_printf(const char *format, ...)
{
	t_options	options;
	va_list		arg_ptr;
	char		*non_format_start;

	options.len = 0;
	non_format_start = (char *)format;
	va_start(arg_ptr, format);
	// TODO: Should this really be passing &non_format_start instead of non_format_string?
	ft_printf_routine((char *)format, &non_format_start, &options, arg_ptr);
	va_end(arg_ptr);
	return ((int)options.len);
}
